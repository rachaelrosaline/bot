#include <stdio.h>
#include <string.h>

#include "config.h"

char *post(char *t) {
    char p[8192];
    snprintf(
        p, 8192,
        "%sHost: %s\r\n%s %s\r\n%s%s %lu%s%s%s\r\n",
        "POST /api/v1/statuses HTTP/1.1\r\n",
        HOST,
        "Authorization: Bearer", KEY,
        "Content-Type: application/x-www-form-urlencoded\r\n",
        "Content-Length:", strnlen(t, 5000) + 7,
        "\r\n\r\n",
        "status=", t
    );
    char *ptr = p;
    return ptr;
}
