.include "config.mk"

SRC = bot.c conn.c main.c post.c

all: bot

bot: config.h ${SRC}
	${CC} ${CFLAGS} ${SRC} -o $@

config.h: config.h.in
	sed -e s/AUTHKEY/${KEY}/g -e s/NAME/${NAME}/g config.h.in > config.h

clean:
	rm config.h bot
