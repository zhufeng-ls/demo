#include <iostream>
#include <limits.h>
#include <math.h>
#include <vector>

using namespace std;

class Solution
{
   public:
    int reverse(int x)
    {
        if (x == INT_MIN || x == INT_MAX)
        {
            return 0;
        }
        int y = x;
        if (x < 0)
        {
            y = -x;
        }

        int ret = 0;
        int64_t tmp = 0;
        while (y > 0)
        {
            tmp = (int64_t)ret * 10 + (y % 10);
            if (tmp > pow(2, 31) - 1)
            {
                return 0;
            }
            ret = tmp;
            y /= 10;
        }

        if (x < 0)
        {
            tmp = -tmp;
        }

        return tmp;
    }
};
int main()
{
    Solution s;
    cout << s.reverse(-2147483648) << endl;
}