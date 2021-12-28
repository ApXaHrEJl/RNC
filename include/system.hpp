#ifndef H_SYSTEM_PROPS
#define H_SYSTEM_PROPS

class System_props {
 private:
  int current_room, seed, bet, last_seed, chance;
  bool result, eog;
  double money, prize;

 public:
  System_props(
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
  void calc_prize();
  void set_room(int value);
  int get_room();
  void set_chance(int value);
  int get_chance();
  void set_bet(int value);
  int get_bet();
  double get_money();
  int get_seed();
  bool iseog();
  void endofgame();
  void mining();
  void play(int mode);
  void draw_interface();
  void generate_seed();
  void check_balance();
  void load_game();
  void save_game();
};

#endif
