# Copyright: Clemens Fruhwirth <clemens@endorphin.org>
# License: GPL, http://www.gnu.org/licenses/gpl.html

LDFLAGS=-lX11 -lXft
CFLAGS=-I/usr/include/X11/Xft -I/usr/include/freetype2

all: xftmatch

install: xftmatch
	mkdir -p ${DESTDIR}/bin
	install xftmatch ${DESTDIR}/bin
