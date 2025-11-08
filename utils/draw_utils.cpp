#include "../include/draw_utils.h"
#include <ncurses.h>

void drawDivider(int y, int width) {
    for (int i = 0; i < width; i++)
        mvaddch(y, i, '-');
}

void drawBox(int y, int x, int h, int w, const std::string& title) {
    mvprintw(y, x + 2, "[ %s ]", title.c_str());
    for (int i = 0; i < w; i++) {
        mvaddch(y + 1, x + i, '-');
        mvaddch(y + h, x + i, '-');
    }
}