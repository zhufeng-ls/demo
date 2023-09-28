
#include <iostream>
#include <math.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode *next)
        : val(x)
        , next(next)
    {
    }
};

class Solution
{
   public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int num1, num2, index1, index2, num;

        num1 = num2 = index1 = index2 = 0;
        getListNumer(l1, num1, index1);
        getListNumer(l2, num2, index2);
        num = num1 + num2;

        return numToList(num);
    }

   private:
    void getListNumer(ListNode *l, int &num, int &index)
    {
        if (l == NULL)
        {
            return;
        }

        num = num + (l->val * pow(10, index++));
        getListNumer(l->next, num, index);
    }

    ListNode *numToList(int64_t num)
    {
        int val;
        ListNode *last = NULL;
        ListNode *head = NULL;
        while (num > 0)
        {
            val = num % 10;
            ListNode *node = new ListNode;
            node->val = val;
            if (last != NULL)
            {
                last->next = node;
                last = node;
            }
            else
            {
                last = node;
                head = last;
            }

            num /= 10;
        }
        return head;
    }
};

int main()
{

    ListNode node1(2);
    ListNode node2(4);
    ListNode node3(3);
    node1.next = &node2;
    node2.next = &node3;

    ListNode n1(5);
    ListNode n2(6);
    ListNode n3(4);
    n1.next = &n2;
    n2.next = &n3;

    Solution s;
    auto l = s.addTwoNumbers(&node1, &n1);

    cout << "sum ";
    while (l != NULL)
    {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
}