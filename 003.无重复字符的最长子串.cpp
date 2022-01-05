/*
Using : unordered_set : count , find
        sliding windows
Input : s = "abcabcbb"
Output: 3 
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hashSet;
        int right = 0;
        int ans = 0;
        for(int i = 0 ; i < s.size(); ++i)
        {
            if(i != 0)
                hashSet.erase(s[i - 1]);
          // !hashSet.count(s[right])   ==    hashSet.find(s[right]) == hashSet.end()
            while(right<s.size() && !hashSet.count(s[right]))
            {
                hashSet.insert(s[right]);
                right++;
            }
          // right is the next index of windows ,  i is the first index of windows. So the length equals to right - i
            ans = max(ans , right - i);
        }
        return ans;
    }
};
