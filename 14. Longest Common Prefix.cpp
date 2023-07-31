class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        int n = strs.size();
        sort(strs.begin(), strs.end());
        string first = strs[0] , last = strs[n - 1];

        for(int i=0; i<min(first.length(), last.length()); i++) {
            if (first[i] != last[i]) {
                break;
            } else {
                ans += first[i];
            }
        }

        return ans;   
    }
};
