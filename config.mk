PATH = /api/v1/timelines/public
NAME = rosaline.systems

LIBS = -lssl -lcrypto

CPPFLAGS = ${LIBS}
LDFLAGS = -O2

CFLAGS = ${CPPFLAGS} ${LDFLAGS}

CC = cc
