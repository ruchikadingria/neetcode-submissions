class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> val;
        for(int i = 0; i < strs.size(); i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());
            val[str].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for(auto i : val)
        {
            result.push_back(i.second);
        }

        return result;
    }
};