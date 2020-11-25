class Solution {
public:
    vector<string> my_map = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    string toMorse(const string input)
    {
        string res = "";
        for(const char my_char: input)
        {
            int temp = my_char;

            res += my_map[temp - 97];
        }
        return res;
    }
    
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        set<string> my_list;

        for(string word: words)
        {
            string current = toMorse(word);
            
            my_list.insert(current);
        }
        
        return my_list.size();
    }
};
