#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Foo1
{
   public:
    Foo1() { cout << "Foo1 默认构造函数" << endl; }
    Foo1(const Foo1 &foo) { cout << "Foo1 拷贝构造函数" << endl; }
    // Foo1(const Foo1 &&foo) { cout << "Foo1 移动构造函数" << endl; }
    Foo1 &operator=(const Foo1 &foo) { cout << "Foo1 拷贝赋值函数" << endl; }
    Foo1 &operator=(const Foo1 &&foo) { cout << "Foo1 移动赋值函数" << endl; }
};

class Foo2
{
   public:
    Foo2() { cout << "Foo2 默认构造函数" << endl; }
    Foo2(const Foo2 &foo) { cout << "Foo2 拷贝构造函数" << endl; }
    Foo2(const Foo2 &&foo) { cout << "Foo2 移动构造函数" << endl; }
    Foo2 &operator=(const Foo2 &foo) { cout << "Foo2 拷贝赋值函数" << endl; }
    Foo2 &operator=(const Foo2 &&foo) { cout << "Foo2 移动赋值函数" << endl; }
};

class Foo3
{
   public:
    // Foo3() = default;
    //  Foo3(const Foo3 &f) = default;
    //  Foo3(Foo3 &&f) = default;
    //  Foo3 &operator=(const Foo3 &f) { cout << "Foo3 拷贝赋值函数" << endl; }
    //  Foo3 &operator=(const Foo3 &&f) { cout << "Foo3 移动赋值函数" << endl; }

   private:
    Foo1 foo1;
    Foo2 foo2;
};

int main()
{
    Foo3 f1;
    std::cout << std::endl;

    Foo3 f2(f1);
    std::cout << std::endl;

    Foo3 f3(std::move(f1));
    std::cout << std::endl;

    Foo3 f4;
    f4 = f1;
    f4 = std::move(f1);
    std::cout << std::endl;

    Foo3 f5 = f1;
    Foo3 f6 = std::move(f1);
    std::cout << std::endl;
}