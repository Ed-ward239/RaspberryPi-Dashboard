#include "calendar.h"
#include <ncurses.h>
#include <ctime>
#include <sstream>
#include <iomanip>

Calendar::Calendar() {
    generateMonth();
}

void Calendar::generateMonth() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(now, "%B %Y");
    currentMonthName = oss.str();

    days.clear();

    tm first = {0};
    first.tm_year = now->tm_year;
    first.tm_mon = now->tm_mon;
    first.tm_mday = 1;
    mktime(&first);

    int startDay = first.tm_wday;
    int dayNum = 1;
    int row = 2, col = startDay;
    while (true) {
        days.push_back({dayNum, row, col * 3});
        dayNum++;
        col++;
        if (col >= 7) { col = 0; row++; }

        tm test = first;
        test.tm_mday = dayNum;
        if (mktime(&test) == -1 || test.tm_mon != first.tm_mon) break;
    }
}

void Calendar::render(int y, int x) {
    mvprintw(y, x, "📅 %s", currentMonthName.c_str());
    for (auto &day : days) {
        mvprintw(y + day.row, x + day.col, "%2d", day.number);
    }
}