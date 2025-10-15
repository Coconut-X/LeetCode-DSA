class Solution {
public:
    int minTimeToType(string word) {
        char current = 'a';
        int time = 0;
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            int dist = abs(current - c) ;
            time+=min(dist,26-dist); //time to move
            time++; //time to type
            current = c;
        }
        return time;
    }
};