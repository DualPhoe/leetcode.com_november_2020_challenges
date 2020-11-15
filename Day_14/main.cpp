#include <iostream>

using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) 
    {
        if(buckets <= 1)
        {
            return 0;
        }
        
        int number_of_buckets = 0;
        int number_of_pig = 0;
        int number_of_test = minutesToTest / minutesToDie;
        while (number_of_buckets < buckets)
        {
            number_of_pig++;
            number_of_buckets = pow( number_of_test +1 , number_of_pig);
        }
        
        return number_of_pig;
    }
};