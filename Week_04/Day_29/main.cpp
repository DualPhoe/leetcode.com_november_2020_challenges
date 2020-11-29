class Solution {
    
    bool dfs(const vector<int>& arr,const int & start,const int & pos)
     {
        if(start < 0 || start >= arr.size()) 
        {
            return false;
        }
        
        if(arr[start] == 0)
        {
            return true;
        }
         
        if(pos >= arr.size()) 
        {
            return false;
        }

        
        return (dfs(arr, start + arr[start], pos + 1)) || (dfs(arr, start - arr[start], pos + 1)) ;

    }
    
public:
    
    bool canReach(vector<int>& arr, int start) 
    {
        return dfs(arr, start, 0);
    }
};
