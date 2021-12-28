#include <iostream>
#include <time.h>
#include <drawing.h>
#include <gfx.h>
#include <system.h>
#include <buttons.h>
#define SCREEN_XSIZE 640
#define SCREEN_YSIZE 480

void screen_show(System_props* game, Button_Parent** buttons)
{
   struct timespec tw = {0, 25000000};
   struct timespec tr;
   nanosleep (&tw, &tr);
   gfx_open(SCREEN_XSIZE, SCREEN_YSIZE, "RNC 1.0.1");    
   char alarm;
   int current_action = 0;
   do {
        game->check_balance();
        int previous = current_action;
        current_action = gfx_event_waiting();
        game->draw_interface();
        for (int i = 0; i < 21; i++) {
            buttons[i]->drawing(game);
        }
        if ((current_action == 1) && (previous == 0)) {
            alarm = gfx_wait();
            if (alarm == 1) {
                for (int i = 0; i < 21; i++) {
                    buttons[i]->onclick(game);
                }
            }
        }
        nanosleep (&tw, &tr);
    } while (game->iseog() != 1);
}
