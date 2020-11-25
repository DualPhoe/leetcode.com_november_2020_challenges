class Solution {
public:
    int longestMountain(vector<int>& A) 
    {
        if(A.size() <= 2)
        {
            return 0;
        }

        int max =0;
        

        bool passed_summit = false;

        
        int begin =0;
        
        int prev    = A[0];
        int cur     = A[1];
        
        for(int i =1; i<A.size() -1; i++ )
        {
            int next    = A[i+1];
            
            if(prev < cur && cur > next && ! passed_summit)
            {
                passed_summit = true;

            }
            else if(prev > cur && cur < next )
            {
                if(passed_summit)
                {
                    int temp_distance = i - begin + 1;
                    if(temp_distance > max)
                    {
                        max = temp_distance;
                    }
                    passed_summit = false;
                }

                begin = i;
            }
            
            if(prev == cur && cur < next)
            {
                begin = i;
            }
            else if( prev > cur && cur == next)
            {
                if(passed_summit)
                {
                    int temp_distance = i - begin + 1;
                    if(temp_distance > max)
                    {
                        max = temp_distance;
                    }
                    passed_summit = false;
                }
            }
            
            if(i == A.size()-2 && passed_summit)
            {
                if( prev < cur && cur > next)
                {
                    int temp_distance = i - begin + 2;
                    if (temp_distance > max)
                    {
                        max = temp_distance;
                    }
                }
                else if(prev > cur && cur > next)
                {
                    int temp_distance = i - begin + 2;
                    if (temp_distance > max)
                    {
                        max = temp_distance;
                    }
                }
            }

            prev = cur;
            cur = next;
            
        }
       
        
        return max;
        
    }
};
