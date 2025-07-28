Q2) (2044)Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of different non-empty subsets with the maximum bitwise OR.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b. Two subsets are considered different if the indices of the elements chosen are different.

The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).

 

Example 1:

Input: nums = [3,1]
Output: 2
Explanation: The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:
- [3]
- [3,1]

  class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n= nums.size();
        int totalsub= (1 << n);
        int maxOr=0;
        int count=0;
        for(int num: nums)
        {
            maxOr |= num;
        }
        int currentOr=0;
        for(int i=0; i<totalsub; ++i)
        {    if(i==0)
              continue;
              currentOr=0;
            for(int j=0; j<n; ++j)
               {
                   if((i>>j)&1)
                   {
                     currentOr |= nums[j]; 
                   }
               }

               if(currentOr==maxOr)
               count++;
        }

        return count;
    }
};

  
