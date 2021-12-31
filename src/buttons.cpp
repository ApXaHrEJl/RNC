#include <buttons.hpp>
#include <drawing.hpp>
#include <gfx.hpp>
#include <iostream>
#include <system.hpp>

#define RGB_WHITE 255, 255, 255
#define MAX_CHANCE 95
#define MIN_CHANCE 1
#define MIN_BET 1

namespace rnc {

void Button_Persistent ::drawing(System* game) {
  int y2 = y + 32;
  int x2 = x + (size * 64);
  draw_button(x, y, x2, y2, 1);
  int middle_x = x + ((x2 - x) / 2);
  gfx_color(RGB_WHITE);
  draw_text(middle_x, y + 12, name);
}

void Button::drawing(System* game) {
  int cond = condition(game);
  if (cond == -1) {
    return;
  }
  int y2 = y + 32;
  int x2 = x + (size * 64);
  draw_button(x, y, x2, y2, cond);
  int middle_x = x + ((x2 - x) / 2);
  gfx_color(RGB_WHITE);
  draw_text(middle_x, y + 12, name);
}

int Button ::condition(System* game) {
  if (game->get_room() != room) {
    return -1;
  }
  switch (id) {
    case 6:
      if (game->get_bet() > MIN_BET) {
        return 1;
      }
      break;
    case 7:
      if (game->get_bet() < game->get_money()) {
        return 1;
      }
      break;
    case 8:
      if (game->get_bet() > MIN_BET) {
        return 1;
      }
      break;
    case 9:
      if (game->get_bet() < game->get_money()) {
        return 1;
      }
      break;
    case 10:
      if (game->get_bet() > MIN_BET) {
        return 1;
      }
      break;
    case 11:
      if (game->get_bet() < game->get_money()) {
        return 1;
      }
      break;
    case 12:
      if (game->get_chance() > MIN_CHANCE) {
        return 1;
      }
      break;
    case 13:
      if (game->get_chance() < MAX_CHANCE) {
        return 1;
      }
      break;
    case 14:
      if (game->get_chance() > MIN_CHANCE) {
        return 1;
      }
      break;
    case 15:
      if (game->get_chance() < MAX_CHANCE) {
        return 1;
      }
      break;
    case 16:
      if (game->get_chance() > MIN_CHANCE) {
        return 1;
      }
      break;
    case 17:
      if (game->get_chance() < MAX_CHANCE) {
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

void Button_Persistent::onclick(System* game) {
  if ((gfx_xpos() >= x) && (gfx_xpos() <= x + (64 * size)) &&
      (gfx_ypos() >= y) && (gfx_ypos() <= y + 32)) {
    event(game);
  }
}

void Button::onclick(System* game) {
  int cond = condition(game);
  if (cond == -1) {
    return;
  }
  if ((gfx_xpos() >= x) && (gfx_xpos() <= x + (64 * size)) &&
      (gfx_ypos() >= y) && (gfx_ypos() <= y + 32) && (cond == 1)) {
    event(game);
  }
}

void Button_Parent::event(System* game) {
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
      game->set_bet(MIN_BET);
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
      game->set_chance(MIN_CHANCE);
      break;
    case 13:
      game->set_chance(MAX_CHANCE);
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
      if (game->get_chance() > MAX_CHANCE) {
        game->set_chance(MAX_CHANCE);
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

void buttons_init(Button_Parent** buttons) {
  buttons[0] = new Button_Persistent(128, 16, "main game");
  buttons[1] = new Button_Persistent(256, 16, "miner");
  buttons[2] = new Button_Persistent(384, 16, "info");
  buttons[3] = new Button_Persistent(128, 432, "save game");
  buttons[4] = new Button_Persistent(256, 432, "load game");
  buttons[5] = new Button_Persistent(384, 432, "quit game");
  buttons[6] = new Button(55, 284, 1, "min");
  buttons[7] = new Button(119, 284, 1, "max");
  buttons[8] = new Button(55, 316, 1, "-1");
  buttons[9] = new Button(119, 316, 1, "+1");
  buttons[10] = new Button(55, 348, 1, "divide");
  buttons[11] = new Button(119, 348, 1, "double");
  buttons[12] = new Button(191, 284, 1, "min");
  buttons[13] = new Button(255, 284, 1, "max");
  buttons[14] = new Button(191, 316, 1, "-1");
  buttons[15] = new Button(255, 316, 1, "+1");
  buttons[16] = new Button(191, 348, 1, "divide");
  buttons[17] = new Button(255, 348, 1, "double");
  buttons[18] = new Button(327, 300, 2, 1, "less");
  buttons[19] = new Button(455, 300, 2, 1, "more");
  buttons[20] = new Button(256, 224, 2, 2, "get money");
}

void buttons_clear(Button_Parent** buttons) {
  for (int i = 0; i < 21; i++) {
    delete buttons[i];
  }
  delete buttons;
}

int Button_Parent::last_id = 0;

}  // namespace rnc

