#include "config.h"
#include "util.h"

void bot(BIO *o, SSL *s, char* t) {
    if(SSL_connect(s) != 1) {
        BIO_printf(o, "SSL_connect failed\n");
        return;
    }
    char *p = post(t);
    SSL_write(s, p, strnlen(p, 8192));
    char r[16384];
    SSL_read(s, r, 16384);
    BIO_printf(o, "%s\n", r);
}
