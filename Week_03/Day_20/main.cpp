class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        if (nums.size() == 0)
        {
            return false;
        }
        
        if (nums[0] == target || nums[nums.size()-1] == target)
        {
            return true;
        }
        
        if(nums[0] < target)
        {
            for (int i =0; i< nums.size(); i++)
            {
                if(target == nums[i])
                {
                    return true;
                }
            }
        }else if (nums[0] > target && nums[nums.size() -1] > target)
        {

            for(int i = 0; i< nums.size(); i++)
            {
                if(target == nums[nums.size() - i -1])
                {
                    return true;
                }
            }
        }
            
        return false;
    }
};
