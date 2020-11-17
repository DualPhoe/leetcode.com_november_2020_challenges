class Solution {
public:
    
    int gcd(const int & a, const int & b) 
    {
        if (b == 0)
        return a;
        return gcd(b, a % b);
    }
    
    int lcm (const int & a, const int & b)
    {
        return (a*b)/gcd(a,b);
    }
    
    int mirrorReflection(int p, int q) 
    {
        if (p == q)
        {
            return 1;
        }
        
        int my_lcm = lcm(p,q);

        int q_temp = my_lcm/p;
        int p_temp = my_lcm/q;
        
        if (q_temp %2 == 1 )
        {
            if (p_temp %2 == 0)
            {
                return 2;
            }
            else
            {
                return 1;
            }
        }
        else //if(q_temp %2 == 0 )
        {
            if( p_temp %2 == 1)
            {
                return 0;
            }
            else
            {
                return 2;
            }
        }

        return -1;
    }
};