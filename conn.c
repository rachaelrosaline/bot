#include <err.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>

#include <sys/socket.h>

#include <openssl/bio.h>
#include <openssl/ssl.h>

#include "config.h"
#include "util.h"

void conn(BIO *o, SSL_CTX *c) {
    SSL *ssl = SSL_new(c);

    struct hostent *h = gethostbyname(HOST);

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in n;
    n.sin_family=AF_INET;
    n.sin_port=htons(443);
    n.sin_addr.s_addr = *(long*)(h->h_addr);

    memset(&(n.sin_zero), '\0', 8);

    if(connect(
        sock, (struct sockaddr *) &n, sizeof(struct sockaddr)
    ) == -1) {
        err(errno, "connect");
        SSL_free(ssl);
        return;
    }

    SSL_set_fd(ssl, sock);

    bot(o, ssl);

    SSL_free(ssl);
    close(sock);
}
