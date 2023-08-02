class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> cache(word1.size()+1, vector<int>(word2.size()+1, INT_MAX));

        for(int i=word2.size(); i>=0; i--) {
            cache[word1.size()][i] = word2.size() - i;
        }
        for(int i=word1.size(); i>=0; i--) {
            cache[i][word2.size()] = word1.size() - i;
        }

        for(int i=word1.size()-1; i>=0; i--) {
            for(int j=word2.size()-1; j>=0; j--) {
                if(word1[i] == word2[j]) {
                    cache[i][j] = cache[i+1][j+1];
                } else {
                    cache[i][j] = 1 + min({cache[i+1][j], cache[i][j+1], cache[i+1][j+1]});
                }
            }
        }

        return cache[0][0];
    }
};
