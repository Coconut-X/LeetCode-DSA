class Solution {
public:

    int sub(vector<int>&nums, int k, int xx, int x){
        unordered_map<int,int> freq;
        priority_queue<pair<int,int>> pq;

        for(int i = x; i < x + k; i++) freq[nums[i]]++;
        for(int i = x; i < x + k; i++) pq.push({freq[nums[i]],nums[i]});

        int t = 1, sum = 0;

        while(t<=xx and !pq.empty()){
            pair<int,int> pqtop = pq.top();
            pq.pop();
            while(!pq.empty() and pq.top().first==pqtop.first && pq.top().second == pqtop.second){ //if same frequency
                if(pq.top().second > pqtop.second) //choose bigger nunmber
                    pqtop = pq.top();
                pq.pop();
            }
            sum+=pqtop.second*pqtop.first; //number*frequency
            t++;
        }
        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>topx;
        for(int i = 0; i <= nums.size() - k ; i++)
            topx.push_back(sub(nums,k,x,i));
        return topx;
    }
};