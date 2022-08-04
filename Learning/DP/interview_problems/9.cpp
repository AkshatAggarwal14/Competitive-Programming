/*
You are given an array 'A' of size 'N' and an integer 'K'. N is always even. You will play a game against the computer.
The rules of the game are as follows:-
1. You will play the first turn and both players will take turns alternately.
2. Initially score of each player will be 0.
3. In your turn, you need to remove either the leftmost or the rightmost element of the array 'A[i]' and add it to your score. But you can remove at max 'K' consecutive elements from the same side. More formally if you have removed elements from only one side in your last 'K' turns then, you have to remove the element from the other side in your current turn. Otherwise, if you have played less than 'K' turns or if you have removed elements from both sides in your last 'K' turns then, you can remove an element from any side.

4. In the computer's turn, he can remove the leftmost or the rightmost element of the array 'A' and add it to its score. There is no other constraint on the computer, it can choose more than 'K' consecutive elements from the same side in its turn.

5. The size of the array will decrease by one after each turn.
6. The game ends when the size of 'A' becomes 0.
7. Each player will play optimally and will try to maximize their score.
Return the maximum score you can achieve.
Note : Assume 0-based indexing.
For example:
Let 'N' = 2, 'K' = 1, 'A' = [ 1, 2, 2, 1]

You: Choose the leftmost element then, your score will be updated to 1 and 'A'  will be updated to [2, 2, 1].

Computer: Chooses the left-most element, then its score will be 2 and 'A' will be updated to [2, 1].

You: Choose the rightmost element i.e. 1 and your score will be updated to 2 and 'A' will be updated to [2]. As K = 1, you cannot choose the leftmost element again in your current turn given that you have already taken the element from the left side in your last turn.

Computer: Choose the last remaining element i.e. 2 update its score to 4. Therefore your final score will be 2.

It can be proved that this is the maximum score you can achieve if both players play optimally.
Input Format:-
The first line contains an integer 'T', which denotes the number of test cases.

For every test case:-
The first line contains two integers 'N' and 'K', denoting the number of elements in the array and maximum consecutive elements you can choose from the same respectively.
The second line contains 'N' space-separated integers denoting the elements of the array 'A'.
Output Format:-
For each test case, return the maximum score you can achieve.
Note:-
You don’t need to print anything. Just implement the given function.
Constraints:-
1 <= 'T' <= 10
1 <= 'N' <= 10^2
1 <= 'K' <= 10^2
1 <= 'A[i]' <= 10^7

'N' is even.
The sum of 'N' over all test cases does not exceed 10^2.

Time Limit: 1 sec
*/