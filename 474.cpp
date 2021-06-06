class Solution {
public:
        int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for (int i=0;i<length;i++){
            int zeros,ones,strlength=strs[i].size();
            for (int j=0;j<strlength;j++){
                strs[i][j]=="0" ? zeros++ : ones++;
            }
            for (int j=m;j>=zeros;j--){
                for (int k=n;k>=ones;k--){
                    dp[j][k] = max(dp[j][k], dp[j - zeros][k - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};