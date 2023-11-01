#include <string>

struct Point {
    int x;
    int y;
    std::string name;
};

void drawText(std::string text, int x, int y);

void drawCircle(int x, int y, int radius);

const double PI = 3.1415926;
