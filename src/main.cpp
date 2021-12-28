#include <buttons.hpp>
#include <screen.hpp>

int main() {
  rnc::Button_Parent** buttons = new rnc::Button_Parent*[21];
  rnc::buttons_init(buttons);
  rnc::System_props game;
  rnc::screen_show(&game, buttons);
  rnc::buttons_clear(buttons);
  return 0;
}
