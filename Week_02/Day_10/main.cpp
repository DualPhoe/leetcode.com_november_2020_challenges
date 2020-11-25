class Solution {
public:

    int invert(const int & input)
    {
        if(input == 1)
        {
            return 0;
        }
        return 1;
    }
    
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) 
    {
        int size = A.size();
        cout << size << endl;
        for( vector<int> & a_row : A)
        {
            int i =0;
            for(int i = 0; i <= (size /2); i++ )
            {
                if(i< (size/2))
                {
                    int temp =invert (a_row[i]);
                    a_row[i] = invert(a_row[size-1 -i]);
                    a_row[size-1 -i] = temp;
                }
                
                else if ((size%2 ==1) && (i == (size/2)) ) 
                {
                    a_row[i] = invert( a_row[i] );
                }
            }

        }
        
        return A;
    }
};
