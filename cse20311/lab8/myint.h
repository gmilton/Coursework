// myint.h
class MyInt {
  public:
    MyInt();
    MyInt(int);
    ~MyInt();
    int getValue();
    void setValue(int);
    void display();
    // prototype for operator+ goes here:
    MyInt operator+(MyInt);
    
  private:
    int value;
};

