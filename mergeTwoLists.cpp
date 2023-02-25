#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    vector<int> v1;
    int l1_len=0, l2_len=0;

    ListNode *p;
    for(p = list1; p!=nullptr; p = p->next, ++l1_len)
    {
        v1.push_back(p->val);
    }


    for(p = list2; p!= nullptr; p=p->next, ++l2_len)
    {
        v1.push_back(p->val);
    }

    if(v1.size() == 0) return nullptr;

    std::sort(v1.begin(),v1.end());

    if(list1 == nullptr) p= list2;
    else p = list1;
    //ListNode *p_pre = list1;

    int total_len = l1_len + l2_len;

    for(auto iter=v1.begin(); iter!=v1.end(); ++iter, -- total_len)
    {
        p->val = *iter;
        if(p->next == nullptr && list1 != nullptr && total_len > l2_len) p->next = list2;
        p = p->next;
    }

    return list1 != nullptr? list1:list2; 

}

int main()
{
    ListNode *pl1, *pl2, *p;

    p = new ListNode;
    p->val = 1;
    p->next = new ListNode;

    pl1 = p;
    p = p->next;

    p->val = 2;
    p->next = new ListNode;
    p = p->next;

    p->val = 4;
    p->next = nullptr;

    p = new ListNode;
    p->val = 1;
    p->next = new ListNode;

    pl2 = p;
    p = p->next;

    p->val = 3;
    p->next = new ListNode;
    p = p->next;

    p->val = 4;
    p->next = nullptr;

    p = mergeTwoLists(pl1,pl2);

    return 0;
}