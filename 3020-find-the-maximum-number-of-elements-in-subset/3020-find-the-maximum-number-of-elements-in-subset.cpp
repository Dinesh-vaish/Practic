class Solution {
public:
    int maximumLength(vector<int>& nums) {
    unordered_map<long long, int> counts;
    for (int num : nums) {
        counts[num]++;
    }

    int ans = 1;
    if (counts.count(1)) {
        int countOfOnes = counts[1];
        ans = (countOfOnes % 2 == 0) ? countOfOnes - 1 : countOfOnes;
    }

    for (auto const& [val, freq] : counts) {
        if (val == 1) continue;

        int currentLen = 0;
        long long currentBase = val;

        while (counts.count(currentBase) && counts[currentBase] >= 2) {
            currentLen += 2;
            if (currentBase > 100000) {
                currentBase = 0;
                break;
            }
            currentBase = currentBase * currentBase;
        }

        if (currentBase > 0 && counts.count(currentBase) && counts[currentBase] >= 1) {
            currentLen += 1;
        } else {
            currentLen -= 1;
        }

        ans = max(ans, currentLen);
    }

    return ans;
    }
};
