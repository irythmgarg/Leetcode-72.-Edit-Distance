class Solution {
public:

    // Memoization table to store results of subproblems
    int dp[501][501];

    // Recursive helper function to calculate minimum edit distance
    int hlo(string word1, string word2, int i, int j) {

        // If word1 is fully traversed, insert remaining characters of word2
        if (i >= word1.length()) {
            return word2.length() - j;
        }

        // If word2 is fully traversed, delete remaining characters of word1
        if (j >= word2.length()) {
            return word1.length() - i;
        }

        // If result already computed, return from dp table
        if (dp[i][j] != -1)
            return dp[i][j];

        // If characters match, move both pointers ahead
        if (word1[i] == word2[j]) {
            return dp[i][j] = hlo(word1, word2, i + 1, j + 1);
        }

        // Compute all three operations: insert, delete, replace
        int insertOp = 1 + hlo(word1, word2, i, j + 1);     // Insert character
        int deleteOp = 1 + hlo(word1, word2, i + 1, j);     // Delete character
        int replaceOp = 1 + hlo(word1, word2, i + 1, j + 1); // Replace character

        // Take minimum of the three operations
        return dp[i][j] = min({insertOp, deleteOp, replaceOp});
    }

    // Main function to initialize memoization and call recursive logic
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp)); // Initialize dp array with -1
        return hlo(word1, word2, 0, 0); // Start comparing from index 0 of both strings
    }
};
