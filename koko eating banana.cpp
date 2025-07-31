Q4) (875) Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.
Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

class Solution {
public:
    bool check(vector<int>& piles, int h,int m)
    {
        int n=piles.size(); 
        long th=0;
        for(int i=0 ; i<n ; ++i)
        { 
            th += (long)(ceil((double)piles[i]/m));
        }
        if(th<=h)
        return true;
        else 
        return false;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        if(n==1)
        return (int)(ceil((double)piles[0]/h));
      
        int l =1;
  
        int hr =  *max_element(piles.begin(), piles.end());
      
        while(l<=hr)
        {
            int m= (l+hr)/2;
            if(check(piles,h,m))
            {
              
                hr=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return l;
    }
};

