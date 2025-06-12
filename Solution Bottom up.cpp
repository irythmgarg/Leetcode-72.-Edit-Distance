class Solution {
public:
    // Function to compute the minimum number of operations (insert, delete, replace)
    // required to convert word1 into word2 using Dynamic Programming.
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        // Create a DP table of size (m+1) x (n+1)
        int dp[m + 1][n + 1];

        // Initialize the first column: converting word1[0...i] to empty string
        // Requires i deletions
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }

        // Initialize the first row: converting empty string to word2[0...j]
        // Requires j insertions
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        // Fill the rest of the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // If current characters match, no operation is needed
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // Otherwise, take the minimum of the three operations:
                // Insert, Delete, Replace
                else {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],     // Delete from word1
                        dp[i][j - 1],     // Insert into word1
                        dp[i - 1][j - 1]  // Replace in word1
                    });
                }
            }
        }

        // Return the final answer: minimum operations for word1[0...m] -> word2[0...n]
        return dp[m][n];
    }
};
