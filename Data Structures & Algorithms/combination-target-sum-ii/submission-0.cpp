class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(vector<int> & can , int tar , int i){
    if(tar==0){
        ans.push_back(temp);
        return;
    }
    if (i >= can.size() || tar < 0)
            return;
    temp.push_back(can[i]);
    solve(can , tar - can[i] , i+1);
    temp.pop_back();
    int j=i+1;
    while(j<can.size() && can[j] == can[i]){
        j++;
    }
    solve(can , tar  , j);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        solve(candidates , target ,0);
        return ans;
    }
};
