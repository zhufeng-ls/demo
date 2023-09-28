#include <iostream>
#include <vector>

using namespace std;

class Solution
{
   public:
    string convert(string s, int numRows)
    {
        if (s == "")
        {
            return "";
        }

        if (numRows == 1)
        {
            return s;
        }

        int size = s.size();
        vector<vector<char>> ves;
        for (int i = 0; i < numRows; ++i)
        {
            ves.emplace_back(vector<char>());
        }
        ves[0].emplace_back(s[0]);
        int n = size;
        int index = 1;
        bool reverse = false;
        while (index < n)
        {
            // 关键点就在这里, 一定要判断 index  < n, 否则会越界一次
            // 这个越界 leetcode 并没有报错.
            for (int i = 1; i < numRows && index < n; ++i)
            {
                if (reverse)
                {
                    ves[numRows - 1 - i].emplace_back(s[index]);
                }
                else
                {
                    ves[i].emplace_back(s[index]);
                }
                ++index;
            }
            reverse = !reverse;
        }
        std::string ss = "";
        for (int i = 0; i < numRows; ++i)
        {
            for (auto it = ves[i].begin(); it != ves[i].end(); ++it)
            {
                ss += *it;
            }
        }

        return ss;
    }
};

int main()
{
    Solution s;
    string str = "PAYPALISHIRING";
    cout << "convert: " << s.convert(str, 3) << endl;
}