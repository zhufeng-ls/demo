#ifndef LISTNODE_H
#define LISTNODE_H

#include <vector>

using std::vector;

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

ListNode *vector2list(vector<int> &v1)
{
    ListNode *head = nullptr;
    ListNode *first = nullptr;
    int size = v1.size();
    for (int i = 0; i < size; ++i)
    {
        ListNode *node = new ListNode(v1[i]);
        if (head == nullptr)
        {
            first = node;
            head = first;
        }
        else
        {
            head->next = node;
            head = node;
        }
    }

    return first;
}

#endif