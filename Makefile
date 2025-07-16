



win:
	CC=cl
	CFLAGS=	
	ifdef STATIC_LIB
		TARGET=static_event.lib
	else
		TARGET=event.dll
	endif


linux:
	CC=gcc
	ifdef STATIC_LIB
		TARGET=libevent.a
	else
		TARGET=libevent.so

unix:
	CC=cc
	CFLAGS=
