class Solution {
public:
    bool isSafe(int row,int col,char val,vector<vector<char>>& arr){
        int c = 0;
        for(int i=0;i<9;i++){

            // if(3*(row/3) + (i/3) == row && 3*(col/3) + i%3 == col){
            //     continue;
            // }

            // if(row == row && i==col){
            //     continue;
            // }
            // if(col == col && i == row){
            //     continue;
            // }

            if(arr[row][i] == val){     
            c++;
               // return false;
            }
            if(arr[i][col] == val){
                c++;
             //   return false;
            }
            if(arr[3*(row/3) + (i/3)][3*(col/3) + i%3] == val){
                c++;
              //  return false;
            }
            if(c>3){
                return false;
            }
        }
        
        return true;
    }
    bool solve(vector<vector<char>>& arr){
        int n = arr[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]!='.'){
                 //   cout<<arr[i][j]<<" "<<isSafe(i,j,arr[i][j],arr)<<endl;
                    if(isSafe(i,j,arr[i][j],arr)){
                     //   cout<<"issafe "<<arr[i][j]<<endl;
                    }else{
                        return false;
                    }

                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int ans = false;
        ans = solve(board);
        return ans;

    }
};