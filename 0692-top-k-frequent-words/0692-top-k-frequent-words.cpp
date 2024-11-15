class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int> freq ; 
        for (string &i : words) {
            freq[i]++ ;
        }
        int n = freq.size() ; 
      
        vector<set<string>> f(n + 1) ; 
        for (string &s : words) {
            f[freq[s]].insert(s) ;
        }
        vector<string> ans ;
    for (int i = n ; i >= 1 && (int)ans.size() < k ; i--) {
            for (string j : f[i]) {
                ans.push_back(j) ; 
                if ((int)ans.size() == k) {
                    break ;
                }
            }
        }
        return ans ; 
	}
};