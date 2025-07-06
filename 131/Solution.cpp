class Solution {

    vector<vector<string>> ans;
    vector<string> strs;
    int n;
public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        backtrace(s,0);
        return ans;
    }

    void backtrace(string &s , int index){

        if (index == n){
            ans.push_back(strs);
            return;
        }


        for (int right = index ; right < n ; right++){
            if (isPalindrome(s,index,right)){
                strs.push_back(s.substr(index,right-index+1));
                backtrace(s,right + 1);
                strs.pop_back();
            }
        }
    }
private:
    bool isPalindrome(string &s , int left , int right){
        while (left <= right){
            if (s[left++] != s[right--]){
                return false;
            }
        }
        return true;
    }
};