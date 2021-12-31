#include <buttons.hpp>
#include <cstdio>
#include <ctime>
#include <drawing.hpp>
#include <fstream>
#include <iostream>
#include <system.hpp>

namespace rnc {

void System::draw_interface() {
  gfx_clear_color(45, 45, 45);
  gfx_clear();
  gfx_color(255, 255, 255);
  gfx_line(0, 48, 640, 48);
  gfx_line(0, 432, 640, 432);
  switch (current_room) {
    case 1:
      draw_text(320, 64, "main game");
      draw_text(320, 104, "balance:");
      draw_text(320, 120, money);
      draw_text(187, 148, "game settings");
      draw_text(187, 204, "prize:");
      draw_text(187, 220, prize);
      draw_text(119, 268, "bet: " + std::to_string(bet));
      draw_text(255, 268, "chance: " + std::to_string(chance));
      draw_text(455, 148, "play");
      draw_text(391, 340, "0-" + std::to_string((int)(9999.99 * chance)));
      draw_text(
          519,
          340,
          std::to_string((int)((9999.99 * (100 - chance)) + 1)) + "-999999");
      draw_rectangle(51, 160, 587, 416);
      gfx_line(323, 160, 323, 416);
      if (last_seed >= 0) {
        draw_text(455, 204, "last game result:");
        draw_text(455, 220, last_seed);
        std::string res;
        if (result == 0) {
          gfx_color(255, 0, 0);
          res = "you lose";
        } else {
          gfx_color(0, 255, 0);
          res = "you win";
        }
        draw_text(455, 236, res);
      } else {
        draw_text(455, 204, "select the range of number");
      }
      break;
    case 2:
      draw_text(320, 64, "miner");
      draw_text(
          320,
          104,
          "if you have no money, you can get random bonus from 0.1 to 1 money "
          "per 1 click");
      draw_text(320, 192, "balance:");
      draw_text(320, 208, money);
      break;
    case 3:
      draw_text(320, 64, "info");
      draw_text(320, 104, "this is simple clicker-game with guessing numbers.");
      draw_text(
          320,
          120,
          "to play, you should select the range of the randomly generated "
          "number,");
      draw_text(320, 136, "and press the buttons ,,more,, or ,,less,,.");
      draw_text(320, 152, "you can set bet and chance to win yourself.");
      draw_text(
          320,
          176,
          "you also just can tap button in miner menu to get in-game "
          "currency.");
      draw_text(320, 336, "this game is a course project in the discipline");
      draw_text(320, 352, "object-oriented programming");
      draw_text(320, 368, "author: sitnikov danila alekseevich");
      draw_text(320, 400, "novosibirsk, 2020");
      break;
  }
}

void System::set_room(int value) {
  current_room = value;
}

int System::get_room() {
  return current_room;
}

void System::set_chance(int value) {
  chance = value;
  calc_prize();
}

int System::get_chance() {
  return chance;
}

void System::set_bet(int value) {
  bet = value;
  calc_prize();
}

int System::get_bet() {
  return bet;
}

double System::get_money() {
  return money;
}

bool System::iseog() {
  return eog;
}

void System::endofgame() {
  eog = 1;
}

void System::calc_prize() {
  prize = bet * (100.00 / chance);
}

void System::generate_seed() {
  if (last_seed == -1) {
    srand(time(NULL));
  }
  seed = rand() % 1000000;
  last_seed = seed;
}

void System::play(int mode) {
  generate_seed();
  money -= bet;
  if (mode == 1) {
    if (last_seed <= ((int)(9999.99 * chance))) {
      result = 1;
      money += prize;
    } else {
      result = 0;
    }
  } else {
    if (last_seed > ((int)(9999.99 * (100 - chance)))) {
      result = 1;
      money += prize;
    } else {
      result = 0;
    }
  }
  if ((result == 0) && (bet > money)) {
    bet = money;
    if (bet < 1) {
      bet = 1;
    }
    calc_prize();
  }
  if (money > 999999.99) {
    money = 999999.99;
  }
}

void System::mining() {
  money += ((rand() % 90) / 100.00) + 0.1;
  if (money > 999999.99) {
    money = 999999.99;
  }
}

void System::check_balance() {
  if (money < 1) {
    current_room = 2;
  }
}

void System::save_game() {
  std::ofstream savedata("userdata/savedata");
  if (savedata.is_open()) {
    savedata << money;
    savedata.close();
  } else {
    std::cout << "Savedata not found\n";
  }
}

void System::load_game() {
  std::ifstream savedata("userdata/savedata");
  if (savedata.is_open()) {
    double value;
    savedata >> value;
    savedata.close();
    if ((value < 1000000) && (value >= 0)) {
      money = value;
      if (bet > money) {
        bet = money;
      }
    } else {
      std::cout << "Bad data format\n";
    }
  } else {
    std::cout << "Savedata not found\n";
  }
}

}  // namespace rnc
