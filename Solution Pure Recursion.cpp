class Solution {
public:

    // Recursive function to calculate minimum edit distance between substrings of word1 and word2
    int hlo(string word1, string word2, int i, int j) {

        // If all characters in word1 are processed, insert remaining characters from word2
        if (i >= word1.length()) {
            return word2.length() - j;
        }

        // If all characters in word2 are processed, delete remaining characters from word1
        if (j >= word2.length()) {
            return word1.length() - i;
        }

        // If characters at current indices match, move both pointers forward
        if (word1[i] == word2[j]) {
            return hlo(word1, word2, i + 1, j + 1);
        }

        // Try all three operations: insert, delete, and replace
        int insertOp = 1 + hlo(word1, word2, i, j + 1);     // Insert character from word2
        int deleteOp = 1 + hlo(word1, word2, i + 1, j);     // Delete character from word1
        int replaceOp = 1 + hlo(word1, word2, i + 1, j + 1); // Replace character

        // Return the minimum cost among the three operations
        return min({insertOp, deleteOp, replaceOp});
    }

    // Main function to compute minimum edit distance
    int minDistance(string word1, string word2) {
        return hlo(word1, word2, 0, 0); // Start recursion from the beginning of both strings
    }
};
