#include <iostream>
#include <stack>
#include <string>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<int> openBrackets;
        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case '(':
                // open parens
                openBrackets.push(1);
                break;
            case '[':
                // open brackets
                openBrackets.push(2);
                break;
            case '{':
                // open curly bracket
                openBrackets.push(3);
                break;
            case ')':
                if (openBrackets.empty() || openBrackets.top() != 1)
                    return false;
                openBrackets.pop();
                break;
            case ']':
                if (openBrackets.empty() || openBrackets.top() != 2)
                    return false;
                openBrackets.pop();
                break;
            case '}':
                if (openBrackets.empty() || openBrackets.top() != 3)
                    return false;
                openBrackets.pop();
                break;
            }
        }
        if (openBrackets.empty())
            return true;
        return false;
    }
};

int main()
{
    Solution solution;
    std::cout << solution.isValid("()") << std::endl;
    std::cout << solution.isValid("(]") << std::endl;
    std::cout << solution.isValid("()[]{}") << std::endl;
    std::cout << solution.isValid("(){}[{}]") << std::endl;
    return 0;
}