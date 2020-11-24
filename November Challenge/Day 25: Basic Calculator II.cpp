#include<bits/stdc++.h>
class Solution {
public:
    int Operation(char ch,int o1,int o2)
    {
        switch(ch)
        {
            case '+' : return o1+o2;
                       break;
            case '-' : return o1-o2;
                        break;
            case '/' : return o1/o2;
                        break;
            case '*' : return o1*o2;
                        break;
            default : return 0;
                        break;
        }
    }
    int getPrecedence(char ch)
    {
        if(ch == '/' || ch == '*')
            return 1;
        return 0;
    }
    int calculate(string s) {
        int i,j,k,n;
        n = s.size();
        stack<int> operands;
        stack<char> operators;
        if(n == 0)
            return 0;
        for(i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                string num;
                while(i<n && isdigit(s[i]))
                {
                    num += s[i];
                    i++;
                }
                i--;
                operands.push(stoi(num));
            }
            else if(s[i] != ' ')
            {
                while(!operators.empty() && getPrecedence(s[i]) <= getPrecedence(operators.top()))
                {
                    char ch = operators.top(); operators.pop();
                    j = operands.top();  operands.pop();
                    k = operands.top();  operands.pop();
                    operands.push(Operation(ch,k,j));
                }
                operators.push(s[i]);
            }
        }
        while(!operators.empty())
        {
            char ch = operators.top(); operators.pop();
            j = operands.top();  operands.pop();
            k = operands.top();  operands.pop();
            operands.push(Operation(ch,k,j));
        }
        int ans = operands.top();  operands.pop();
        return ans;
    }
};
