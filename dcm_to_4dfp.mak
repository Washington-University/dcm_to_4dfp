#	Makefile for dcm_to_4dfp


PROG	= dcm_to_4dfp
TRX	= ${NILSRC}/TRX
CSRCS	= ${PROG}.c
LSRCS	= pixel_ops.c lst.c dcm.c condition.c \
utility.c ctnthread.c dcmsupport.c \
dcmdict.c dcmcond.c

LOBJS   = ${TRX}/rec.o ${TRX}/Getifh.o ${TRX}/endianio.o


OBJS    = ${CSRCS:.c=.o} ${LSRCS:.c=.o}

# These were used before GNU autotools were added
LONGSIZE	=32
INTSIZE		=32
SHORTSIZE	=16

# These are compatible with GNU autotools
SIZEOF_LONG= 4
SIZEOF_INT= 4
SIZEOF_SHORT= 2

#C_OPTS	= -DDEBUG -DMALLOC_DEBUG -DSHARED_MEMORY \
#C_OPTS	= -g -DDEBUG -DMALLOC_DEBUG -DSHARED_MEMORY \

C_OPTS	= -DDEBUG -DMALLOC_DEBUG  \
	-DSIZEOF_LONG=$(SIZEOF_LONG) -DSIZEOF_SHORT=$(SIZEOF_SHORT) \
	-DSIZEOF_INT=$(SIZEOF_INT) -DHAVE_REGEX_H=1 -DHAVE_REGCOMP=1

CCFLAGS	= -O -I${TRX} -Iinclude -I/usr/include ${C_OPTS}   -lm 

#CCFLAGS	= -O -Iinclude -I/usr/include ${C_OPTS} -lm
#CCFLAGS	= -Iinclude -I/usr/include ${C_OPTS} -lm

CC = cc ${CCFLAGS}

.c.o:
	$(CC) -c $<

${PROG}: ${OBJS} 
	${CC}  -o $@ ${LOBJS} ${OBJS}

.INIT: 
	@echo "RELEASE FOLDER = ${RELEASE}"
	@echo "NILSRC FOLDER = ${NILSRC}"


#clean:
#        rm ${OBJS} ${PROG}

#checkout:
#        co ${CSRCS} ${FSRCS}

#checkin:
#        ci ${CSRCS} ${FSRCS}

release: ${PROG}
	chgrp program ${PROG}
	chmod 751 ${PROG}
	/bin/mv ${PROG} ${RELEASE}
