class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact, digits;

        fact.push_back(1);
        int f = 1;
        for(int i=1; i<n; i++) {
            f *= i;
            fact.push_back(f);
        }

        for(int i=0; i<n; i++) {
            digits.push_back(i);
        }

        string ans = "";
        solve(fact, digits, ans, n, k);

        return ans;
    }

    void solve(vector<int>& fact, vector<int>& digits, string& ans, int n, int k) {
        if(n == 1) {
            ans +=  (char)('0' + digits.back() + 1);
            return;
        }

        int idx = k / fact[n-1];

        if(k % fact[n-1] == 0) {
            idx -= 1;
        }

        ans += (char) ('0' + digits[idx] + 1);
        digits.erase(digits.begin()+idx);

        k -= fact[n-1] * idx;
        solve(fact, digits, ans, n-1, k);
    }
};
