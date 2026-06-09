class Solution {
public:
    int target;
    int n;
    vector<int> dp;

    bool solve(int mask,
               int currSum,
               int groupsLeft,
               vector<int>& nums) {

        if (groupsLeft == 1)
            return true;

        if (currSum == target)
            return solve(mask, 0, groupsLeft - 1, nums);

        if (dp[mask] != -1)
            return dp[mask];

        for (int i = 0; i < n; i++) {

            if (!(mask & (1 << i)) &&
                currSum + nums[i] <= target) {

                if (solve(mask | (1 << i),
                          currSum + nums[i],
                          groupsLeft,
                          nums))
                    return dp[mask] = true;
            }
        }

        return dp[mask] = false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sum = 0;

        for (int x : nums)
            sum += x;

        if (sum % k)
            return false;

        target = sum / k;
        n = nums.size();

        dp.assign(1 << n, -1);

        return solve(0, 0, k, nums);
    }
};