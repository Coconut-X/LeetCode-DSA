class Solution {
public:
    int minPartitions(string n) {
        for(auto& c:n) n[0] = max(n[0],c);
        return n[0]-'0';
    }
};