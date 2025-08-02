class Solution {
public:

long long minCost(vector<int>& basket1, vector<int>& basket2) {
    map<int, int> freq;
    for (int x : basket1) freq[x]++;
    for (int x : basket2) freq[x]++;

    for (auto& [k, v] : freq) {
        if (v % 2 != 0) return -1;
    }

    map<int, int> count1, count2;
    for (int x : basket1) count1[x]++;
    for (int x : basket2) count2[x]++;

    vector<int> surplus;
    for (auto& [k, _] : freq) {
        int diff = count1[k] - freq[k] / 2;
        if (diff > 0) {
            surplus.insert(surplus.end(), diff, k);
        }
        else if (diff < 0) {
            surplus.insert(surplus.end(), -diff, k);
        }
    }

    sort(surplus.begin(), surplus.end());
    int min_val = min(*min_element(basket1.begin(), basket1.end()),
                      *min_element(basket2.begin(), basket2.end()));

    long long cost = 0;
    int n = surplus.size();
    for (int i = 0; i < n / 2; ++i) {
        cost += min(surplus[i], 2 * min_val);
    }

    return cost;
}
};
