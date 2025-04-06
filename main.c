// #include <X11/Xatom.h>
// #include <X11/Xlib.h>
// #include <X11/Xutil.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
//
// int main() {
//   XEvent event;
//   Display *display = XOpenDisplay(NULL);
//   if (display == NULL) {
//     fprintf(stderr, "Cannot open display\n");
//     exit(1);
//   }
//   int screen = DefaultScreen(display);
//
//   int screen_width = DisplayWidth(display, screen);
//   int screen_height = DisplayHeight(display, screen);
//
//   int window_width = 300;
//   int window_height = 200;
//
//   int x = (screen_width - window_width) / 2;
//   int y = (screen_height - window_height) / 2;
//
//   Window window = XCreateSimpleWindow(
//       display, RootWindow(display, screen), x, y, window_width, window_height,
//       1, BlackPixel(display, screen), WhitePixel(display, screen));
//   XStoreName(display, window, "cppgun");
//
//   // // Make the window float in i3
//   // Atom window_type = XInternAtom(display, "_NET_WM_WINDOW_TYPE", False);
//   // Atom dialog = XInternAtom(display, "_NET_WM_WINDOW_TYPE_DIALOG", False);
//   // XChangeProperty(display, window, window_type, XA_ATOM, 32, PropModeReplace,
//   //                 (unsigned char *)&dialog, 1);
//   //
//   // // Set only size hints, not position hints
//   // XSizeHints hints;
//   // hints.flags = PPosition | PSize; // Only size hints, not position
//   // hints.width = window_width;
//   // hints.height = window_height;
//   // XSetWMNormalHints(display, window, &hints);
//
//   XSelectInput(display, window, ExposureMask | KeyPressMask);
//   XMapWindow(display, window);
//
//   while (1) {
//     XNextEvent(display, &event);
//     if (event.type == KeyPress)
//       break;
//   }
//
//   XCloseDisplay(display);
//   return 0;
// }

#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  XEvent event;

  Display *display = XOpenDisplay(NULL);

  if (display == NULL) {
    fprintf(stderr, "Cannot open display\n");
    exit(1);
  }

  int screen = DefaultScreen(display);

  Window window = XCreateSimpleWindow(
      display, RootWindow(display, screen), 10, 10, 300, 200, 1,
      BlackPixel(display, screen), WhitePixel(display, screen));

  XStoreName(display, window, "cppgun");
  XSelectInput(display, window, ExposureMask | KeyPressMask);
  XMapWindow(display, window);

  while (1) {
    XNextEvent(display, &event);

    if (event.type == KeyPress)
      break;
  }

  XCloseDisplay(display);

  return 0;
}

