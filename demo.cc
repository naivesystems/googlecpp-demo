class Base {
 public:
  virtual void someFunction();
};

class Derived : public Base {
 public:
  virtual void someFunction() override;
};
