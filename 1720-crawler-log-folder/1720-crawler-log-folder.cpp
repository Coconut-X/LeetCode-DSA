class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int count=0;
        stack <string> stek;

        for(auto log: logs)
        {
            string temp=log;
            temp.pop_back();

            if(temp==".")
            {
                continue;
            }
            if(temp==".." )
            {
                if(stek.empty()) continue;
                count--;
                stek.pop();
                
            }
            else 
            {
                stek.push(log);
                count++;
            }
        }

        return count;
        
    }
};