#include <stdio.h>
#include <stdlib.h>
#include <json-glib-1.0/json-glib/json-glib.h>

#ifdef __linux__
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#endif

#define _PATH

void interp_mouseMove(int x, int y);

int interp(char *filepath);

int interp_execute_acoes(void);
