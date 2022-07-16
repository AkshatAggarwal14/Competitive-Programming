# What is a Trie?
Trie data structure is a tree-based data structure used for storing collections of strings. The word trie comes from the word _re**TRIE**val_ which means to find or get something back. 

_It can also be used to store numbers in form of binary strings._

If two strings have a common prefix then they will have the same ancestor in the trie. In a trie data structure, we can store a large number of strings and can do search operations on it in an efficient way. 

A trie can be used to sort a collection of strings alphabetically as well as search whether a string with a given prefix is present in the trie or not. A dictionary can be implemented efficiently with the help of a trie data structure.

# Why use Trie?
- A trie data structure can be used to implement a wide range of features that can't be implemented with a hash table. For example, Prefix-based searching can't be done with a hash table.
- There are no collisions in a trie data structure which means a better worst-case time complexity than a hash table that is not implemented properly.
- Hash functions are not used in a Trie data structure.
- Searching of a string in a Trie data structure is done in $O(k)$ time complexity. Where k is the number of words in the query string. It may also take less than $O(k)$ time when the query string is not present in the trie.

# Structure of Trie:

The structure of a trie is like that of a tree. 

Each trie consists of a root node. The root node branches into various child nodes having multiple edges. Each TrieNode consists of an array of pointers where every index of the array represents a character. 

Each node of a trie represents a string and each edge represents a character. The root node is an empty string. 

Each node except the root node is a string having characters along the path from the root to that node.


<p align="center">
  <img src="images/struct.webp" alt=""/>
</p>

Every level of the Trie data structure represents a prefix of a given length. If we consider the root node to be at level 0. Then the root node represents a prefix of length 0 or an empty string. Level 1 of the Trie represents a prefix of length 1 and so on.

Another important thing to note is that every string in the Trie data structure is sorted lexicographically from left to right. We will learn how to implement it while discussing the insert operation in a Trie.

# Real world applications:
1. **Autocomplete Feature** - Trie data structures are commonly used in implementing the autocomplete features that we see in search engines. If we type a prefix of the desired string then we will see suggestions of many strings that will have the same prefix. This can be efficiently implemented with the help of a Trie as in a Trie the strings having a common prefix share the same ancestors. We can then search at levels below these ancestors and show suggestions based on the popularity of different strings that we come across.
2. **Spell Checkers** - Spell Checkers check whether the typed word is present in the dictionary or not. If the word is not present in the dictionary then it shows suggestions based on the typed word. It may also sort the suggestions based on their popularity. A dictionary can be efficiently implemented using a Trie. Using a Trie makes it easy to search a string in a Trie as well as show suggestions based on a given word.
3. **String Matching Algorithms** - Trie data structures can also be used in string matching algorithms to match a given pattern among a collection of strings.

# Disadvantage of Trie Data Structure:
The main disadvantage with Trie is that they take a lot of memory for storing strings as compared to other data structures. This is because each node consists of an array of pointers for the child nodes and also contains some additional variables like the `wordEndCnt` variable we used in the TrieNode structure.
