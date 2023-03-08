#include <string.h>

#include <iostream>
#include <string>

using namespace std;

void memcpy_test()
{
    string test = "adsadasds";
    char *buffer = new char[128];
    memcpy(buffer, test.c_str(), test.size());
    cout << "buffer: " << buffer << endl;
    delete[] buffer;
}

int main() { memcpy_test(); }