class Solution 
{
public:
    int removeDuplicates(vector<int>& nums, int k = 1)
    {
		return distance(nums.begin(), unique(nums.begin(), nums.end()));
		// or just subtract iterators...
		// return unique(nums.begin(), nums.end()) - nums.begin();
    }
};
