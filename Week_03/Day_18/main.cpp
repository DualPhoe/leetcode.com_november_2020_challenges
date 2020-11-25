#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {   
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res = {intervals[0]};
        
        for(int i = 1; i < intervals.size(); i++) 
        {
            if(intervals[i][0] > res[res.size()-1][1]) 
            {
                res.push_back(intervals[i]);
            }
            else 
            {
                vector<int> merged = {res[res.size()-1][0], max(res[res.size()-1][1], intervals[i][1])};
                res.pop_back();
                res.push_back(merged);
            }
        }

        return res;
    }
};