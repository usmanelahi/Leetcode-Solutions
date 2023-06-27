class Solution {
public:
    
    int f(int vowel,int count,int n,vector<vector<int>> &dp){
        if(count>=n){
            return 1;
        }
        if(vowel>=5){
            return 0;
        }

        if(dp[count][vowel]!=-1) return dp[count][vowel];

        int f1=f(vowel+1,count,n,dp);
        int f2=f(vowel,count+1,n,dp);

        return dp[count][vowel]=f1+f2;
    }

    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1,vector<int>(5,-1));
        return f(0,0,n,dp);
    }
};
