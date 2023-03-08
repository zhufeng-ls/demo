#include <iostream>

using namespace std;

// #pragma pack(push, 4)
struct S2
{
    //   int c;
    char a[2];
    char b;
};
struct S3
{
    double d;
    char c;
    int i;
};

struct S4
{
    char c[2];
    struct S3 s3;
    long double d;
};
struct S4_1
{
    char c[2];
    struct S3 s3;
    double d;
};
struct S4_2
{
    char c[2];
    struct S3 s3;
    int d;
};

struct S4_3
{
    char c[2];
    struct S3 s3;
    short d;
};

struct S4_4
{
    char c[2];
    struct S3 s3;
};

struct S5
{
    int a;
    char b;
    short c;
};

struct S6
{
    char b;
    int a;
    short c;
};

int main()
{
    std::cout << "int: " << sizeof(int) << endl;
    std::cout << "double: " << sizeof(long double) << endl;
    std::cout << "char: " << sizeof(char) << endl;

    std::cout << "S2: " << sizeof(S2) << endl;
    std::cout << "S3: " << sizeof(S3) << endl;
    std::cout << "S4: " << sizeof(S4) << endl;
    std::cout << "S4_1: " << sizeof(S4_1) << endl;
    std::cout << "S4_2: " << sizeof(S4_2) << endl;
    std::cout << "S4_3: " << sizeof(S4_3) << endl;
    std::cout << "S4_4: " << sizeof(S4_4) << endl;
    std::cout << "S5: " << sizeof(S5) << endl;
    std::cout << "S6: " << sizeof(S6) << endl;
}