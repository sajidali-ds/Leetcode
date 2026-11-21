class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int row=dimensions.size();
        int col=dimensions[0].size();
        int maxi=0;
        int area=0;
        vector<int>diagonal_length(row);
        for(int i=0;i<row;i++){
           
            diagonal_length[i]=(dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1]);
            
            
        }
        for(int i=0;i<row;i++){
            if(maxi < diagonal_length[i]){
                maxi=diagonal_length[i];
                area=dimensions[i][0]*dimensions[i][1];
            }
            else if(maxi == diagonal_length[i]) {
                area = max(area, dimensions[i][0] * dimensions[i][1]);
            }

        }
        return area;
    }
};