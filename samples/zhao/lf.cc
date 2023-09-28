#include <iostream>

class A
{
   public:
    A() = default;
    ~A() = default;
    int x, y;
    void change(int x, int y, int &a, int &b);
    void func1();
};

void A::change(int x, int y, int &a, int &b)
{
    a = 1;
    b = 2;
    return;
}

void A::func1()
{
    int x = 1;
    int y = 2;
    int m = 3;
    int n = 4;
    change(x, y, m, n);
    return;
}

int main()
{
    A a;
    a.func1();
    return 0;
}