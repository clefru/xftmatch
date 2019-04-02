// Copyright: Clemens Fruhwirth <clemens@endorphin.org>
// License: GPL, http://www.gnu.org/licenses/gpl.html

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <X11/Xft/Xft.h>

#define BUF_LEN 10000

int main(int argc, char * argv[]) {
    // Sorry for the static buffer length. XFtNameUnparse just has a
    // crappy interface, and I didn't want to use FcNameUnparse
    // directly.

    char *buf;

    Display *dpy;
    XftResult res;
    XftPattern *pattern;
    XftPattern *matchedPattern;

    if(!(buf = malloc(BUF_LEN))) {
	perror("name buffer alloc failed");
	exit(EXIT_FAILURE);
    }

    if((dpy = XOpenDisplay(NULL)) == NULL) {
	fprintf(stderr, "Couldn't connect to X server\n");
	exit(EXIT_FAILURE);
    }
    if(argc != 2) {
	printf("Usage: %s <font-matching-spec>\n", argv[0]);
	exit(-1);
    }

    pattern = XftNameParse(argv[1]);
    matchedPattern = XftFontMatch(dpy, DefaultScreen(dpy), pattern, &res);
    if(XftNameUnparse (matchedPattern, buf, BUF_LEN))
	printf("%s\n", buf);
    else
	printf("XftNameUnparse failed. Buffer too small? See code.\n");
}
