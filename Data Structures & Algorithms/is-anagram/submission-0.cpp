class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> values;

        for (int i = 0; i < s.size(); i++) {
            values[s[i]]++;
        }

        for (int i = 0; i < t.size(); i++) {
            values[t[i]]--;
        }

        for (auto& pair : values){
            if(pair.second > 0)
                return false;
        }
        
        return true;
    }
};