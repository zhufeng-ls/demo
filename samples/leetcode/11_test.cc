#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
   public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        // 为了避免中间出现两个特长的值的情况,所以,必须要遍历完毕
        while (l < r)
        {
            int area = min(height[l], height[r]) * (r - l);
            ans = max(ans, area);
            // 移动值较小的那一端,并将移动后的面积做比较
            // 就算移动后的面积比较小,也要继续移动,因为有可能中间出现, 100,101
            // 这样的情况
            if (height[l] <= height[r])
            {
                ++l;
            }
            else
            {
                --r;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> height{2, 3, 4, 5, 18, 17, 6};
    Solution s;
    cout << s.maxArea(height) << endl;
}