#pragma once
#include <string>
#include <vector>

struct CalendarDay {
    int number;
    int row;
    int col;
};

class Calendar {
private:
    std::string currentMonthName;
    std::vector<CalendarDay> days;

public:
    Calendar();                // Initializes current month
    void render(int y, int x); // Draw calendar grid
};