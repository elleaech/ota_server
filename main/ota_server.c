#include "ota_log.h"
#include "ota.h"

#include <inttypes.h>
#include <string.h>

/* ---------------------------------------------------------------------- */
void
ota_server(void)
{
    OTA ota_data;
    memset(&ota_data, 0x00, sizeof(OTA));

    lb_ota_update_firmware_perform(&ota_data);
    lb_ota_update_firmware_finish(&ota_data);
}