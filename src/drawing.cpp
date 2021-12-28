#include <iostream>
#include <gfx.h>
#include <string>
using namespace std;

void draw_symbol(int x, int y, char symb)
{
    switch (symb) {
        case 'a': gfx_line(x+0,y+1,x+0,y+7); 
                  gfx_line(x+5,y+1,x+5,y+7); 
                  gfx_line(x+1,y+0,x+4,y+0); 
                  gfx_line(x+0,y+4,x+4,y+4); 
                  break;
        case 'b': gfx_line(x+0,y+0,x+4,y+0); 
                  gfx_line(x+0,y+0,x+0,y+6); 
                  gfx_line(x+0,y+3,x+3,y+3); 
                  gfx_line(x+4,y+4,x+4,y+6); 
                  gfx_line(x+0,y+7,x+3,y+7); 
                  gfx_line(x+4,y+1,x+4,y+2);
                  break;
        case 'c': gfx_line(x+0,y+1,x+0,y+6); 
                  gfx_line(x+1,y+0,x+4,y+0); 
                  gfx_line(x+1,y+7,x+4,y+7); 
                  gfx_point(x+4,y+1); 
                  gfx_point(x+4,y+6);
                  break;
        case 'd': gfx_line(x+0,y+0,x+0,y+7); 
                  gfx_line(x+0,y+0,x+3,y+0); 
                  gfx_line(x+0,y+7,x+3,y+7); 
                  gfx_line(x+4,y+1,x+4,y+6);
                  break;
        case 'e': gfx_line(x+0,y+0,x+0,y+7); 
                  gfx_line(x+0,y+0,x+4,y+0); 
                  gfx_line(x+0,y+3,x+4,y+3); 
                  gfx_line(x+0,y+7,x+4,y+7);
                  break;
        case 'f': gfx_line(x+0,y+0,x+0,y+7); 
                  gfx_line(x+0,y+0,x+4,y+0); 
                  gfx_line(x+0,y+3,x+4,y+3);
                  break;
        case 'g': gfx_line(x+0,y+1,x+0,y+6); 
                  gfx_line(x+1,y+0,x+4,y+0); 
                  gfx_line(x+1,y+7,x+4,y+7); 
                  gfx_line(x+4,y+4,x+4,y+6); 
                  gfx_line(x+2,y+4,x+4,y+4); 
                  gfx_point(x+4,y+1);
                  break;
        case 'h': gfx_line(x+0,y+0,x+0,y+7); 
                  gfx_line(x+4,y+0,x+4,y+7); 
                  gfx_line(x+0,y+4,x+4,y+4);
                  break;
        case 'i': gfx_line(x+1,y+0,x+3,y+0); 
                  gfx_line(x+1,y+7,x+3,y+7); 
                  gfx_line(x+2,y+0,x+2,y+7);
                  break;
        case 'j': gfx_line(x+2,y+0,x+4,y+0); 
                  gfx_line(x+3,y+0,x+3,y+6); 
                  gfx_line(x+1,y+7,x+2,y+7); 
                  gfx_line(x+0,y+5,x+0,y+6);
                  break;
        case 'k': gfx_line(x+0,y+0,x+0,y+7); 
                  gfx_line(x+0,y+4,x+4,y+0); 
                  gfx_line(x+0,y+3,x+4,y+7);
                  break;
        case 'l': gfx_line(x+0,y+0,x+0,y+7); 
                  gfx_line(x+0,y+7,x+4,y+7);
                  break;
        case 'm': gfx_line(x+0,y+0,x+0,y+7); 
                  gfx_line(x+4,y+0,x+4,y+7); 
                  gfx_line(x+2,y+2,x+2,y+7); 
                  gfx_point(x+1,y+1); 
                  gfx_point(x+3,y+1);
                  break;
        case 'n': gfx_line(x+0,y+0,x+0,y+7); 
                  gfx_line(x+4,y+0,x+4,y+7); 
                  gfx_line(x+0,y+2,x+3,y+5);
                  break;
        case 'o': gfx_line(x+0,y+1,x+0,y+6); 
                  gfx_line(x+1,y+0,x+3,y+0); 
                  gfx_line(x+1,y+7,x+3,y+7); 
                  gfx_line(x+4,y+1,x+4,y+6);
                  break;
        case 'p': gfx_line(x+0,y+0,x+3,y+0); 
                  gfx_line(x+0,y+0,x+0,y+7); 
                  gfx_line(x+0,y+3,x+3,y+3); 
                  gfx_line(x+4,y+1,x+4,y+2);
                  break;
        case 'q': gfx_line(x+0,y+1,x+0,y+6); 
                  gfx_line(x+1,y+0,x+3,y+0); 
                  gfx_line(x+1,y+7,x+3,y+7); 
                  gfx_line(x+4,y+1,x+4,y+6); 
                  gfx_line(x+2,y+5,x+4,y+7);
                  break;
        case 'r': gfx_line(x+0,y+0,x+3,y+0); 
                  gfx_line(x+0,y+0,x+0,y+7); 
                  gfx_line(x+0,y+3,x+3,y+3); 
                  gfx_line(x+4,y+1,x+4,y+2); 
                  gfx_line(x+0,y+3,x+4,y+7);
                  break;
        case 's': gfx_line(x+1,y+0,x+3,y+0); 
                  gfx_line(x+1,y+7,x+3,y+7); 
                  gfx_line(x+0,y+1,x+0,y+2); 
                  gfx_line(x+4,y+1,x+4,y+2); 
                  gfx_line(x+0,y+5,x+0,y+6); 
                  gfx_line(x+4,y+5,x+4,y+6); 
                  gfx_line(x+1,y+3,x+3,y+4);
                  break;
        case 't': gfx_line(x+0,y+0,x+4,y+0); 
                  gfx_line(x+2,y+0,x+2,y+7);
                  break;
        case 'u': gfx_line(x+0,y+0,x+0,y+6); 
                  gfx_line(x+4,y+0,x+4,y+6); 
                  gfx_line(x+1,y+7,x+3,y+7);
                  break;
        case 'v': gfx_line(x+0,y+0,x+0,y+4); 
                  gfx_line(x+4,y+0,x+4,y+4); 
                  gfx_line(x+1,y+5,x+1,y+6); 
                  gfx_line(x+3,y+5,x+3,y+6); 
                  gfx_point(x+2,y+7);
                  break;
        case 'w': gfx_line(x+0,y+0,x+0,y+7); 
                  gfx_line(x+4,y+0,x+4,y+7); 
                  gfx_line(x+2,y+0,x+2,y+5); 
                  gfx_point(x+1,y+6); 
                  gfx_point(x+3,y+6);
                  break;
        case 'x': gfx_line(x+0,y+0,x+0,y+1); 
                  gfx_line(x+4,y+0,x+4,y+1); 
                  gfx_line(x+0,y+5,x+0,y+7); 
                  gfx_line(x+4,y+5,x+4,y+7); 
                  gfx_line(x+1,y+2,x+3,y+4); 
                  gfx_line(x+1,y+4,x+3,y+2);
                  break;
        case 'y': gfx_line(x+0,y+0,x+0,y+4); 
                  gfx_line(x+4,y+0,x+4,y+4); 
                  gfx_line(x+0,y+7,x+1,y+7); 
                  gfx_line(x+1,y+7,x+4,y+4); 
                  gfx_point(x+1,y+5);
                  break;
        case 'z': gfx_line(x+0,y+0,x+4,y+0); 
                  gfx_line(x+0,y+7,x+4,y+7); 
                  gfx_line(x+0,y+7,x+4,y+0);
                  break;
        case '1': gfx_line(x+2,y+0,x+2,y+7);
                  gfx_line(x+0,y+7,x+4,y+7);
                  gfx_line(x+0,y+2,x+2,y+0);
                  break;
        case '2': gfx_line(x+0,y+1,x+0,y+2); 
                  gfx_line(x+1,y+0,x+3,y+0); 
                  gfx_line(x+4,y+1,x+4,y+3); 
                  gfx_line(x+4,y+3,x+0,y+7);
                  gfx_line(x+0,y+7,x+4,y+7);
                  break;
        case '3': gfx_line(x+1,y+0,x+3,y+0); 
                  gfx_line(x+4,y+1,x+4,y+2); 
                  gfx_line(x+4,y+5,x+4,y+6); 
                  gfx_line(x+1,y+7,x+3,y+7); 
                  gfx_point(x+0,y+1); 
                  gfx_point(x+0,y+6); 
                  gfx_point(x+3,y+3); 
                  gfx_point(x+2,y+4); 
                  gfx_point(x+3,y+4);
                  break;
        case '4': gfx_line(x+3,y+0,x+3,y+7); 
                  gfx_line(x+0,y+5,x+4,y+5); 
                  gfx_line(x+0,y+3,x+0,y+5); 
                  gfx_line(x+0,y+3,x+3,y+0);
                  break;
        case '5': gfx_line(x+0,y+0,x+4,y+0); 
                  gfx_line(x+0,y+0,x+0,y+3); 
                  gfx_line(x+0,y+3,x+3,y+3); 
                  gfx_line(x+4,y+4,x+4,y+6); 
                  gfx_line(x+1,y+7,x+3,y+7); 
                  gfx_point(x+0,y+6);
                  break;
        case '6': gfx_line(x+1,y+0,x+3,y+0); 
                  gfx_line(x+0,y+1,x+0,y+6); 
                  gfx_line(x+0,y+3,x+3,y+3); 
                  gfx_line(x+4,y+4,x+4,y+6); 
                  gfx_line(x+1,y+7,x+3,y+7); 
                  gfx_point(x+4,y+1);
                  break;
        case '7': gfx_line(x+0,y+0,x+4,y+0); 
                  gfx_line(x+4,y+0,x+4,y+2); 
                  gfx_line(x+0,y+6,x+4,y+2); 
                  gfx_point(x+0,y+1); 
                  gfx_point(x+0,y+7);
                  break;
        case '8': gfx_line(x+1,y+0,x+3,y+0); 
                  gfx_line(x+1,y+3,x+3,y+3); 
                  gfx_line(x+1,y+7,x+3,y+7); 
                  gfx_line(x+0,y+1,x+0,y+2); 
                  gfx_line(x+4,y+1,x+4,y+2); 
                  gfx_line(x+0,y+4,x+0,y+6); 
                  gfx_line(x+4,y+4,x+4,y+6);
                  break;
        case '9': gfx_line(x+1,y+0,x+3,y+0); 
                  gfx_line(x+4,y+1,x+4,y+6); 
                  gfx_line(x+1,y+4,x+4,y+4); 
                  gfx_line(x+0,y+1,x+0,y+3); 
                  gfx_line(x+1,y+7,x+3,y+7); 
                  gfx_point(x+0,y+6); 
                  break;
        case '0': gfx_line(x+0,y+1,x+0,y+6); 
                  gfx_line(x+1,y+0,x+3,y+0); 
                  gfx_line(x+1,y+7,x+3,y+7); 
                  gfx_line(x+4,y+1,x+4,y+6);
                  break;
        case '+': gfx_line(x+2,y+2,x+2,y+6); 
                  gfx_line(x+0,y+4,x+4,y+4);
                  break;
        case '-': gfx_line(x+0,y+4,x+4,y+4);
                  break;
        case '=': gfx_line(x+0,y+3,x+4,y+3);
                  gfx_line(x+0,y+5,x+4,y+5);
                  break;
        case ',': gfx_line(x+2,y+5,x+2,y+6);
                  gfx_point(x+1,y+7);
                  break;
        case '.': gfx_line(x+2,y+6,x+2,y+7);
                  break;
        case ':': gfx_line(x+2,y+1,x+2,y+2);
                  gfx_line(x+2,y+5,x+2,y+6);
                  break;
    }
}

void draw_text(int x, int y, const string text)
{
    x -= (text.size() * 7) / 2;
    for (size_t i = 0; i < text.size(); i++) {
        draw_symbol(x+(7*i), y, text[i]);    
    }
}

void draw_text(int x, int y, int value)
{
    draw_text(x, y, to_string(value));
}

void draw_text(int x, int y, double value)
{
    int buf = (int)value;
    int symbols = 2 + (buf == 0);
    while (buf > 0) {
        symbols++;
        buf = buf / 10;
    }
    buf = (int)(value * 100);
    string text = to_string(buf);
    if (buf < 100) {
        text = "0" + text;
    }
    x -= ((text.size()+1) * 7) / 2;
    int point = 0;
    for (size_t i = 0; i < text.size(); i++) {
        if (symbols - i == 2) {
            draw_symbol(x+(7*i), y, '.');
            point = 1;
        }
        draw_symbol(x+(7*(i + point)), y, text[i]);    
    }
}

void draw_rectangle(int x1, int y1, int x2, int y2)
{
    gfx_line(x1, y1, x2, y1);
    gfx_line(x1, y2, x2, y2);
    gfx_line(x1, y1, x1, y2);
    gfx_line(x2, y1, x2, y2);

}

void draw_button(int x1, int y1, int x2, int y2, int cond)
{
    if (cond == 1) {
        gfx_color(100,100,100);
        for (int i = 1; i < 32; i++) {
            gfx_line(x1, y1+i, x2, y1+i);
        }
    }
    gfx_color(255,255,255);
    draw_rectangle(x1,y1,x2,y2);
    draw_rectangle(x1+2,y1+2,x2-2,y2-2);    
}

