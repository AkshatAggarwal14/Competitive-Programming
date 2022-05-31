/*
    a: "heap"
    b: "pea"

    Convert a to b, how many characters to insert/delete.
    as we want to convert a to b,
    first convert a to LCS,
    thus DELETIONS = len(a) - len(LCS) // "heap" to "ea" [2]
    INSERTIONS = len(b) - len(LCS)       // "ea" tp "pea" [1]
*/

/*
    If minimum insertions/deletions to make palindrome then use LPS, instead of LCS
*/