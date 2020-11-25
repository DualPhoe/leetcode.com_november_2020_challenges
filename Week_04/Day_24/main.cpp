class Solution {
public:
    
    string Remove_space (string input)
    {
        string res = "";
        
        for(int i =0; i<input.size(); i++)
        {
            if(input[i] != ' ')
            {
                res += input[i];
            }
        }
        
        return res;
    }
    
    int calculate(string s) 
    {
        if(s.size()== 0)
        {
            return 0;
        }
        
        s = Remove_space(s);
        
        
        set<char> numbers = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        stack<int> ns;
        int res=0;
        int index = 0;
        char op='+';
        
        int i=0;
        long cal=0;
        while (i<s.length())
        {
            if (numbers.count(s[i]) != 0)
			{
				cal = s[i] - 48;
				while (numbers.count(s[i + 1]) != 0)
				{
					cal = cal * 10 + s[i + 1] - 48;
					i++;
				}
                
                if (op=='+') 
                {
                    ns.push(cal);
                }
                else if (op=='-') 
                {
                    ns.push(-1*cal);
                }
                else if (op=='*')
                {
                    int a=ns.top(); ns.pop(); ns.push(a*cal);
                }
                else if (op=='/')
                {
                    int a=ns.top(); ns.pop(); ns.push(a/cal);
                }
			}
            else if (s[i]=='-') op='-';
            else if (s[i]=='+') op='+';
            else if (s[i]=='*') op='*';
            else if (s[i]=='/') op='/';
            i++;
        }
        while (!ns.empty())
        {
            res=res+ns.top();
            ns.pop();
        }
        return res;

    }
};
