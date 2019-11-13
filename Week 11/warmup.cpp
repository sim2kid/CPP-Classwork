class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int last = 0;
        int count = 0;
        for(auto i = nums.begin(); i != nums.end(); i++) {
            if(count == 0) {
                last = nums.front() - 1;
            }
            if(last != *i) {
                last = *i;
                count++;
            } else {
                nums.erase(i);
                i--;
            }
        }
        
        return count;
    }
};