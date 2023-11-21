#include <openssl/bio.h>
#include <openssl/ssl.h>

#include "config.h"

void bot(BIO *errout, SSL *s) {
    if(SSL_connect(s) != 1) {
        BIO_printf(errout, "SSL_connect failed\n");
        return;
    }
    SSL_write(s, GETREQ, sizeof(GETREQ));
    char out[16384];
    SSL_read(s, out, 16384);
    printf("%s\n", out);
}
