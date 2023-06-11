class Solution {
    
    public int climbStairs(int n) {
        
        // we create an array to store the values for previous steps
        int [] dp = new int[n + 1];
        dp[0] = 1;  //we are finding ways to reach not the total number of step, so to reach '0' there is only one way that is not to take any step. Therefore dp[0] is 1
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++) {
        // since we have 2 options(1 step and 2 step), so to reach at any place we can come from only two places '-1' or '-2'. Therefore we get both the values from our dp array and add them
            dp[i] = dp[i- 1] + dp[i - 2];   
        }
        
        return dp[n];
    }
}
