#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

// vector<int> two_sum(vector<int>& nums, int target)
// {
//     vector<int>::iterator i;
//     vector<int>::iterator j;
//     vector<int> result;

//     for(i = nums.begin(); i!= nums.end()-1; ++i)
//         for(j = i+1; j != nums.end(); ++j)
//         {
//             if ((*i + *j) == target)
//             {
//                 result.push_back(i - nums.begin());
//                 result.push_back(j - nums.begin());
                
//             }
//         }

//     return result;
// }

vector<int> two_sum(vector<int>& nums, int target)
{
    unordered_map<int,int> my_hash;
    int count, key;

    for(int i=0; i<nums.size(); ++i)
    {
        my_hash[nums[i]] = i;
    }



    // for(int i = 0; i<nums.size(); ++i)
    // {
    //     auto iter = my_hash.find(target - nums[i]);
    //     if ( iter == my_hash.end()) // Can't find the key
    //     {
    //         continue;
    //     }
    //     else
    //     {
    //         if (i != iter->second)
    //             return {i, iter->second};
    //     }
    // }

    for (int i=0; i<nums.size(); ++i)
    {
        key = target - nums[i];
        if(key == nums[i]) continue;

        count = my_hash.count(key);

        if( count )
        {
            return {i, my_hash[key]};
        }
    }

    return {};
}

int main()
{
    vector<int> nums1 {2,7,11,15};

    vector<int> result;

    result = two_sum(nums1, 9);

    cout << "[ "<<result[0] << " "<<result[1] << " ]" <<endl;

    vector<int> nums2  {3,2,4};
    int target = 6;
    result = two_sum(nums2, target);
    cout << "[ "<<result[0] << " "<<result[1] << " ]" <<endl;
}