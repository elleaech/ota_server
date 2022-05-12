#include "ota_log.h"

#include <esp_log.h>

void lb_ota_log_info(const char *format, ...)
{
    va_list argptr;
    va_start(argptr, format);

    esp_log_writev(ESP_LOG_INFO, "", format, argptr);

    va_end(argptr);
}
