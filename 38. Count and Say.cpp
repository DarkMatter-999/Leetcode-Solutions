class Solution {
public:
    string build(string s) {
        string res = "";
        char curr = s[0];
        int count = 1;

        for(int i=1; i<s.length(); i++) {
            if(curr == s[i]) {
                count++;
            } else {
                res.push_back('0' + count);
                res.push_back(curr);

                curr = s[i];
                count = 1;
            }
        }

        res.push_back('0' + count);
        res.push_back(curr);
    
        return res;
    }
    string countAndSay(int n) {
        string str = "1";

        for(int i=0; i<n-1; i++ ) {
            str = build(str);
        }

        return str;
    }
};
