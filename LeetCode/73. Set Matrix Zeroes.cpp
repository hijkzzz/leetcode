class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0  || matrix[0].size() == 0) return;

        //标记第一行和第一列
        int firstLine = 1;
        int firstCol = 1;

        //用第一行第一列标记
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    if(i == 0) firstLine = 0;
                    if(j == 0) firstCol = 0;

                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        //设置值
         for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstCol == 0){
            for(int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
        }

        if(firstLine == 0){
            for(int i = 0; i < matrix[0].size(); i++)
                matrix[0][i] = 0;
        }

    }
};
