class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
int n = nums.size();
        
       
        vector<int> count(2 * n + 1, 0);
        
        int current_sum = 0;
        count[0 + n] = 1; 
        long long less_count = 0; 
        long long total_subarrays = 0;
        for (int x : nums) {
            int old_sum = current_sum;
            
            if (x == target) {
                current_sum += 1;
               
                less_count += count[old_sum + n];
            } else {
                current_sum -= 1;
             
                less_count -= count[current_sum + n];
            }
            
            total_subarrays += less_count;
            
            count[current_sum + n]++;
        }
        
        return total_subarrays;
    }
};