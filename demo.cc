#include <ratio> // g1213
#include <cfenv> // g1214
#include <filesystem>  // g1215
#include <string>

struct Point {
    int x;
    int y;
    std::string name;
};

int main() {
  Point p = {1, 2, "Captain"};
  auto [circle_x, circle_y, title] = p;  // g1206
}
