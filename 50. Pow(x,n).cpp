class Solution {
public:
    double myPow(double x, int n) {
        if(x==1)
            return 1;

        double ans = 1;

        double newn = n;
        n = abs(n);

        while(n>0) {
            int c = n&1;

            if(c==1) {
                ans = ans*x;
            }
            x = x*x;
            n = n>>1;
        }

        if(newn<0)
            return 1/ans;
        
        return ans;
    }
};
