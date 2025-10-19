class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        
        unordered_map<string,bool> v;
        queue<string>q;
        q.push(s);
        v[s] = true;
        int len = s.size();
        string m = s;
        while(!q.empty()){
            string top = q.front();
            q.pop();
            m = min(m,top);
            string rot = top;
            int shift = b % len;
            if(shift > 0) rot = top.substr(len - shift) + top.substr(0, len - shift);

            string add = top;
            for(int i = 1; i < len; i+=2) add[i]  = ((add[i]-'0'+a)%10) +'0';

            if(!v[rot]){
                v[rot] = true;
                q.push(rot);
            } 
            if(!v[add]){
                v[add] = true;
                q.push(add);
            } 
        }
        return m;
    }
};