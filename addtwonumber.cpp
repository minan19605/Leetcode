#include <iostream>
#include <vector>
#include <memory>

//Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void output_vector(const std::vector<int> & v)
{
    std::cout << "[ ";
    for (auto i = v.begin(); i != v.end(); ++i)
        std::cout << *i << ", ";

    std::cout<<" ]"<<std::endl;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    std::vector<int> v1, v2;

    ListNode *pStart;

    for(pStart = l1; pStart != nullptr; pStart = pStart->next)
    {
        v1.push_back(pStart->val);
    }


    for(pStart = l2; pStart != nullptr; pStart = pStart->next)
    {
        v2.push_back(pStart->val);
    }

    std::vector<int> * pshort_v = &v1;
    std::vector<int> * plong_v = &v2;
    // output_vector(*plong_v);
    // output_vector(*pshort_v);
    if (v2.size() <= v1.size())
    {
        pshort_v = &v2;
        plong_v = &v1;
    }

    // output_vector(*plong_v);
    // output_vector(*pshort_v);

    
    int sum = 0;
    int carry_digit = 0;
    int mod = 0;
    //int i;
    std::vector<int> v_result;

    std::vector<int>::iterator short_i, long_i;

    for(short_i = pshort_v->begin(), long_i = plong_v->begin(); 
        short_i!= pshort_v->end(); ++short_i, ++long_i)
    {
        sum = *short_i + *long_i + carry_digit;
        carry_digit = int(sum/10);
        mod = sum % 10;
        v_result.push_back(mod);
    }

    for(; long_i != plong_v->end(); ++long_i)
    {
        sum = *long_i + carry_digit;
        carry_digit = int(sum/10);
        mod = sum % 10;
        v_result.push_back(mod);
    }

    // while (!pshort_v->empty())
    // {
    //     sum =pshort_v->back()+ plong_v->back() + carry_digit;
    //     pshort_v->pop_back();
    //     plong_v->pop_back();

    //     carry_digit = int(sum/10);
    //     mod = sum % 10;
    //     v_result.push_back(mod);
    // }

    // while(!plong_v->empty())
    // {
    //     sum =plong_v->back() + carry_digit;
    //     plong_v->pop_back();
    //     carry_digit = int(sum/10);
    //     mod = sum % 10;
    //     v_result.push_back(mod);
    // }

    if (carry_digit > 0)
    {
        v_result.push_back(carry_digit);
    }

    //std::vector<int>::iterator i_result;
    ListNode *pHead = nullptr;
    ListNode *pCurrent = nullptr;
    ListNode *pNode = nullptr;
    for(auto i_result = v_result.begin(); i_result != v_result.end(); ++i_result)
    {
        try{
            pNode = new ListNode;
        }
        catch (const std::exception& e)
        {
            std::cout<< e.what();
        }

        pNode->val = *i_result;
        pNode->next = nullptr;

        if (pHead == nullptr)
        {
            pHead = pNode;
            pCurrent = pNode;
        }
        else
        {
            pCurrent->next = pNode;
            pCurrent = pCurrent->next;
        }
    }

    return pHead;
}

void output_numbers(ListNode *pList)
{
    
    std::cout << "[ " ;
    for(ListNode *pStart = pList; pStart != nullptr; pStart = pStart->next)
    {
        std::cout << pStart->val <<", ";
    }

    std::cout<< " ]"<<std::endl;
}

int main()
{
    // l1 = [9,9,9,9,9,9,9]
    // l2 = [9,9,9,9]

    ListNode *pl1_Head = nullptr;
    ListNode *pl2_Head = nullptr;
    ListNode *pCurrent = nullptr;

    for(int i= 0; i<7; ++i)
    {
        ListNode *pNode = new ListNode ;
        pNode->val = 9;
        pNode->next = nullptr;

        if (pl1_Head == nullptr)
        {
            pl1_Head = pNode;
            pCurrent = pNode;
        }
        else
        {
            pCurrent->next = pNode;
            pCurrent = pCurrent->next;
        }
    }

    output_numbers(pl1_Head);

    for(int i= 0; i<4; ++i)
    {
        ListNode *pNode = new ListNode ;
        pNode->val = 9;
        pNode->next = nullptr;

        if (pl2_Head == nullptr)
        {
            pl2_Head = pNode;
            pCurrent = pNode;
        }
        else
        {
            pCurrent->next = pNode;
            pCurrent = pCurrent->next;
        }
    }

    output_numbers(pl2_Head);

    ListNode* pResult= addTwoNumbers( pl1_Head, pl2_Head);

    // std::cout << "[ " ;
    // for(ListNode *pStart = pResult; pStart->next != nullptr; pStart = pStart->next)
    // {
    //     std::cout << pStart->val <<", ";
    // }

    // std::cout << "]"<<std::endl;

    output_numbers(pResult);
}
