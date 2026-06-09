class Solution {
public:

    int target = 0;
    bool solve(int i , int k , int curr , vector<int> & nums , vector<int>& used){
        int n=nums.size();
        if(i==n){
            return false;
        }
        if(k == 1){
            return true;
        } 

        if(curr == target){
            return solve(0 , k-1 , 0 , nums , used);
        }

        if(!used[i] && nums[i]+curr <= target){
            used[i]=1;
            if(solve(i+1 , k , curr+nums[i] , nums , used)){
                return true;
            }
            used[i]=0;
        }
        return solve(i+1 , k , curr , nums , used);
    }
    bool makesquare(vector<int>& matchsticks) {

        int n=matchsticks.size();
        int sum=0;
        for(int i=0 ; i< n ; i++){
            sum+=matchsticks[i];
        }
        if(sum%4!=0){
            return false;
        }
        target = sum/4;
        vector<int> used(n,0);
        return solve(0 , 4 , 0 , matchsticks , used);
        
    }
};