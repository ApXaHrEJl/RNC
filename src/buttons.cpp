#include "buttons.h"
#include <iostream>
//#include <boost/filesystem.hpp>

void Button_Parent :: onclick(System_props* game) {}

void Button_Parent :: drawing(System_props* game) {}

void Button_Persistent :: drawing(System_props* game) 
{
    int y2 = y + 32;
    int x2 = x + (size * 64);
    draw_button(x, y, x2, y2, 1);
    int middle_x = x + ((x2 - x) / 2);
    gfx_color(255,255,255);
    draw_text(middle_x,y+12,name);
}

void Button::drawing(System_props* game) 
{
    int cond = condition(game);
    if (cond == -1) {
        return;
    }
    int y2 = y + 32;
    int x2 = x + (size * 64);
    draw_button(x, y, x2, y2, cond);
    int middle_x = x + ((x2 - x) / 2);
    gfx_color(255,255,255);
    draw_text(middle_x,y+12,name);
}

int Button :: condition(System_props* game)
{
    if (game->get_room() != room) {
        return -1;
    }
    switch (id) {
        case 6: 
            if (game->get_bet() > 1) {
                return 1;
            }
            break;
        case 7: 
            if (game->get_bet() < game->get_money()) {
                return 1;
            }
            break;
        case 8: 
            if (game->get_bet() > 1) {
                return 1;
            }
            break;
        case 9: 
            if (game->get_bet() < game->get_money()) {
                return 1;
            }
            break;
        case 10: 
            if (game->get_bet() > 2) {
                return 1;
            }
            break;
        case 11: 
            if (game->get_bet() < game->get_money()) {
                return 1;
            }
            break;
        case 12: 
            if (game->get_chance() > 1) {
                return 1;
            }
            break;
        case 13: 
            if (game->get_chance() < 95) {
                return 1;
            }
            break;
        case 14: 
            if (game->get_chance() > 1) {
                return 1;
            }
            break;
        case 15: 
            if (game->get_chance() < 95) {
                return 1;
            }
            break;
        case 16: 
            if (game->get_chance() > 1) {
                return 1;
            }
            break;
        case 17: 
            if (game->get_chance() < 95) {
                return 1;
            }
            break;
        default: 
            return 1;
    }
    return 0;
}

Button_Parent::~Button_Parent() {}

Button_Persistent::~Button_Persistent() {}

Button::~Button() {}

void Button_Persistent::onclick(System_props* game) 
{
    if ((gfx_xpos() >= x) && (gfx_xpos() <= x + (64 * size))
        && (gfx_ypos() >= y) && (gfx_ypos() <= y + 32)) {
        event(game);
    }
}

void Button::onclick(System_props* game)
{
    int cond = condition(game);
    if (cond == -1) {
        return;
    }    
    if ((gfx_xpos() >= x) && (gfx_xpos() <= x + (64 * size))
        && (gfx_ypos() >= y) && (gfx_ypos() <= y + 32)
        && (cond == 1)) {
        event(game);
    }
}

void Button_Parent::event(System_props* game) 
{
    switch (id) {
        case 0: 
            game->set_room(1);
            break;
        case 1: 
            game->set_room(2);
            break;
        case 2: 
            game->set_room(3);
            break;
        case 3: 
            game->save_game();
            break;
        case 4: 
            game->load_game();
            break;
        case 5: 
            game->endofgame();
            break;
        case 6:
            game->set_bet(1); 
            break;
        case 7:
            game->set_bet(game->get_money()); 
            break;
        case 8:
            game->set_bet(game->get_bet() - 1); 
            break;
        case 9:
            game->set_bet(game->get_bet() + 1); 
            break;
        case 10:
            game->set_bet(game->get_bet() / 2); 
            break;
        case 11:
            game->set_bet(game->get_bet() * 2);
            if (game->get_bet() > game->get_money()) {
                game->set_bet(game->get_money());
            }
            break;
        case 12:
            game->set_chance(1);
            break;
        case 13:
            game->set_chance(95);
            break;
        case 14:
            game->set_chance(game->get_chance() - 1);
            break;
        case 15:
            game->set_chance(game->get_chance() + 1);
            break;
        case 16:
            game->set_chance(game->get_chance() / 2);
            break;
        case 17:
            game->set_chance(game->get_chance() * 2);
            if (game->get_chance() > 95) {
                game->set_chance(95);
            }
            break;
        case 18:
            game->play(1);
            break;
        case 19:
            game->play(2);
            break;
        case 20:
            game->mining();
            break;
    }
}

int Button_Parent :: last_id = 0;

