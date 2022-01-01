#include <buttons.hpp>
#include <game_cycle.hpp>
#include <vector>

int main() {
  rnc::Button_Parent** buttons = rnc::buttons_init();
  rnc::System game;
  rnc::game_cycle(game, buttons);
  buttons_clear(buttons);
  return 0;
}
