#include <iostream>
#include <vector>

using namespace std;

class Solution
{
   public:
    // 中心扩散法的原理是:
    // 先找寻连在一起的相同字母,比如 aaa,bbbb
    // 然后从上述相同字母中,向左,向右扩展.

    // 动态规划的原理就是时间换空间
    // 记录下每一个 i,j 之间的状态,如果它们是回文的
    // 则 i-1,j+1 之间也是回文字符串.

    string longestPalindrome(string s)
    {
        if (s == "")
        {
            return s;
        }

        int size = s.size();
        int maxlen = 0;
        int maxStart = 0;
        int len = 1;

        for (int i = 0; i < size; ++i)
        {
            int left = i - 1;
            int right = i + 1;
            while (left >= 0 && s[left] == s[i])
            {
                --left;
                ++len;
            }
            while (right < size && s[right] == s[i])
            {
                ++right;
                ++len;
            }
            while (left >= 0 && right < size && s[left] == s[right])
            {
                len += 2;
                --left;
                ++right;
            }
            if (len > maxlen)
            {
                maxlen = len;
                maxStart = left;
            }
            len = 1;
        }

        return s.substr(maxStart + 1, maxlen);
    }
};

int main()
{
    Solution s;
    string str = "cbbd";
    cout << "ret: " << s.longestPalindrome(str) << endl;
}