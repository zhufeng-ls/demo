#include <queue>
#include <iostream>

using namespace std;

typedef struct 
{
    char* data;
    int   len;
} Data;

int main()
{
    queue<Data*> que;

    Data *d1, *d2, *d3;
    d1 = new Data;
    d1->data = new char[10];
    d1->len = 10;
    que.push(d1);

    cout << "Data size: " << sizeof(Data) << endl;
    cout << "int size: " << sizeof(int) << endl;
    cout << "pointer size: " << sizeof(char*) << endl;

    auto p = que.front();
    que.pop();
    if (p != nullptr)
    {
        cout << "true" << endl;;
        delete []p->data;
        delete p;
    }
    else 
    {
        cout << "false";
    }
}