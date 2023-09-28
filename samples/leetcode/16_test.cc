/**
 * 最接近的三数之和
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums
中选出三个整数，使它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在恰好一个解。

示例 1：
输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。

示例 2：
输入：nums = [0,0,0], target = 1
输出：0
 
提示：
3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-104 <= target <= 104
 */

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <string>
#include <vector>

using namespace std;
int a, b, c;

class Solution
{
   public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int size = nums.size();

        int ret = 0;
        int min_diff = INT_MAX;

        int tmp_ret;
        int tmp_diff;

        for (int i = 0; i < size; ++i)
        {
            // 去掉重复的数,避免重复运行
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            // 这两句比较关键
            // left 从 i 后面开始,减少了很多重复的行为
            int right = size - 1;
            int left = i + 1;
            while (left < right)
            {
                tmp_ret = nums[left] + nums[right] + nums[i];
                tmp_diff = fabs(tmp_ret - target);
                if (tmp_diff < min_diff)
                {
                    ret = tmp_ret;
                    min_diff = tmp_diff;
                    a = nums[i], b = nums[left], c = nums[right];
                }

                if (tmp_ret > target)
                {
                    --right;
                }
                else if (tmp_ret < target)
                {
                    ++left;
                }
                else if (tmp_ret == target)
                {
                    return ret;
                }
            }
        }

        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> nums{-1, 2, 1, -4};
    int target = 1;
    cout << s.threeSumClosest(nums, target) << endl;
    cout << a << '\t' << b << '\t' << c << endl;

    priority_queue<int> p;
}