class Solution {
public:
    vector<vector<int>> t;
    int solve(int n,int budget,int minprice,vector<vector<int>>& items,vector <int>& copies){
        if(n==0){
            return budget/minprice;
        }
        if(t[n][budget] !=-1){
            return t[n][budget];
        }
        int take=0;
        int price=items[n-1][1];
        int skip=0;
        if(price <= budget){
            take=1+copies[n-1]+solve(n-1,budget-price,minprice,items,copies);
        }
        skip=solve(n-1,budget,minprice,items,copies);

        return t[n][budget]=max(take,skip);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector <int> copies(n,0);
        int minprice=INT_MAX;
        for(int i=0;i<n;i++){
            minprice=min(minprice,items[i][1]);
            int copy=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                
                if(items[j][0] % items[i][0]==0){
                    copy++;
                }
            }
            copies[i]=copy;
        }
        t.assign(n + 1, vector<int>(budget + 1, -1));
        return solve(n,budget,minprice,items,copies);
    }
};