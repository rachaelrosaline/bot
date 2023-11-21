#include <stdio.h>

#include <openssl/bio.h>
#include <openssl/ssl.h>

#include "util.h"

int main() {
    BIO *o = BIO_new_fp(stdout, BIO_NOCLOSE);
    SSL_CTX *c;
    if((c = SSL_CTX_new(TLSv1_2_client_method())) == NULL) {
        BIO_printf(o, "SSL_CTX_new error\n");
        return 1;
    }

    conn(o, c);

    SSL_CTX_free(c);
}
