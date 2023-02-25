#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;



int removeElement(vector<int>& nums, int val)
{
    // vector<int> dst;

    // for(auto iter = nums.begin(); iter!= nums.end(); ++iter)
    // {
    //     if(*iter != val) dst.push_back(*iter);
    // }

    // std::copy(dst.begin(), dst.end(), nums.begin());

    // return dst.size();

    // faster, but tricky.
    for(auto iter = nums.begin(); iter != nums.end(); )
    {
        if(*iter == val) nums.erase(iter);
        else ++iter; // be careful for this one.
    }

    return nums.size();
}

int main()
{
    int ret;
    vector<int> v_1 {3,2,2,3};
    

    ret = removeElement(v_1, 3);

    for(int i=0; i< ret; ++i)
    {
        cout<<v_1[i] << " ";
    }

    return 0;
}