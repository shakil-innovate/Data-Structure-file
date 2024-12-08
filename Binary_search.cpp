#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l,r,m;
        l=0;r=nums.size();

        while(l<r)
        {
            m=(l+r)/2;

            if(nums[m]==target)
            {
                return m;
            }

            else if(nums[m]>target)
            {
                r=m-1;
            
            }

            else if(nums[m]<target)
            {
                l=m+1;
            }
        }
        return -1;
        
    }
};