class Solution {
public:
    int minCostToMoveChips(vector<int>& position) 
    {

        int odd = 0;
        int even = 0;

        for (int value: position)
        {

            if(value % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
        
        if(odd < even)
        {
            return odd;
        }
        
        return even;
                
    }
};
