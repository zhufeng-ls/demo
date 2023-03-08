#include <iostream>

using namespace std;

class Foo
{
   public:
    Foo() {}

    void transPair(void *data)
    {
        auto pair = (std::pair<float, float> *)data;
        cout << "after trans: " << pair->first << '\t' << pair->second << endl;
    }
};

int main()
{
    float a = 3.5, b = 3.6;

    Foo f;
    cout << "before trans: " << a << '\t' << b << endl;
    std::pair<float, float> pair = {a, b};
    f.transPair(&pair);
}