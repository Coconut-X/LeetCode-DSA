class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> score;
        int count=0;
        for(auto& op: operations)
        {
            if(op=="C"){
                count-=score[score.size()-1];
                score.pop_back();
            }
            else if(op=="D")
            {
                count+=2*score[score.size()-1];
                score.push_back(2*score[score.size()-1]);
            }
            else if(op=="+")
            {
                count+= score[score.size()-1] + score[score.size()-2];
                score.push_back(score[score.size()-1] + score[score.size()-2]);
            }
            else
            {
                score.push_back(stoi(op));
                count+=stoi(op);   
            }
        }

        return count;
        
    }
};