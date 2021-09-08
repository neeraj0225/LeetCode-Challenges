class Solution {
public:
     long long int toInt(string str){
        int n = str.length()-1;
         long long int result=0;
        for(char s : str){
             long long int temp = s - '0';
            result += temp * (pow(10,n--));
        }
        return result;
    }
    
    int myAtoi(string s) {
        bool numFlag = false,signSet=false,leadZero=false;
        int sign = 1;
        string num;
        for(char str : s){
            if(str == ' ' && !numFlag){
                if(signSet){
                    break;
                }
                if(leadZero)
                    break;
                continue;
            }
            else if(str == '0' && !numFlag)
            {
                leadZero = true;
                signSet = true;
                continue;
            }
            else if((str == '+' || str == '-')){
                if(numFlag)
                    break;
                else if(signSet)
                    break;
                else {
                    signSet = true;
                    if(str == '-')
                        sign = -1;
                }
            }
            else if(str >= '0' && str <= '9'){
                if(!numFlag)
                    numFlag = true;
                num.push_back(str);
            }
            else{
                break;
            }
        }
        if(numFlag)
        {
            if(num.length() > 10)
            {
                if(sign < 0)
                    return INT_MIN;
                return INT_MAX;
            }
            else {
               long long int result = toInt(num);  
                if(result > INT_MAX){
                    if(sign < 0)
                        return INT_MIN;
                    return INT_MAX;
                }
                else {
                    int res = sign * ((int)result);
                    return res;
                }
            }
        }
        else {
            return 0;
        }
    }
};
