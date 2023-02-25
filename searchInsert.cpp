#include <iostream>
#include <vector>
#include <set>

using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    int len = nums.size();
    if (target < nums[0]) return 0;
    if (target > nums[len-1]) return len;

    int low = 0;
    int high = len-1;
    int mid = (low+high) / 2;

    while(low < high)
    {
        if(nums[mid] == target) return mid;

        if(nums[mid] < target) low = mid +1 ;
        else high = mid - 1;

        mid = (low + high) / 2;
    }

    if(nums[low] < target) return low+1;
    else return low;

}

int main()
{
    vector<int> l1 {1,3,5,6};
    int target = 5;
 
    int ret = searchInsert(l1, 5);

    std::cout << "Ret loc is "<<ret<<std::endl;

    target = 7;
    ret = searchInsert(l1, target);

    std::cout << "Ret loc is "<<ret<<std::endl;

    target = -1;
    ret = searchInsert(l1, target);

    std::cout << "Ret loc is "<<ret<<std::endl;

    target = 2;
    ret = searchInsert(l1, target);

    std::cout << "Ret loc is "<<ret<<std::endl;

    return 0;
}