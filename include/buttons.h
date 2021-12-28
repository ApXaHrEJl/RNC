#ifndef H_BUTTONS
#define H_BUTTONS
#include <system.h>
#include <cstddef>
#include <string>

using namespace std;

class Button_Parent {
 protected:
  int x, y, id, size;
  string name;
  static int last_id;

 public:
  Button_Parent(int set_x, int set_y, int set_size, string set_name)
      : x(set_x), y(set_y), size(set_size), name(set_name) {
    id = last_id;
    last_id++;
  }
  Button_Parent(int set_x, int set_y, string set_name)
      : x(set_x), y(set_y), size(1), name(set_name) {
    id = last_id;
    last_id++;
  }
  void event(System_props* game);
  virtual ~Button_Parent();
  virtual void onclick(System_props* game) = 0;
  virtual void drawing(System_props* game) = 0;
};

class Button_Persistent : public Button_Parent {
 public:
  Button_Persistent(int set_x, int set_y, string set_name)
      : Button_Parent(set_x, set_y, 2, set_name) {}
  virtual ~Button_Persistent();
  virtual void onclick(System_props* game);
  virtual void drawing(System_props* game);
};

class Button : public Button_Parent {
 private:
  int room;
  int condition(System_props* game);

 public:
  Button(int set_x, int set_y, int set_size, int set_room, string set_name)
      : Button_Parent(set_x, set_y, set_size, set_name), room(set_room) {}
  Button(int set_x, int set_y, int set_room, string set_name)
      : Button_Parent(set_x, set_y, set_name), room(set_room) {}
  virtual ~Button();
  virtual void onclick(System_props* game);
  virtual void drawing(System_props* game);
};

void buttons_init(Button_Parent** buttons);

void buttons_clear(Button_Parent** buttons);

#endif
