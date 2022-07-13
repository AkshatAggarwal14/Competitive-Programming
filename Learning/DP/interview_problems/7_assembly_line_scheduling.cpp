// https://www.cs.rochester.edu/u/gildea/csc282/slides/C15-dynamic.pdf SLIDE 5
/*
Problem Statement/Definitions
1.You own two lines of N machines each used to produce one part of a car.
2. ith Machine in line 1 is called Mi1 and ith machine in line 2 is called Mi2.
3. ith Machine in line 1 takes Ti1 time to produce part P1 whereas ith machine of line 2 takes Ti2 time.
4. It takes e1 time to put raw material into line 1 machine 1 whereas it takes e2 time to put it in line 2 machine 1.
5. It takes r1 time to get ready car from Nth machine of line 1 whereas it takes r2 time to get ready car from Nth machine of line 2.
6. To go from Mi1 to M(i+1)1 it takes 0 seconds while it takes Si2 time to go from Mi1 to M(i+1)2
7. Si2 represents shift time to go from machine i in line1 to machine i+1 in line 2.
Si1 represents shift time to go from machine i in line2 to machine i+1 in line 1.
8. Starting from the raw material you should produce the car in minimum time possible. ith part should always be manufactured before (i+1)th part.
*/

#include <bits/stdc++.h>
using namespace std;

// let we have a machine named "end" which we have to reach at the end. from line 1 it take r1 time to reach and from line 2 it takes r2 time to reach.

int main() {
    /*
    chocies in beginning: 1. e1 + go_from(M11, end)
                          2. e2 + go_from(M12, end)
    go_from(Mi1, end): min time to reach from Mi1 to end
    dp[i][0]: go_from(Mi1, end)

    minimise using choices
    dp[i][0]: t1[i] + dp[i + 1][0]
              t1[i] + s2[i] + dp[i + 1][0]

    Base: dp[n][0]: t1[n] + r1
          dp[n][1]: t2[n] + r2

    ans: min(e1 + dp[1][0], e2 + dp[1][1])
     */
}