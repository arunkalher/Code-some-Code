
# DSA - Episode 01 
# Kadane's Algorithm
#### 2 min read
## Statement- 
### Given an integer array nums, find the subarray (containing at least one number) with the largest sum, and return its sum.

## Subarray
### A subarray is a contiguous sequence of elements within an array.
#
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4] 

Output: 6

Explanation: The subarray [4,-1,2,1] has the largest sum 6.
#
Example 2:

Input: nums = [1]

Output: 1

Explanation: The subarray [1] has the largest sum 1.
Example 3:
#
Input: nums = [5,4,-1,7,8]

Output: 23

Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

## Approach-


### Naive Approach -

Calculate each subarray sum iteratively and store max in a variable-

```cpp
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
```


## Time and Space Complexity
### Time - O(N^2)
### Space - O(1)



### Better Approach - ( What Kadene suggested ?)

Do we need two loops ? Actually, we can do our work in one loop only.

We can iterate once and calculate current subarray sum dynamically ( say currSum ) , if currSum sum is less than 0 then again initialize it to zero.

```cpp
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
```
## Time and Space Complexity
### Time - O(N)
### Space - O(1)


## Thanks for Reading