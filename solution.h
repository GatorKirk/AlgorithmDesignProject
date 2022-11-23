
struct answer{
    int l;
    int r;
    int sum;
};
struct answerMatrix{
    int x1;
    int y1;
    int x2;
    int y2;
    int sum;
};

class Solution {
public:
    answer maxSubArrayBrute(std::vector<int>& nums){//bruteforce
        answer ans;
        ans.sum=-INT_MAX;
        for (int i = 0; i < nums.size(); i++)
            for (int j = i; j < nums.size(); j++) {
                int sum = 0;
                for (int k = i; k <= j; k++)
                    sum += nums[k];
                if (sum > ans.sum){
                    ans.l=i;
                    ans.r=j;
                    ans.sum = sum;
                } 
            }
        return ans;            
    }
    
    answer maxSubArrayDPN2(std::vector<int>& nums){
        answer ans;
        ans.sum=-INT_MAX;    
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for (int j = i; j < nums.size(); j++)
            {
                sum+=nums[j];
                if(sum>ans.sum){
                    ans.l=i;
                    ans.r=j;
                    ans.sum = sum;                    
                }
            }
        }    
        return ans;            
    }    

    answer maxSubArrayBottomUp(std::vector<int>& nums) {
        answer ans;
        ans.l=0;ans.r=0;
        int s=0;
        std::vector<int> dp(nums.size());
        dp[0]=nums[0];
        ans.sum=dp[0];  
        for(int i=0;i<nums.size();i++){
            if(i==0){  
                if(dp[i]<0){
                    s=i+1;
                }
                continue;                
            }
            dp[i]=std::max(dp[i-1]+nums[i],nums[i]);
            if(dp[i]<0){
                s=i+1;
                dp[i]=0;
            }
            else if(ans.sum<dp[i]){
                ans.l=s;
                ans.r=i;
                ans.sum=dp[i]; 
            }

        }
        return ans;
    }

    answer maxSubArrayMemorization(std::vector<int>& nums) {    
        std::vector<std::vector<int>> dp(2, std::vector<int>(size(nums), -1));
        answer ans;
        ans.l=-1;ans.r=-1;
        ans.sum=solve(nums, 0, false, dp);
        for (int i = 0; i < dp[0].size(); i++)
        {
            if(dp[0][i]==dp[1][i])
                ans.r=i;
        }
        for (int j = dp[0].size(); j >0; j--)
        {
            if(dp[0][j]==dp[1][j])
                ans.l=j;
        }

        // int row=0,col=0;
        // row=dp.size();
        // if(row) col=dp[0].size();
        // for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++){
        //         if(j) putchar(' ');
        //         std::cout<<dp[i][j];
        //     }
        //     putchar('\n');
        // } 

        return ans;
    }
    int solve(std::vector<int>& A, int i, bool mustPick, std::vector<std::vector<int>>& dp) {
        if(i >= size(A)) return mustPick ? 0 : -1e5;
        if(dp[mustPick][i] != -1) return dp[mustPick][i];
        if(mustPick)
            return dp[mustPick][i] = std::max(0, A[i] + solve(A, i+1, true, dp));
        return dp[mustPick][i] = std::max(solve(A, i+1, false, dp), A[i] + solve(A, i+1, true, dp));
    }
    
    answerMatrix maxSubmatrixSumN6(std::vector<std::vector<int> > matrix)
    {
        answerMatrix ans;
        ans.sum = 0;
        // Stores the number of rows
        // and columns in the matrix
        int r = matrix.size();
        int c = matrix[0].size();

        // Take each row as starting row
        for (int i = 0; i < r; i++) {
    
            // Take each column as the
            // starting column
            for (int j = 0; j < c; j++) {
    
                // Take each row as the
                // ending row
                for (int k = i; k < r; k++) {
    
                    // Take each column as
                    // the ending column
                    for (int l = j; l < c; l++) {
    
                        // Stores the sum of submatrix
                        // having topleft index(i, j)
                        // and bottom right index (k, l)
                        int sumSubmatrix = 0;
    
                        // Iterate the submatrix
                        // row-wise and calculate its sum
                        for (int m = i; m <= k; m++) {
                            for (int n = j; n <= l; n++) {
                                sumSubmatrix += matrix[m][n];
                            }
                        }
    
                        // Update the maximum sum
                        if(sumSubmatrix>=ans.sum){
                            ans.sum=sumSubmatrix;
                            ans.x1=i;ans.y1=j;ans.x2=k;ans.y2=l;
                        }

                    }
                }
            }
        }
        return ans;
    }
    
    answerMatrix maxSubmatrixSumN3(std::vector<std::vector<int> > matrix)
    {
        answer ans;
        answerMatrix ans2;
        ans2.sum = INT_MIN;ans2.x1=-1;ans2.y1=-1;ans2.x2=-1;ans2.y2=-1;
        // Stores the number of rows
        // and columns in the matrix
        int r = matrix.size();
        int c = matrix[0].size();
        int right,left,i;
        std::vector<int> nums;
        for(left=0;left<c;++left){
            nums.clear();
            nums.resize(r,0);
            for(right=left;right<c;++right){
                for(i=0;i<r;++i){
                    nums[i] += matrix[i][right];
                }
                ans=maxSubArrayBottomUp(nums);
                if (ans.sum > ans2.sum) {
                ans2.sum = ans.sum;
                ans2.x1 = ans.l;                
                ans2.y1 = left;
                ans2.x2 = ans.r;
                ans2.y2 = right;

                }
            }
        }
        return ans2;
    }    
    
    answerMatrix maxSubmatrixSumN4(std::vector<std::vector<int> > matrix)
    {
        answer ans;
        answerMatrix ans2;
        ans2.sum = INT_MIN;ans2.x1=-1;ans2.y1=-1;ans2.x2=-1;ans2.y2=-1;
        // Stores the number of rows
        // and columns in the matrix
        int r = matrix.size();
        int c = matrix[0].size();
        int right,left,i;
        std::vector<int> nums;
        for(left=0;left<c;++left){
            nums.clear();
            nums.resize(r,0);
            for(right=left;right<c;++right){
                for(i=0;i<r;++i){
                    nums[i] += matrix[i][right];
                }
                ans=maxSubArrayDPN2(nums);
                if (ans.sum > ans2.sum) {
                ans2.sum = ans.sum;
                ans2.x1 = ans.l;                
                ans2.y1 = left;
                ans2.x2 = ans.r;
                ans2.y2 = right;

                }
            }
        }
        return ans2;
    }           
};

 

