class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        set<int> avg; 
        
        int x = 0;
        int y = nums.size() - 1; 
        
        while(x < y)
        {
            avg.insert((nums[x] + nums[y])); 
            x++;
            y--;
        }
        
        return avg.size();
    }
};
