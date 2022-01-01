#include <buttons.hpp>
#include <ctime>
#include <drawing.hpp>
#include <gfx.hpp>
#include <iostream>
#include <system.hpp>

#define SCREEN_XSIZE 640
#define SCREEN_YSIZE 480
#define NUM_OF_BUTTONS 21

namespace rnc {

void game_cycle(System& game, Button_Parent** buttons) {
  struct timespec tw = {0, 25000000};
  struct timespec tr;
  nanosleep(&tw, &tr);
  gfx_open(SCREEN_XSIZE, SCREEN_YSIZE, "RNC 2.0.0");
  char alarm;
  int current_action = 0;
  do {
    game.check_balance();
    const int previous = current_action;
    current_action = gfx_event_waiting();
    game.draw_interface();
    for (int i = 0; i < NUM_OF_BUTTONS; i++) {
      buttons[i]->drawing(game);
    }
    if ((current_action == 1) && (previous == 0)) {
      alarm = gfx_wait();
      if (alarm == 1) {
        for (int i = 0; i < NUM_OF_BUTTONS; i++) {
          buttons[i]->onclick(game);
        }
      }
    }
    nanosleep(&tw, &tr);
  } while (game.iseog() != 1);
}

}  // namespace rnc
