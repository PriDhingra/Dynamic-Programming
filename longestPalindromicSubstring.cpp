class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int lc = 0;
        
        for(int i = 0;i < s.length();i++) {
            int left = i;
            int right = i;
            while(left >= 0 && right < s.length() && s[left] == s[right]) {
                if(right - left + 1 > lc) {
                    res = s.substr(left, right + 1 - left);
                    lc = right - left + 1;
                }
                left--;
                right++;
            }
            
            
            
            left = i;
            right = i + 1;
            while(left >= 0 && right < s.length() && s[left] == s[right]) {
                if(right - left + 1 > lc) {
                    res = s.substr(left, right + 1 - left);
                    lc = right - left + 1;
                }
                left--;
                right++;
            }
        }
        
        return res;
    }
};
