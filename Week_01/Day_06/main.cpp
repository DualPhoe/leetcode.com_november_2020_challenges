class Solution {
public:
    int my_div(const int & a, const int & b)
    {
        int res = a / b;
        if(a % b != 0)
        {
            res ++;
        }
        
        return res;
    }
    
    unsigned cal_value(const vector<int> &  nums , const int & div)
    {
        unsigned res =0;
        for (const int value : nums)
        {
            
            // res += my_div(value, div);
            res += ((value/ div) + 1);
            if (value%div == 0)
            {
                res--;
            }
        }
        
        // cout<< "debug: " << res << endl;
        return res;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        bool run = true;
        unsigned i=1;
        
        unsigned up = cal_value(nums, i);
        
        if (up <= threshold)
        {
            return 1;
        }
        
        unsigned down = 1;
        while(up > down)
        {
            i = (up + down) /2;
            // cout << "i: " << i <<endl;
            // cout << "up: " << up << "\tdown: " << down << endl;
            

            int temp_sum = cal_value(nums, i);
            
            if(temp_sum <= threshold)
            {
                up = i;
            }
            else
            {
                down = i;
            }
            
            if(up -1 == down)
            {
                return up;
            }
        }
        
        return i;
    }
};
