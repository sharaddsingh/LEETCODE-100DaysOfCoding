Fruits are available at some positions on an infinite x-axis. You are given a 2D integer array fruits where fruits[i] = [positioni, amounti] depicts amounti fruits at the position positioni. fruits is already sorted by positioni in ascending order, and each positioni is unique.

You are also given an integer startPos and an integer k. Initially, you are at the position startPos. From any position, you can either walk to the left or right. It takes one step to move one unit on the x-axis, and you can walk at most k steps in total. For every position you reach, you harvest all the fruits at that position, and the fruits will disappear from that position.

Return the maximum total number of fruits you can harvest

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
             int n = fruits.size();
        vector<int> positions(n), prefix(n + 1);

        for (int i = 0; i < n; ++i) {
            positions[i] = fruits[i][0];
            prefix[i + 1] = prefix[i] + fruits[i][1];
        }

        auto getFruitSum = [&](int left, int right) {
            auto l = lower_bound(positions.begin(), positions.end(), left) - positions.begin();
            auto r = upper_bound(positions.begin(), positions.end(), right) - positions.begin();
            return prefix[r] - prefix[l];
        };

        int maxFruits = 0;

    
        for (int x = 0; x <= k; ++x) {
            int left = startPos - x;
            int rem = k - 2 * x;
            if (rem < 0) continue;
            int right = startPos + rem;
            maxFruits = max(maxFruits, getFruitSum(left, right));
        }

        for (int x = 0; x <= k; ++x) {
            int right = startPos + x;
            int rem = k - 2 * x;
            if (rem < 0) continue;
            int left = startPos - rem;
            maxFruits = max(maxFruits, getFruitSum(left, right));
        }

        return maxFruits;
  
    }
};
