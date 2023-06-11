class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v1{{1}};
        if(numRows==1) return v1;
        for(int i=1;i<numRows;i++){
            vector<int> s;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i) s.push_back(1);
                else{
                    s.push_back(v1[i-1][j-1]+v1[i-1][j]);
                }
            }
            v1.push_back(s);
        }
            return v1;
    }
};