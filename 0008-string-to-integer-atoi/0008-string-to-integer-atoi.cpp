class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long long int num = 0;
        bool mark = false;
        bool getting = false;

        for(int i = 0;i < n;i++){
            if(s[i] == ' ' && getting == false) continue;

            else if(s[i] == ' ' && getting == true) break;

            else if(s[i] == '-' && getting == false) {
                mark = true;
                getting = true;
            }

            else if(s[i] == '+' && getting == false) getting = true;

            else if((s[i] == '-' || s[i] == '+') && getting == true) break;

            else if(isdigit(s[i])){

                int a = s[i] - '0';
                if(num > (INT_MAX - a) / 10) {
                    return mark ? INT_MIN : INT_MAX;
                }

                if(getting == false) getting = true;
                num *= 10;
                num += a;
            }
            
            else break;
        }

        if(mark){
            cout<<num;
            num *= -1;
        }

        return num;
    }
};