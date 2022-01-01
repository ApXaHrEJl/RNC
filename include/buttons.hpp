#pragma once

#include <cstddef>
#include <string_view>
#include <system.hpp>
#include <vector>

namespace rnc {

class Button_Parent {
 protected:
  const int x;
  const int y;
  const int size;
  std::string_view name;
  int id;
  static int last_id;

 public:
  Button_Parent(
      const int set_x,
      const int set_y,
      const int set_size,
      std::string_view set_name)
      : x(set_x), y(set_y), size(set_size), name(set_name) {
    id = last_id;
    last_id++;
  }
  Button_Parent(
      const int set_x,
      const int set_y,
      std::string_view set_name)
      : x(set_x), y(set_y), size(1), name(set_name) {
    id = last_id;
    last_id++;
  }
  void event(System& game);
  virtual ~Button_Parent();
  virtual void onclick(System& game) = 0;
  virtual void drawing(System& game) const = 0;
};

class Button_Persistent : public Button_Parent {
 public:
  Button_Persistent(
      const int set_x,
      const int set_y,
      std::string_view set_name)
      : Button_Parent(set_x, set_y, 2, set_name) {}
  ~Button_Persistent() override;
  void onclick(System& game) override;
  void drawing(System& game) const override;
};

class Button : public Button_Parent {
 private:
  const int room;
  int condition(System& game) const;

 public:
  Button(
      const int set_x,
      const int set_y,
      const int set_size,
      const int set_room,
      std::string_view set_name)
      : Button_Parent(set_x, set_y, set_size, set_name), room(set_room) {}
  Button(
      const int set_x,
      const int set_y,
      const int set_room,
      std::string_view set_name)
      : Button_Parent(set_x, set_y, set_name), room(set_room) {}
  ~Button() override;
  void onclick(System& game) override;
  void drawing(System& game) const override;
};

Button_Parent** buttons_init();

void buttons_clear(Button_Parent** buttons);

}  // namespace rnc
