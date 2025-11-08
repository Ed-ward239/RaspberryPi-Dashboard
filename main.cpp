#include "headers/clock.h"
#include "headers/weather.h"
#include "headers/spotify.h"
#include "headers/calendar.h"
#include "headers/photos.h"
#include "include/env_loader.h"
#include <ncurses.h>
#include <thread>
#include <chrono>
#include <iostream>

int main() {
    auto env = loadEnv();

    Clock clock;
    Weather weather;
    Spotify spotify;
    Calendar calendar;
    Photos photos;

    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);

    int counter = 0;
    while (true) {
        clear();
        clock.render(1, 2);
        weather.render(4, 2);
        spotify.render(8, 2);
        calendar.render(14, 2);
        photos.render(22, 2);

        mvprintw(LINES - 1, 2, "Press 'q' to quit.");
        refresh();

        if (counter % 60 == 0) weather.update();
        if (counter % 15 == 0) spotify.update();
        counter++;

        std::this_thread::sleep_for(std::chrono::seconds(1));

        int ch = getch();
        if (ch == 'q' || ch == 'Q') break;
    }

    endwin();
    return 0;
}