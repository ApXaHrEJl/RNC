#include "screen.h"
//#include "system.h"
//#include "buttons.h"

int main()
{   
    Button_Parent* buttons[21];
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
    buttons[18] = new Button(327, 300, 2, 1,"less");
    buttons[19] = new Button(455, 300, 2, 1,"more");
    buttons[20] = new Button(256, 224, 2, 2,"get money");
    System_props game;
    screen_show(&game, buttons);
    return 0;
}
