#pragma once

namespace rnc {

class System {
 private:
  int current_room, seed, bet, last_seed, chance;
  bool result, eog;
  double money, prize;

 public:
  System(
      int init_room = 1,
      int init_bet = 5,
      int init_chance = 50,
      double init_money = 20)
      : current_room(init_room),
        bet(init_bet),
        chance(init_chance),
        money(init_money) {
    last_seed = -1;
    eog = 0;
    prize = 10;
  }
  void draw_main_frame() const;
  void draw_main_game_room() const;
  void draw_miner_room() const;
  void draw_info_room() const;
  void draw_interface() const;
  
  int get_room() const { return current_room; };
  int get_chance() const { return chance; }
  int get_bet() const { return bet; }
  double get_money() const { return money; }
  bool iseog() const { return eog; }
  // int get_seed() const;
  
  void set_room(int value);
  void set_chance(int value);
  void set_bet(int value);
  void calc_prize();
  void generate_seed();
  void endofgame();

  void play(int mode);
  void mining();
  void check_balance();

  void save_game();
  void load_game();
};

}  // namespace rnc
