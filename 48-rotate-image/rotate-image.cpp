class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();

        // Firstly Trnasposing the matrix
        /*  matrix: [1 2 3]
                    [4 5 6]
                    [7 8 9] 
                    
            transpose: [1 4 7]
                       [2 5 8]
                       [3 6 9] */
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reversing each row to get the final answer
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};