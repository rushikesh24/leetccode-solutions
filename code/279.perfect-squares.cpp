class Solution {
public:
    
    vector<int> perfectSquare(int n){
        int range = floor(sqrt(n));
        vector<int> res;
        for(int i=1; i<=range; i++){
            res.push_back(i*i);
        }
        return res;
    }
    
    int numSquares(int n) {
        vector<int> squares = perfectSquare(n);
        int m = squares.size();
        int dp[m][n+1];
//         cout<<m<<endl;
        
//         for(int i=0; i<m; i++)
//             cout<<squares[i]<<"\t";
//         cout<<endl;
        memset(dp, 0, sizeof(dp));
        int min_val = INT_MAX;
        for(int i=0; i<m; i++){
            for(int j=1; j<=n; j++){
                if(squares[i] == j)
                    dp[i][j] = 1;
                
                else if(squares[i] < j){
                    if(i==0) dp[i][j] = 1 + dp[i][j-squares[i]];
                    else dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-squares[i]]);
                }
                    
                else if(squares[i] > j)
                    dp[i][j] = dp[i-1][j];
                
                if(j==n)
                    min_val = min(dp[i][j], min_val);
            }
        }
        
        // for(int i=0; i<m; i++){
        //     for(int j=1; j<=n; j++)
        //         cout<<dp[i][j]<<"\t";
        //     cout<<endl;
        // }
        return min_val;
    }
};

// [1,4,9]

// 11 
// 11-4 = 7


                                    
//         0   1   2   3   4   5   6   7   8   9   10  11  12  
//     ---------------------------------------------------------------
// [1]     0   1   2   3   4   5   6   7   8   9   10  11  12
// [4]     0   1   2   3   1   2   3   4   2   3   4   5   3
// [9]     0   1   2   3   1   2   3   4   2   1   2   3   4
