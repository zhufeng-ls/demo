#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution
{
   public:
    // 核心原理是, first 在 second 前, first 在 second 后,两种情况的最大值比较.
    // a
    int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen)
    {
        int size = nums.size();
        int first_max, second_max, max;
        first_max = second_max = max = 0;

        for (int i = 0; i < size - firstLen; ++i)
        {
            first_max = std::accumulate(
                nums.begin() + i, nums.begin() + i + firstLen, 0);
            second_max = findMaxSection(nums, i + firstLen, secondLen);

            max = std::max(max, first_max + second_max);
        }

        return max;
    }

   private:
    // c++ 20 可以用 std::accumulate 代替
    int sumInSection(vector<int> &nums, int &start, int &length)
    {
        int sum = 0;
        int end = start + length;
        for (int i = start; i < end; ++i)
        {
            sum += nums[i];
        }
        return sum;
    }

    int findMaxSection(vector<int> &nums, int start, int length)
    {
        int max = 0;
        int size = nums.size();
        int bound = size - length;
        for (int i = start; i <= bound; ++i)
        {
            max = ::max(max, sumInSection(nums, i, length));
        }

        return max;
    }
};

int main()
{
    std::vector<int> nums{2, 1, 5, 6, 0, 9, 5, 0, 3, 8};
    int firstLen = 4;
    int secondLen = 3;

    Solution s;
    int max1 = s.maxSumTwoNoOverlap(nums, firstLen, secondLen);
    int max2 = s.maxSumTwoNoOverlap(nums, secondLen, firstLen);
    cout << "max: " << std::max(max1, max2) << endl;
}