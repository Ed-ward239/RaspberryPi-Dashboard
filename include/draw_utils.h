#pragma once
#include <string>

// Draws a horizontal divider line at row `y` with given width
void drawDivider(int y, int width);

// Draws a box outline with an optional title
void drawBox(int y, int x, int h, int w, const std::string& title);