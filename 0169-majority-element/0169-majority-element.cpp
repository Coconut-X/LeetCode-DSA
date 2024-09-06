class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count = 1;
int majorityElement = nums[0];

for (int i = 1; i < nums.size(); i++)
{
		
	if (count == 0)
	{
		count = 1;
		majorityElement = nums[i];
	}
	else if (majorityElement == nums[i])
	{
		count++;
	}
	else
	{
		count--;
	}
	
}

if (count == 0) return -1;



return majorityElement;


    }
};