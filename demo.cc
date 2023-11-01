#include "bad.h"

int main() {
  Point p = {1, 2, "Captain"};
  auto [circle_x, circle_y, title] = p;

  int radius = circle_x;
  drawCircle(circle_x, circle_y, radius);
  drawText(title, circle_x, circle_y);
  drawText(std::to_string(PI * radius * radius), circle_x, circle_y);
}

// to test the structed binding without comments
