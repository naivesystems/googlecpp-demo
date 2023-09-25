#include <cstring>
#include <iostream>
#include <string>

struct Point {
    int x;
    int y;
    std::string name;
};

class Base {
  public:
    Base(int n) { data_ = n; }
    explicit Base(int x, int y) { data_ = x + y; }
    virtual bool Equal(Base* other = nullptr) = 0;

  private:
    int data_;
};

class Derived : public Base {
  public:
    bool EqualDynamic(Base* other);
    bool EqualStatic(Base* other);

  private:
    int data_;
};

bool Derived::EqualDynamic(Base* other) {
    Derived* that = dynamic_cast<Derived*>(other);
    return this->data_ == that->data_;
}

bool Derived::EqualStatic(Base* other) {
    Derived* that = static_cast<Derived*>(other);
    return this->data_ == that->data_;
}

int main() {
    Point p1, p2;
    memset(&p1, 0, sizeof(p1));     // sizeof(varname)
    memset(&p2, 0, sizeof(Point));  // sizeof(type)

    float f = 3.5;
    int c_cast = (int)f;
    int cpp_cast = static_cast<int>(f);
}
