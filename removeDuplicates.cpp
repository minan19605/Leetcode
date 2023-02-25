#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// work, simple but slow, memory consume
// int removeDuplicates(vector<int>& nums) {
//     set<int> myset(nums.begin(), nums.end());

//     std::copy(myset.begin(), myset.end(), nums.begin());

//     return myset.size();
// }

void output(const vector<int> &v)
{
    cout<<"[ ";
    std::for_each(v.begin(),v.end(), [](int x){cout<<x<<", ";});

    cout<<"]"<<endl;
}

int removeDuplicates(vector<int>& nums){

    int size = nums.size();

    if(size == 0 || size == 1) return size;

    int i = 0;
    int count = 1; // At least return 1
    int k = 1;

    while(--size)
    {
        output(nums);
        if(nums[k] == nums[i]) // like 1,1,1
        {
            nums[i] = nums[k];
            ++ k;
            continue;
        }

        // 1,1,1,2,3,
        // or 1,2,3,
        ++i;
        nums[i] = nums[k];
        ++ k;
        ++ count;

    }

    return count;
}

int main()
{
    vector<int> nums {1,1,1,2,3,3,3,4,5,6,7,7,7,7,8,9};

    removeDuplicates(nums);

    return 0;
}