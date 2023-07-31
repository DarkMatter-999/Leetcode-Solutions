class Solution {
public:
    int myAtoi(string s) {
        double res = 0;

        int size = s.size();
        int i = 0;
        while(s[i] == ' ') {
            i++;
        }

        bool pos = false, neg = false;
        if (s[i] == '+') {
            pos = true;
            i++;
        }
        if (s[i] == '-') {
            neg = true;
            i++;
        }

        if(pos == true && neg == true) {
            return 0;
        }

        while (i < size && s[i] >= '0' && s[i] <= '9') {
            res = res * 10 + (s[i] - '0');
            i++;
        }

        if (neg) {
            res = -res;
        }
        
        if(res > INT_MAX) {
            return INT_MAX;
        }

        if(res < INT_MIN) {
            return INT_MIN;
        }
        
        return (int)res;
    }
};

