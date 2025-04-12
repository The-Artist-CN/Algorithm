class Solution {
public:
    char findTheDifference(string s, string t) {
        int ret = 0;
        for (char ch: s) {
            ret ^= ch;
        }
        for (char ch: t) {
            ret ^= ch;
        }
        return ret;
    }
    char findTheDifferenceUseUnordered_map(string s, string t) {
        unordered_map<char,int> m;
        for(int i=0;i<t.size();i++){
            m[t[i]]+=1;
            
        }
        for(int i=0;i<s.size();i++){
            m[s[i]]--;
            
        }
        char c;
        for(int i=0;i<t.size();i++){
            if(m[t[i]]==1){
                c=t[i];
            }
            
        }
        return c;
    }
};

