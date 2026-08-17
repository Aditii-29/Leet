class Solution {
public:
    bool isPalindrome(string curr) {
        int left = 0;
        int right = curr.length() - 1;

        while (left < right) {
            if (curr[left] != curr[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
    void solve(vector<string>& arr, vector<vector<string>>& ans, int index,
               string& curr, string& s) {
        if (index == s.length()) {
            ans.push_back(arr);
            return;
        }
        for (int i = index; i < s.length(); i++) {
            curr=s.substr(index,i-index+1);
            if (isPalindrome(curr)) {
                arr.push_back(curr);
                solve(arr, ans, i + 1, curr, s);
                arr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> arr;
        string curr = "";
        vector<vector<string>> ans;
        int index = 0;
        solve(arr, ans, index, curr, s);
        return ans;
    }
};