/*
 * 17. 电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按
任意顺序返回。 给出数字到字母的映射如下（与电话按键相同）。注意 1
不对应任何字母。

示例：

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
示例 2：

输入：digits = ""
输出：[]
示例 3：

输入：digits = "2"
输出：["a","b","c"]
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
   public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ret;
        if (digits == "")
        {
            return ret;
        }

        int size = digits.size();
        unordered_map<char, string> phones{{'2', "abc"},
                                           {'3', "def"},
                                           {'4', "ghi"},
                                           {'5', "jkl"},
                                           {'6', "mno"},
                                           {'7', "pqrs"},
                                           {'8', "tuv"},
                                           {'9', "wxyz"}};

        string m;
        int m_size;
        for (int i = 0; i < size; ++i)
        {
            m = phones[digits[i]];
            m_size = m.size();
            int v_size = ret.size();
            vector<string> tmp;
            // 核心在这里,将以往的结果置换出来,再依次遍历
            tmp.swap(ret);
            for (int j = 0; j < m_size; ++j)
            {
                if (v_size == 0)
                {
                    // 这里char不能直接转成 string,需要调用特定的string构造函数.
                    ret.push_back(string(1, m[j]));
                }
                else
                {
                    for (int k = 0; k < v_size; ++k)
                    {
                        ret.push_back(tmp[k] + m[j]);
                    }
                }
            }
        }

        return ret;
    }
};

int main()
{
    Solution s;
    string digits = "23";
    auto v = s.letterCombinations(digits);
    cout << "size: " << v.size();
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << endl;
    }
}