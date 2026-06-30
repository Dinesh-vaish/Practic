class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int gcd=0;
       for(int i:nums)
       {
        gcd=__gcd(gcd,i);
        if(gcd==1) return 1;
       }
       return 0;
    }
};