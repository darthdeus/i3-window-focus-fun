#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
    return 1;
  }
  SDL_version compiled;
  SDL_version linked;

  SDL_VERSION(&compiled);
  printf("Compiled against SDL version %d.%d.%d\n", compiled.major,
         compiled.minor, compiled.patch);

  SDL_GetVersion(&linked);
  printf("Linked against SDL version %d.%d.%d\n", linked.major, linked.minor,
         linked.patch);

  // SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0");
  // SDL_SetHint(SDL_HINT_VIDEO_X11_FORCE_EGL, "0");
  // SDL_SetHint(SDL_HINT_VIDEO_X11_WINDOW_VISUALID, "0");

  // Create a window
  SDL_Window *window =
      SDL_CreateWindow("cppgun",               // Window title
                       SDL_WINDOWPOS_CENTERED, // x position, centered
                       SDL_WINDOWPOS_CENTERED, // y position, centered
                       300,                    // width
                       200,                    // height
                       SDL_WINDOW_SHOWN        // flags
      );

  if (window == NULL) {
    fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  // Create a renderer for the window
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL) {
    fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  // Clear the window to white
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);

  // Main loop
  bool quit = false;
  SDL_Event event;

  while (!quit) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        quit = true;
      } else if (event.type == SDL_KEYDOWN) {
        quit = true;
      }
    }

    // Add a short delay to avoid consuming 100% CPU
    SDL_Delay(10);
  }

  // Clean up
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
