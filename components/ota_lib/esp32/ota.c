#include "ota_log.h"
#include "ota.h"

#include <esp_err.h>
#include <esp_system.h>
#include <esp_https_ota.h>
#include <esp_http_client.h>
#include <esp_ota_ops.h>

/* ---------------------------------------------------------------------- */
static int32_t
map_return_(int32_t rc)
{
    if (ESP_OK == rc)
    {
        rc = OTA_OK;
    }
    else
    {
        rc = OTA_ERROR;
    }

    return rc;
}

/* ---------------------------------------------------------------------- */
static void
set_updation_params_(esp_http_client_config_t *ota_config,
                     HTTP *http_data,
                     Authentication *auth_data,
                     SSL *ssl_data)
{
    if (NULL != ota_config && NULL != http_data)
    {
        memset(ota_config, 0x00, sizeof(esp_http_client_config_t));

        ota_config->url = http_data->url;
        ota_config->host = http_data->host;
        ota_config->port = http_data->port;

        if (NULL != auth_data)
        {
            ota_config->username = auth_data->username;
            ota_config->password = auth_data->password;
        }

        if (NULL != ssl_data)
        {
            ota_config->cert_pem = ssl_data->cert_pem;
            ota_config->cert_len = ssl_data->cert_len;
        }
    }
}

/* ---------------------------------------------------------------------- */
static void
log_running_app_version(void)
{
    const esp_partition_t *running = esp_ota_get_running_partition();
    esp_app_desc_t running_app_info;

    if (ESP_OK == esp_ota_get_partition_description(running, &running_app_info))
    {
        lb_ota_log_info("[%s]\tRunning app version: %s\n", __FUNCTION__, running_app_info.version);
    }
}

/* ---------------------------------------------------------------------- */
int32_t
lb_ota_update_firmware_perform(HTTP *http_data,
                               Authentication *auth_data,
                               SSL *ssl_data)
{
    esp_err_t err = ESP_OK;

    esp_http_client_config_t ota_config;

    lb_ota_log_info("[%s]\tStarting OTA\n", __FUNCTION__);
    log_running_app_version();

    if (NULL != http_data)
    {
        set_updation_params_(&ota_config, http_data, auth_data, ssl_data);

        lb_ota_log_info("[%s]\tAttempting to download update from %s\n", __FUNCTION__, http_data->url);
        err = esp_https_ota(&ota_config);
    }
    else
    {
        err = ESP_FAIL;
    }

    lb_ota_log_info("[%s]\terr=[%d]\n", __FUNCTION__, err);

    err = map_return_(err);
    lb_ota_log_info("[%s]\trc=[%d]\n", __FUNCTION__, err);

    return err;
}

/* ---------------------------------------------------------------------- */
void lb_ota_update_firmware_finish(int32_t rc)
{
    if (ESP_OK == rc)
    {
        lb_ota_log_info("[%s]\tREBOOTING ESP-32...\n", __FUNCTION__);
        esp_restart();
    }
    else
    {
        lb_ota_log_info("[%s]\tOTA PERFORM FAILED! KEEPING ESP-32 ALIVE...\n", __FUNCTION__);
    }
}
