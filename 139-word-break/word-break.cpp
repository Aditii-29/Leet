class Solution {
public:
    bool helper(vector<int>&dp,string& s, vector<string>& wordDict, int index, int n) {
        if (index == n) {
            return true;
        }
        for (int i = index; i <= n - 1; i++) {
            string currentWord = s.substr(index, i - index + 1);
            if (find(wordDict.begin(), wordDict.end(), currentWord) !=
                wordDict.end()&& dp[i]!=1) {
                    dp[i]=1;
                if (helper(dp,s, wordDict, i + 1, n)) {
                    return true;
                }
            }
            
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int index = 0;
        int n = s.length();
        vector<int>dp(n+1,-1);
        
        return helper(dp,s, wordDict, index, n);
    }
};