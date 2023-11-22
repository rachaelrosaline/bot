#include <openssl/bio.h>
#include <openssl/ssl.h>

void conn(BIO *o, SSL_CTX *c, char *t);
void bot(BIO *o, SSL *s, char *t);
char *post(char *t);
