.include "config.mk"

SRC = bot.c conn.c main.c

all: bot

bot: config.h
	${CC} ${CFLAGS} ${SRC} -o $@

config.h: config.h.in
	sed -e s,PATH,${PATH},g -e s/NAME/${NAME}/g config.h.in > config.h

clean:
	rm config.h bot
