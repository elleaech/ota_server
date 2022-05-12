#ifndef __OTA_DATA_H__
#define __OTA_DATA_H__

#include <inttypes.h>

typedef struct
{
    const char *url;
    const char *host;
    int16_t port;
} HTTP;

typedef struct
{
    const char *username;
    const char *password;
} Authentication;

typedef struct
{
    const char *cert_pem;
    size_t cert_len;
} SSL;

#endif /* #ifndef __OTA_DATA_H__ */
