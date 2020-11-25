class Solution {
public:
    int maxPower(string s) {
        int result =0;
        
        if(s.size() <2)
        {
            return s.size();
        }
        
        result = 1;
        int max =1;
        char previous_char = s[0];
                
        for (int i =1; i< s.size(); i ++)
        {
            char temp = s[i];
            if(previous_char == temp)
            {
                max ++;
            }
            else
            {

                max = 1;
            }  
            
            if(max > result )
            {
                result = max;
            }
            
            previous_char = temp;
        }
        
        return result;
    }
};
