#ifndef __OTA_H__
#define __OTA_H__

#include <stdlib.h>
#include <string.h>

#include "ota_data.h"

#define OTA_OK 0
#define OTA_ERROR -1

int32_t lb_ota_update_firmware_perform(HTTP *http_data,
                                       Authentication *auth_data,
                                       SSL *ssl_data);

void lb_ota_update_firmware_finish(int32_t rc);

#endif /* #ifndef __OTA_H__ */
