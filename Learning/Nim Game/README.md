# Nim Game
There are three piles of chips (Example: 5, 7 and 9). Two players take turns. They select a pile and remove any number of chips from it. One can remove 1 chip, 2 chip, ..., entire pile. The player who removes the last pile is the winner!

## 1 Pile

> The first player removes all the chips from the only pile and wins! This is a `winning` position.

## 2 Piles

**Case 1**: Both piles are equal. ***(x, x)*** 

> The second player can mimic first players moves, and thus win. Thus this is a `losing` position.

### 3 Piles

- ***(0, x, x)*** is a `losing` position as this is equivalent to ***(x, x)*** 2 player nim game.
- ***(0, 0, x)*** is a `winning` position as this is equivalent to a 1 player nim game.
- ***(x, 1, 1)*** is a `winning` position as ***(0, 1, 1)*** is a `losing` position.
- ***(x, y, y)*** is a `winning` position as ***(0, 1, 1)*** is a `losing` position.

# Application
1. [The Game of Divisors](https://www.hackerrank.com/contests/codekar-3/challenges/the-game-of-divisors-1/problem)

# Resources
[Link 1](https://codeforces.com/blog/entry/66040?#comment-505669)