class Solution {
public:
    int maxi(vector<int> & nums){
        int a=INT_MIN;
        int n=nums.size();
        for(int i=0 ; i< n ; i++){
            if(nums[i] > a){
                a=nums[i];
            }
        }
        return a;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int cnt;
        int a = maxi(piles);
        int l = 1;
        int mid;

        while(l<a){
            cnt = 0;
            mid = l + (a-l)/2;
            for(int i = 0 ; i<n ; i++){
                cnt += (piles[i]+mid-1)/mid;
            }
            if(cnt<=h){
                a=mid;
            }
            else{
                l=mid+1;
            }

        }
        return l;

    }
};
