class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int s1 = nums1.size(), s2 = nums2.size();

        //always keep array A the smaller one, because we tune its index i based on j of array B
        //to keep our complexity log(min(s1,s2))
        if (s1 > s2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int half = (s1+s2+1)/2;
        long int left = 0, right = s1; 

        int i = left + (right - left)/2; //start from middle.
        int j = half - i; // 4-2-1=2, initialy starts from same index as i
        //you can think of i and j as mid1 and mid2
        //the element at index == mid is considered in right partition
        int Aleft, Aright;
        int Bleft, Bright;
        
        while(left<=right){
           
            i = left + (right - left)/2; 
            j = half - i;
            
            Aleft = (i == 0) ? INT_MIN : nums1[i-1];
            Aright = (i == s1) ? INT_MAX : nums1[i];
            Bleft = (j == 0) ? INT_MIN : nums2[j-1];
            Bright = (j == s2) ? INT_MAX : nums2[j];

            if(max(Aleft,Bleft)<=min(Aright,Bright)){
                break;
            }
            //always move i and not j, beacuse j depends on i and will be updated on every loop
            if(Aleft>Bright){
                right = i-1;
            }
            if(Bleft>Aright){
                left = i+1;
            }
        }

        if((s1+s2)&1){ //odd length
            return max(Aleft,Bleft);
        }

        return (max(Aleft,Bleft)+min(Aright,Bright))/2.0;

    }
};
