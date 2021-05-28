class Solution {
public:
    int myAtoi(string s) {
        while(s[0] == ' ') s.erase(s.begin());
        
        bool flag = false;
        if(s[0] == '-' ){
            flag = true;
            s.erase(s.begin());
        }
        
        else if(s[0]=='+')
            s.erase(s.begin());
        int res = 0;
        int i = 0;
        while(s[i] >= '0' && s[i] <= '9'){
            if(res > INT_MAX/10 || (res == INT_MAX/10 && s[i] - '0' > 7))
                return flag ? INT_MIN : INT_MAX;
            res = (int)(res * 10) + (s[i] - '0');
            i++;
        }
        return flag ? res*-1 : res;
    }
};