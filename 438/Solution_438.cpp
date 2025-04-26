class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> scount(26);
        vector<int> pcount(26);
        vector<int> reslut;
        if (s.length() < p.length())
            return {}; // p 比 s 长，直接返回空
        for (char pstr:p){
            pcount[pstr-'a']++;
        }
        int left = 0;
        for(int right = 0 ; right < s.length();right++){
             scount[s[right]-'a']++;

            if(right-left+1 == p.length()){
                if(scount == pcount) reslut.push_back(left);
                scount[s[left]-'a']--;
                left++;
            }
           
        }
        return reslut;
    }
};
