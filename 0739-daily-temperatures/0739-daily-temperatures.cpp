class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int s=temperatures.size();
        vector <int> h(s,0);
        stack  <int> stek;

        for(int i=s-1;i>=0;i--)
        {
            int line=0;

            while (!stek.empty() && temperatures[stek.top()] <= temperatures[i])
                stek.pop();

            h[i] = stek.empty() ? 0 : stek.top() - i;
            stek.push(i);

        }

        return h;
    }
};