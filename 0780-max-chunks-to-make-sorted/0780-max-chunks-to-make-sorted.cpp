class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int count = 0;
        int maxSeen = 0;

        for (int i = 0; i < arr.size(); i++) 
        {
            maxSeen = max(maxSeen, arr[i]);
            if (maxSeen == i) 
            {
                count++;
            }
        }
        //the numbers are unique and largest num=largest index in array
        //so each number should be at the same index as its value

        return count;
    }
};
