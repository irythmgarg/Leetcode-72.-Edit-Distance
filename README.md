# Leetcode-72.-Edit-Distance

# 📝 Edit Distance (Levenshtein Distance) - README

Welcome to the **Edit Distance** guide! 🧠 This classic dynamic programming problem measures how similar two strings are by counting the minimum number of operations required to transform one string into another.

---

## 📘 Problem Statement

Given two strings `word1` and `word2`, return the **minimum number of operations** required to convert `word1` to `word2`. The allowed operations are:

* Insert a character
* Delete a character
* Replace a character

### 💡 Example:

Input: `word1 = "horse"`, `word2 = "ros"`
Output: `3`
Explanation: horse -> rorse (replace 'h' with 'r') -> rose (remove 'h') -> ros (remove 'e')

---

## 🧵 Approach 1: Pure Recursion 🌀

### 🔍 Idea:

* Try every possible operation (insert, delete, replace) at each step.
* Recurse on all three choices and take the minimum.

### ❌ Drawback:

* Overlapping subproblems cause **exponential time**.
* Time Complexity: **O(3^n)**
* Space Complexity: **O(n + m)** (recursion stack)

---

## 🧠 Approach 2: Top-Down DP (Memoization) 🧠

### 💡 Idea:

* Store the result of subproblems using a 2D memoization table.
* Avoid recomputation by caching results.

### ⚙️ How:

* `dp[i][j]` represents min operations to convert `word1[0...i-1]` to `word2[0...j-1]`

### 🧮 Complexity:

* Time: **O(n \* m)**
* Space: **O(n \* m)** (memo table)

---

## 🧊 Approach 3: Bottom-Up DP (Tabulation) 🧊

### 🔍 Idea:

* Build a table from smaller subproblems up to the full strings.
* Compare characters and fill based on the minimum of:

  * Insert ➕
  * Delete ➖
  * Replace ✏️

### 📋 Table:

* `dp[i][j] = dp[i-1][j-1]` if characters match
* Else `1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])`

### 📈 Complexity:

* Time: **O(n \* m)**
* Space: **O(n \* m)**

---

## 💾 Approach 4: Space Optimized DP 💽

### ⚙️ Idea:

* At any point, only the previous and current rows are required.
* Use two 1D arrays to reduce space.

### ✨ Advantage:

* Great for large inputs with memory constraints.

### 📉 Complexity:

* Time: **O(n \* m)**
* Space: **O(min(n, m))**

---

## 🧪 Summary of Approaches

| Approach            | Time Complexity | Space Complexity |
| ------------------- | --------------- | ---------------- |
| Pure Recursion      | O(3^n)          | O(n + m)         |
| Top-Down (Memo)     | O(n \* m)       | O(n \* m)        |
| Bottom-Up (Tabular) | O(n \* m)       | O(n \* m)        |
| Space Optimized     | O(n \* m)       | O(min(n, m))     |

---

## 🎯 Applications

* Spell checkers and autocorrect
* DNA sequencing and bioinformatics
* Natural language processing
* Plagiarism detection

---

## 📜 License

MIT License. Free to use and modify!

---

**Made with ❤️ by Ridham Garg**
