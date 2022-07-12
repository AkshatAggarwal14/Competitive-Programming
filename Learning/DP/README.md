# Table of Contents
1. Knapsack
    - [0-1 Knapsack](./01_Knapsack/)
        - [Recursive (Top - Down)](./01_Knapsack/01_recursive_memoization.cpp)
        - [Tabulation (Bottom up)](./01_Knapsack/01_tabulation.cpp)
        - [Space optimised tabulation](./01_Knapsack/01_space_optimised.cpp)
        - Questions
            1. [Checking if subset with given sum exists](./01_Knapsack/subset_sum.cpp)
            2. [Count of subsets with given sum](./01_Knapsack/count_of_subset_sum.cpp)
            3. [Can you partition array into subsets with equal sum?](./01_Knapsack/equal_sum_partition.cpp)
            4. [Find minimum difference between sum of subsets](./01_Knapsack/minimum_subset_sum_difference.cpp)
            5. [Count of subsets with given difference](./01_Knapsack/count_subsets_given_difference.cpp)
    - [Unbound Knapsack](./unbounded_knapsack/)
        - [Tabulation (Bottom up)](./unbounded_knapsack/unbounded.cpp)
        - Questions
            1. [Rod Cutting problem](./unbounded_knapsack/rod_cutting_problem.cpp)
            2. [Coin Change I](./unbounded_knapsack/coin_change.cpp) - Total ways to get given sum
            3. [Coin Change II](./unbounded_knapsack/coin_change_2.cpp) - Minimum number of coins needed for given sum

2. Longest Common Subsequence type DP
    - LCS
        - Length of LCS
            1. [Recursive (Top - Down)](./LCS/LCS_recursive.cpp)
            2. [Tabulation (Bottom up)](./LCS/LCS_iterative.cpp)
            3. [Space optimised tabulation](./LCS/LCS_iterative_space.cpp)
        - [Print LCS](./LCS/LCS_print.cpp)
    - [Longest Common Subtring](./LCS/Longest_common_substring.cpp)
    - [Shortest Common Supersequence](./LCS/SCS.cpp)
    - [Minimum Insertions OR Deletions to convert A to B](./LCS/min_insert_delete.cpp)
    - [Longest Palindromic Subsequence](./LCS/LPS.cpp)
    - [Print SCS](./LCS/SCS_print.cpp)
    - [Longest Repeating Subsequence](./LCS/LRepeatingS.cpp)
    - [Minimum Insertions to make string Palindrome](./LCS/insert_palin.cpp)
    - [Longest Increasing Subsequence](./LCS/LIS.cpp) $(O(n^2))$
    - [Longest Increasing Subsequence](./LCS/LIS_efficient.cpp) $(O(n log(n)))$
    - [Longest Increasing Subsequence](./LCS/LIS_best.cpp) $(O(nlog(n)))$ and shorter code

3. Matrix Chain Multiplication
    - MCM
        - [Recursive](./MCM/MCM_recursive.cpp)
        - [Memoized](./MCM/MCM_memoized.cpp)
        - [Tabulation / Iterative](./MCM/MCM_iterative.cpp)
    - [Palindrome Partitioning](./MCM/palindrome_partitioning.cpp)
    - [Evaluate Expression to true / boolean paranthesis](./MCM/boolean_paranthesis.cpp)
    - Min / Max value of an expression
    - [Scramble string](./MCM/scrambled_string.cpp)
    - [Egg Dropping Problem](./MCM/egg_dropping_problem.cpp)

4. DP on Trees
    - [Diameter of Binary Tree](./dp_on_trees/diameter_of_tree.cpp)
    - [Maximum Path sum from any node to any other node](./dp_on_trees/maximum_path_sum.cpp)
    - [Maximum Path sum from leaf to leaf](./dp_on_trees/maximum_path_sum_from_leaf_to_leaf.cpp)
    - [Binary Lifting](./dp_on_trees/binary_lifting.cpp)
        - [LCA](./dp_on_trees/lca_using_binary_lifting.cpp)
    - Diameter of N-ary Tree

5. Misc
    - [Kadane's Algorithm](./Kadane.cpp)
    - [Interview Problem](./interview_problem.cpp)
    - [Leetcode Problems](https://leetcode.com/discuss/general-discussion/458695/dynamic-programming-patterns#Minimum-(Maximum)-Path-to-Reach-a-Target)