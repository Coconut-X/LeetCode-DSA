class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int left=0, right=letters.size()-1;
        char ans = letters[0];
        while(left<=right){
            int mid=left + (right - left)/2;

            if(letters[mid]<=target){
                left=mid+1;
            }
            else{
                right=mid-1;
                ans=letters[mid];
            }
             
        }
        
        return ans;
        //return ans>target?ans:letters[0];
        
    }
};