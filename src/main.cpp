#include <buttons.hpp>
#include <screen.hpp>

int main() {
  Button_Parent** buttons = new Button_Parent*[21];
  buttons_init(buttons);
  System_props game;
  screen_show(&game, buttons);
  buttons_clear(buttons);
  return 0;
}
