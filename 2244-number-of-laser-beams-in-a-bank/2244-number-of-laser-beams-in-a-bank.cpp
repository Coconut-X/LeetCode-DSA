class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> beams;

        for(auto &s: bank){
            int freq = count(s.begin(), s.end(), '1');
            if(freq) beams.push_back(freq);
        }
        if(beams.size() < 2) return 0;

        long long total = 0;
        for(int i = 0; i < beams.size() - 1; i++)
            total+=beams[i]*beams[i+1];
        
        return total;
    }
};