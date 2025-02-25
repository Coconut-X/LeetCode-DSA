class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        int count=students.size();

        queue<int> q, sand;

        for(auto s: students)
            q.push(s);
        
        for(auto t: sandwiches)
            sand.push(t);

        int cur=0;

        while(sand.size() and q.size())
        {
            if(sand.front()==q.front())
            {
                cur=0;
                count--;
                q.pop();
                sand.pop();
                if(q.empty()) 
                    return 0;
            }
            else
            {
                cur++;
                q.push(q.front());
                q.pop();
            }
            if(cur==q.size())
                return count;
        }
        
        return count;
    }
};