#include <map>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

static map<int, vector<int>> mv = 
{
    {1, {1,2,3}},
    {2, {2,3,4,5}},
    {3, {3,4,5,6}},
    {10, {10,9,8,7,6}}
};


void test_map1()
{
    auto& vec = mv[1];
    vec.push_back(4);
    mv[1] = vec;
    auto vec1 = mv[1];
    int n = vec1.size();
    cout << "numbers: ";
    for (int i = 0; i < n; ++i)
    {
        cout << vec1[i] << " ";
    } 
    cout << endl;
}

void test_map2()
{
    mv[4] = {2,2,2,3};
    auto vec1 = mv[4];
    int n = vec1.size();
    cout << "numbers: ";
    for (int i = 0; i < n; ++i)
    {
        cout << vec1[i] << " ";
    } 
    cout << endl;
}

int main()
{
    test_map2();
}