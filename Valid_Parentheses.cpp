#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool ifmatch(char a, char b)
{
    switch(a)
    {
        case '(': if(b == ')') return true; else return false;
        case '{': if(b == '}') return true; else return false;
        case '[': if(b == ']') return true; else return false;
        default:
            return false;
    }
}

bool isValid(string s){
    // char left_parentheses = '(';
    // char right_parentheses = ')';

    // char left_curly_braces = '{';
    // char right_curly_braces = '}';

    // char left_square_brackets = '[';
    // char right_square_brackets = ']';


    stack<char> parentheses;

    char _input = s[0];
    char _top;

    if(s.size() % 2) return false; // str length is odd

    // if(_input != left_parentheses && _input != left_curly_braces && _input!= left_square_brackets) return false;
    // parentheses.push(_input);

    for(auto iter=s.begin(); iter!= s.end(); ++iter)
    {
        _input = *iter;
        if(parentheses.empty())
        {
            parentheses.push(_input);
            continue;
        }
        else
            _top = parentheses.top();

        if(ifmatch(_top, _input)) // input and top is match
        {
            parentheses.pop();
        }
        else //the last symbol is right
        {
            parentheses.push(_input);
        }
    }

    return parentheses.empty();
}

int main()
{
    string s1 = "{[]}()";

    cout<< s1 <<" is " << isValid(s1) <<endl;
    return 0;
}