
# CSE 4304: Data Structures Lab
## Lab 2: Linked Lists

**Semester:** Winter 2025–26  
**Group:** B

---

## Instructions

- Name each file `<ID>_T<task>_L02_B.cpp` (or `.c`).
- Example: `123456789_T01_L02_B.cpp` for Task 1.
- You may use the C++ Standard Library (STL) unless a task says otherwise.
- Be mindful of input constraints and time limits.

---

## Linked List Quick Reference

### 1. A Node

A node of a singly linked list holds a value and a pointer to the next node.

```cpp
struct Node {
    int data;
    Node *next;
};

Node a;
a.data = 10;
a.next = NULL;
```

In C, use `struct Node` instead of `Node`.

### 2. Pointers and `->`

A pointer holds the address of a node. `p->data` accesses the data field of the node that `p` points to. It is equivalent to `(*p).data`.

```cpp
Node *p = &a;
p->data = 20;

p = p->next;

if (p != NULL) {
    printf("%d\n", p->data);
}
```

- `NULL` means the pointer points to no node.
- The last node's `next` pointer is `NULL`.
- `head` is `NULL` when the list is empty.
- Always check whether a pointer is `NULL` before accessing its members.

### 3. `new` and `delete`

In C++, `new` creates a node and returns its address. The node remains allocated until it is deleted.

```cpp
Node *p = new Node;
p->data = 7;
p->next = NULL;

delete p;
```

In C, use `malloc()` and `free()` instead.

---

# Task 1: Playlist Edits

**Time Limit:** 1 second  
**Memory Limit:** 256 MB

## Problem Statement

A playlist of song numbers starts empty. You are given `q` instructions, one per line.

Each instruction is one of the following:

| Instruction | Operation |
|---|---|
| `F x` | Add song `x` at the front of the playlist. |
| `B x` | Add song `x` at the back of the playlist. |
| `I k x` | Insert song `x` at position `k`. Existing songs from position `k` onward move one place back. If the playlist has fewer than `k - 1` songs, do nothing. |
| `R k` | Remove the song at position `k`. If the playlist has fewer than `k` songs, do nothing. |
| `D x` | Remove the first occurrence of song `x`. If `x` is not present, do nothing. |
| `S x` | Print the position of the first occurrence of song `x`. Print `0` if it is not present. |
| `P` | Print the playlist from the first song to the last, or `empty` if there are no songs. |

Carry out the instructions in order.

Store the playlist in a **singly linked list that you implement yourself**.

Do not use `std::list`, `std::vector`, or an array to hold the playlist.

## Input

- The first line contains an integer `q` (`1 ≤ q ≤ 1000`) — the number of instructions.
- Each of the next `q` lines contains one instruction.
- `1 ≤ k ≤ 1000`
- `1 ≤ x ≤ 10^6`

At least one instruction is `S` or `P`.

## Output

For each `S` and `P` instruction, print its answer on its own line.

## Examples

### Example 1

**Input**
```text
10
B 10
B 20
F 5
I 3 15
P
D 20
S 15
R 1
S 99
P
```

**Output**
```text
5 10 15 20
3
0
10 15
```

### Example 2

**Input**
```text
6
P
R 1
D 7
I 2 7
I 1 7
P
```

**Output**
```text
empty
7
```

---

# Task 2: Merge Rosters

**Time Limit:** 1 second  
**Memory Limit:** 256 MB

## Problem Statement

There are two attendance lists for the same class. Each list holds student IDs sorted from smallest to largest, with no ID appearing twice in the same list.

A student can appear on both lists.

Build the combined list containing every student who appears on at least one of the two lists, exactly once, sorted from smallest ID to largest.

Store each list in a **singly linked list that you implement yourself**.

Do not use `std::list`, `std::vector`, or an array to hold the lists.

Build the combined list using the existing nodes from the two lists by changing their `next` pointers.

**Do not create new nodes after reading the input.**

## Input

- The first line contains two integers `n` and `m` (`1 ≤ n, m ≤ 10^5`) — the lengths of the two lists.
- The second line contains `n` integers — the IDs in the first list, sorted in ascending order.
- The third line contains `m` integers — the IDs in the second list, sorted in ascending order.
- Every ID is between `1` and `10^9`.

## Output

- Print a single integer `c` — the number of students in the combined list.
- On the next line, print the `c` IDs of the combined list in ascending order.

## Examples

### Example 1

**Input**
```text
3 3
101 104 107
102 104 110
```

**Output**
```text
5
101 102 104 107 110
```

### Example 2

**Input**
```text
2 4
5 9
1 5 9 12
```

**Output**
```text
4
1 5 9 12
```

---

# Task 3: Count Off

**Time Limit:** 1 second  
**Memory Limit:** 256 MB

## Problem Statement

There are `n` students standing in a line.

They count off from `1` to `k`, starting from the front of the line and continuing toward the back. The first student says `1`, the second says `2`, and so on up to `k`. The next student starts again from `1`.

Students who say the same number belong to the same team.

Rebuild the line so that:

- Team 1 comes first.
- Team 2 comes next.
- Continue until Team `k`.
- Each team preserves its original relative order.

Store the line in a **singly linked list that you implement yourself**.

Do not use `std::list`, `std::vector`, or an array to hold the line.

Move the existing nodes by changing their `next` pointers.

**Do not copy IDs from one node to another.**

## Input

- The first line contains two integers `n` and `k` (`1 ≤ k ≤ n ≤ 10^5`) — the number of students and the number of teams.
- The second line contains `n` distinct integers between `1` and `10^9` — the student IDs in their original order.

## Output

Print the `n` IDs of the rearranged line from front to back.

## Examples

### Example 1

**Input**
```text
7 3
101 102 103 104 105 106 107
```

**Output**
```text
101 104 107 102 105 103 106
```

### Example 2

**Input**
```text
6 2
10 20 30 40 50 60
```

**Output**
```text
10 30 50 20 40 60
```

### Example 3

**Input**
```text
4 4
8 3 6 1
```

**Output**
```text
8 3 6 1
```

## Note

In Example 1:

- **Team 1:** 101, 104, 107
- **Team 2:** 102, 105
- **Team 3:** 103, 106

Each team preserves the original order of its members.

---

**End of Lab 2 — Group B**
