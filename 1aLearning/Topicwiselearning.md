### Bit Manipulation

- If we observe closely, we notice the result of XOR is 1 when the number of 1 bits is odd and 0 otherwise.

### String

- A substring is a contiguous sequence of characters in a string.

### Bit Masking

#### Setting bits:

- You can set specific bits in a binary number using a bitmask and the bitwise OR (|) operator. For instance, to set the third bit of a number x, you can use x |= (1 << 2).

#### Clearing bits:

- To clear (unset) specific bits, you use a bitmask and the bitwise AND (&) operator with the complement of the bitmask. For example, to clear the second bit of a number x, you can use x &= ~(1 << 1).

#### Checking bits:

- Bitmasks are also used to check whether specific bits are set or unset. This is done using the bitwise AND (&) operator with the bitmask. For instance, to check if the fourth bit of a number x is set, you can use if (x & (1 << 3)) { /_ Bit is set _/ }.

#### Toggle bits:

- You can toggle (flip) specific bits using a bitmask and the bitwise XOR (^) operator. For example, to toggle the fifth bit of a number x, you can use x ^= (1 << 4).

### Sorting

- Sorting the array takes O(n log n) time using an efficient sorting algorithm like quicksort or mergesort.

### A new Data structure? Bitset

- bitset<2048> b;

### Disjoint Substrings in a String (Contest)
- **"ab" and "cb" are distinct** because they are different strings.  
- **"ab" and "cb" are NOT disjoint** if they overlap (e.g., in "abc", "ab" and "cb" share 'b').  
- They **are disjoint** if taken from different parts of a string without overlap (e.g., in "abxycb").
