#include "ota_log.h"
#include "ota.h"

#include <inttypes.h>
#include <string.h>

/* ---------------------------------------------------------------------- */
void
do_ota(char *firmware_filepath, int32_t file_content_len)
{
    OTA ota_data;
    memset(&ota_data, 0x00, sizeof(OTA));
    ota_data.firmware_filepath = firmware_filepath;
    ota_data.firmware_content_len = file_content_len;

    lb_ota_update_firmware_perform(&ota_data);
    lb_ota_update_firmware_finish(&ota_data);
}