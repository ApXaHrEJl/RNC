#ifndef H_DRAWING
#define H_DRAWING
#include <gfx.h>
#include <string>

using namespace std;

void draw_symbol(int x, int y, char symb);

void draw_text(int x, int y, string text);

void draw_text(int x, int y, int value);

void draw_text(int x, int y, double value);

void draw_rectangle(int x1, int y1, int x2, int y2);

void draw_button(int x1, int y1, int x2, int y2, int cond);

#endif
