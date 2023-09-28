#include "listNode.h"
#include <iostream>

using namespace std;

class Solution
{
   public:
    // 分解成子问题
    // 每个递归的结果,就会返回一个最小的节点,然后把所有递归的结果链接在一起.
    // 我们判断 l1 和 l2 头结点哪个更小，然后较小结点的 next
    // 指针指向其余结点的合并结果。
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }
        else if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

int main()
{
    vector<int> v1{2};
    vector<int> v2{1};

    auto l1 = vector2list(v1);
    auto l2 = vector2list(v2);

    Solution s;
    auto l3 = s.mergeTwoLists(l1, l2);
    while (l3)
    {
        cout << l3->val << '\t';
        l3 = l3->next;
    }

    cout << endl;
}