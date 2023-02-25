#include <iostream>
#include <string>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string>& strs){

    std::string prefix;
    char _c;
    bool found;

    
    for(int i=0; i<strs[0].size(); ++i){
        _c = strs[0][i];
        found = true;
        for(auto iter=strs.begin()+1; iter!= strs.end(); ++iter)
        {
            if(_c != iter->c_str()[i])
            {
                found= false;
                break;
            }
        }

        if(found == false)
        {
            break;
        }
        else{
            prefix.push_back(_c);
        }
    }

    return prefix;
}

int main()
{
    std::vector<std::string> strs;

    std::string prefix;

    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("flight");

    prefix = longestCommonPrefix(strs);

    std::cout << prefix <<std::endl;

    return 0;
}