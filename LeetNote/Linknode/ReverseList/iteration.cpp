#include<iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* next, *pre=nullptr;
        ListNode* curr=head;
        while (curr)
        {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
};

void PrintListNode(ListNode* head)
{
    ListNode* next = head;
    while (next!=nullptr)
    {
        cout<<next->val<<' ';
        next = next->next;
    }
    cout<<endl;
}

int main()
{
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);

    Solution s;
    ListNode *node = s.reverseList(node1);
    PrintListNode(node);
    system("pause");
}