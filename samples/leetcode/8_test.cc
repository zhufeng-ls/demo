#include <iostream>
#include <limits.h>
#include <string>

using namespace std;

class Solution
{
   public:
    int myAtoi(string s)
    {
        int64_t ret = 0;
        bool direction = true;
        bool started = false;
        int i = 0;
        int size = s.size();

        for (; i < size; ++i)
        {
            if (s[i] != ' ')
            {
                break;
            }
        }

        if (i < size)
        {
            if (s[i] == '-')
            {
                direction = false;
                ++i;
            }
            else if (s[i] == '+')
            {
                direction = true;
                ++i;
            }
        }

        for (; i < size; ++i)
        {

            if (s[i] < '0' || s[i] > '9')
            {
                break;
            }

            ret = ret * 10 + (s[i] - '0');
            if (ret > INT_MAX)
            {
                if (direction)
                {
                    return INT_MAX;
                }
                else
                {
                    if (-ret < INT_MIN)
                    {
                        return INT_MIN;
                    }
                }
            }
        }

        return direction ? ret : -ret;
    }
};

int main()
{
    Solution s;
    string str = "   -42";
    cout << s.myAtoi(str) << endl;
}