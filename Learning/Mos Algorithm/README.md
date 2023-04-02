Learning sources: [Mo's Algorithm](https://cp-algorithms.com/data_structures/sqrt_decomposition.html), [Mo's Algorithm with updates](https://www.youtube.com/watch?v=gUpfwVRXhNY)

# What is the time complexity of the Mo's Algorithm?
Sorting all Queries will take $O(Q*log(Q))$.

`NOTE:` All queries are sorted in the following order: `<[L], R>`, here `[L]` means the block in which `L` lies, and `R` means the right index of query.

1. Let block size be $S$. The value of `cur_l` will change by atmost $O(S)$ between two queries, thus we have $O(SQ)$ calls of `add(cur_l)` and `remove(cur_l)`.

2. Also for one block, as all queries with left index in same block are sorted by their right index, we have to move `cur_r` by atmost $O(N)$. Thus for all the blocks, we have additional $O((N/S)*N)$ calls of `add(cur_r)` and `remove(cur_r)`. Here $N/S$ is the number of blocks.

Now as $S \approx \sqrt n$, the number of `add()` and `remove()` calls become $O((N+Q) \sqrt N)$. So, complexity is $O((N+Q)F \sqrt N)$, where $O(F)$ is the complexity of the `add()` and `remove()` function.

`NOTE:` If we try to find the optimal value of $S$, for the relation $f(S) = SQ + N^2/S$, by using calculus, we will find $S = N / \sqrt{Q}$. This is the optimal value of $S$, but $\sqrt{N}$ also works fine.

# How to improve runtime of Mo's Algorithm?
1. In odd blocks sort the right index in ascending order and in even blocks sort it in descending order. This will minimize the movement of right pointer, as the normal sorting will move the right pointer from the end back to the beginning at the start of every block. With the improved version this resetting is no more necessary.

    Code for this version of comparator is:
```cpp
bool operator<(const Query &other) const {
    if (l / block_size != other.l / block_size) return l < other.l;
    return ((l / block_size) & 1) ? r < other.r : r > other.r;
}
```

2. Block size of precisely  $\sqrt{N}$  doesn't always offer the best runtime. For example, if  $\sqrt{N}=750$  then it may happen that block size of  $700$  or  $800$  may run better. More importantly, don't compute the block size at runtime - make it const. Division by constants is well optimized by compilers.

# How does Mo's Algorithm with updates work?
Refer Following code: [SPOJ - XXXXXXXX Solution](./Q5-mos-updates.cpp).

The problem includes doing range queries, along with point updates of the form $a_{pos} = val$.

If we use similar method as mentioned above, we will get the complexity of $O(Q * N * \sqrt{Q})$ because before each query we have to do some updates, and undo other updates.

When dealing with udpates, we sort the queries in the following order: `<[L], [R], updatesTillNow>`.

`NOTE:` Similar optimization in the comparator can be applied and the following comparator can be used:

```cpp
bool operator<(const Query &other) const {
    if (l / block_size != other.l / block_size) 
        return l < other.l;
    if (r / block_size != other.r / block_size) 
        return ((l / block_size) & 1) ? r < other.r : r > other.r;
    return (((l / block_size) & 1) ^ ((other.l / block_size) & 1))
                ? updatesTillNow < other.updatesTillNow
                : updatesTillNow > other.updatesTillNow;
}
```

1. Total changes of `cur_l`: Suppose we have $q_i$ queries with $L$ in $i^{th}$ block. Thus the value of `cur_l` will change by atmost $O(q_i*S)$ for the $i^{th}$ block. So total changes on `cur_l` will be $O(SQ)$. 

2. Total changes of `cur_r`: For a fixed left block, the number of changes is $O(SQ)$. When we go from one block to another, number of changes is $O(N)$, therefore the total change will be $O(SQ + (N/S)N)$.

3. Total changes of `updatesTillNow`: For a fixed left, and fixed right block, `updatesTillNow` has free movement from $0$ to $Q-1$. So the number of changes = number of distinct block pairs * $Q$. The total number of changes becomes $O(Q * (N/S)^2)$.

So, complexity is $O((SQ + N^2/S + QN^2/S^2)F)$, where $O(F)$ is the complexity of the `add()` and `remove()` function. When $S$ is small, $S = 1$, the middle term is useless, similarly when $S$ is larger, $S = N$, the middle term is useless.

So complexity is $O(SQ + QN^2/S^2)$. Now to minimise this, we can use calculus and find the optimal block size, $S \approx N^{2/3}$. The number of blocks = $N/S$ = $N^{1/3}$.

`PS:` [Some source](https://codeforces.com/blog/entry/72690) says that $S = (2 * N^2)^{1/3}$ gets the best time complexity.