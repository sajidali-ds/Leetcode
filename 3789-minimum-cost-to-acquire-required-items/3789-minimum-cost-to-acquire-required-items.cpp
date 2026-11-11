class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long  cost=0;
        long long common = min(need1, need2);
        cost = common * min(
            (long long)costBoth,
            (long long)cost1 + cost2
        );

        need1 -= common;
        need2 -= common;

        cost += (long long)need1 * min(cost1, costBoth);
        cost += (long long)need2 * min(cost2, costBoth);

        return cost;
        
    }
};