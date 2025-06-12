class Solution {
public:
    // Function to compute the minimum number of operations to convert text1 to text2
    int minDistance(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        // If either string is empty, return the length of the other (all insertions or deletions)
        if (m == 0 || n == 0)
            return m + n;

        // Ensure text1 is always the longer string to reduce space usage
        if (n > m) {
            return minDistance(text2, text1);
        }

        // Initialize a 2-row DP array for space optimization
        int dp[2][n + 1];

        // Fill base case: converting an empty text1 to first j characters of text2
        for (int j = 0; j <= n; j++)
            dp[0][j] = j;

        // Start filling the DP table row by row
        for (int i = 1; i <= m; i++) {
            // Base case: converting first i characters of text1 to empty string (all deletions)
            dp[1][0] = i;

            for (int j = 1; j <= n; j++) {
                // If characters match, no operation is needed
                if (text1[i - 1] == text2[j - 1])
                    dp[1][j] = dp[0][j - 1];
                else
                    // Otherwise, take minimum of insert, delete, or replace
                    dp[1][j] = 1 + min({
                        dp[0][j],     // delete operation
                        dp[1][j - 1], // insert operation
                        dp[0][j - 1]  // replace operation
                    });
            }

            // Copy current row to previous row for next iteration
            for (int j = 0; j <= n; j++) {
                dp[0][j] = dp[1][j];
            }
        }

        // The answer is in the last cell of the current row
        return dp[1][n];
    }
};
