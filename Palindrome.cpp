#include <iostream>

using namespace::std;

bool isPalindrome(int x)
{
    if(x < 0) return false;

    if(x==0) return true;

    long y = 0;
    int tmp = x;
    while(tmp){
        y += tmp % 10;
        tmp /= 10;
        if(tmp)
            y *=10;
        
    }

    if(y == x) return true;

    return false;
}

int main()
{
    int x = 121;
    
    bool r = isPalindrome(x);

    if(r)
    {
        cout << x << " is Palindrome "<<endl;
    }

    return 0;
}