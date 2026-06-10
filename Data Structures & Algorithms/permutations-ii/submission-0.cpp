class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& nums, int n, vector<int>& vis) {
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {

            if (vis[i])
                continue;

            if (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])
                continue;

            vis[i] = 1;
            temp.push_back(nums[i]);

            solve(nums, n, vis);

            temp.pop_back();
            vis[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> vis(n, 0);

        solve(nums, n, vis);

        return ans;
    }
};