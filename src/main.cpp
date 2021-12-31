#include <buttons.hpp>
#include <screen.hpp>
#include <vector>

int main() {
  rnc::Button_Parent** buttons = rnc::buttons_init();
  rnc::System game;
  rnc::screen_show(game, buttons);
  buttons_clear(buttons);
  return 0;
}
