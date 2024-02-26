
#include<iostream>
#include<vector>
using namespace std;


// Kadane's Algorithm


// Naive Approach -
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int answer=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            int currSum=nums[i];
            answer=max(answer,currSum);
            for(int j=i+1;j<nums.size();j++)
            {
                currSum+=nums[j];
                answer=max(answer,currSum);
            }
        }
        return answer;
    }

};


// Better Approach

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int answer=nums[0];
        int currSum=nums[0];
        for(int i=1;i<nums.size();i++)
        {   
            if(currSum<0) currSum=0;
            currSum+=nums[i];
            answer=max(currSum,answer);
            
        }
        return answer;
    }

};
