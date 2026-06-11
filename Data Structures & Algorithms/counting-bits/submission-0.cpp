class Solution {
public:
    vector<int> ans;
    void solve(int n , int j){
        int temp = j;
        if(j>n){
            return;
        }
        int an=0;
        while(temp){
            temp = temp & (temp-1);
            an++;
        }
        ans.push_back(an);
        solve(n,j+1);
    }
    vector<int> countBits(int n) {
        solve(n , 0);
        return ans;
    }
};
