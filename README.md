# moglix-online-assignment
Programming assignment for hiring process.


## Problem Statement

### Longest Valid Parentheses

> Given a string s containing only the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

>A valid parentheses substring is one in which every opening parenthesis '(' has a corresponding closing parenthesis ')' in the correct order.
---

## Examples

### Example 1

**Input**

```text
s = "(()"
```

**Output**

```text
2
```

**Explanation**

The longest valid parentheses substring is `"()"`.

---

### Example 2

**Input**

```text
s = ")()())"
```

**Output**

```text
4
```

**Explanation**

The longest valid parentheses substring is `"()()"`.

---

## Brute Force Approach

The brute force approach is based on checking **every possible substring** of the given string and determining whether it forms a **valid parentheses sequence**.

### Steps

1. Generate all possible substrings using **two nested loops**:
   - The outer loop selects the **starting index** of the substring.
   - The inner loop selects the **ending index** of the substring.

2. For each generated substring:
   - Traverse it character by character.
   - Maintain a counter:
     - Increment the counter for every `'('`.
     - Decrement the counter for every `')'`.
   - If the counter becomes **negative** at any point, the substring is invalid because there are more closing parentheses than opening parentheses.
   - After traversing the entire substring, it is considered **valid** only if the counter is exactly `0`, indicating that every opening parenthesis has a matching closing parenthesis.

3. If the current substring is valid, update the maximum length found so far.

4. After checking all possible substrings, return the maximum valid substring length.

---

## Algorithm

1. Initialize `maxLength = 0`.
2. Generate every possible substring of the input string.
3. For each substring:
   - Check whether it is a valid parentheses sequence.
   - If it is valid, update `maxLength` with the larger of the current maximum and the substring's length.
4. Return `maxLength`.

---

## Time Complexity

| Operation | Complexity |
|-----------|------------|
| Generating all substrings | O(n²) |
| Checking each substring| O(n) |
| Overall | O(n³) |

---

## Space Complexity

| Memory Usage | Complexity |
|--------------|------------|
| Extra Space | O(n) |

---

## Optimal Approach (Using Stack)

The optimal solution uses a **stack** to efficiently track the indices of unmatched parentheses while traversing the string only once.

Instead of storing the parentheses themselves, the stack stores their **indices**. This allows us to calculate the length of a valid substring whenever a matching pair is found.

### Why do we push `-1` initially?

Before starting the traversal, we push `-1` onto the stack.

- It acts as a **base index** for calculating the length of valid substrings.
- It correctly handles cases where a valid substring starts from index `0`.

For example:

```text
s = "()()"
```

When the first valid pair is found at index `1`, its length is:

```text
1 - (-1) = 2
```

Without `-1`, this calculation would not be possible.

---

## Steps

1. Create an empty stack and push `-1` onto it.
2. Traverse the string from left to right.
3. If the current character is `'('`, push its index onto the stack.
4. If the current character is `')'`:
   - Pop the top element from the stack.
   - If the stack becomes empty after popping, push the current index onto the stack. This index becomes the new base for future valid substrings.
   - Otherwise, calculate the length of the current valid substring as:

     ```text
     current_index - stack.top()
     ```

     Update the maximum length if this value is larger than the current maximum.
5. After processing all characters, return the maximum length.

---

## Algorithm

1. Initialize an empty stack.
2. Push `-1` onto the stack.
3. Initialize `maxLength = 0`.
4. Traverse the string:
   - If the current character is `'('`, push its index.
   - Otherwise:
     - Pop the stack.
     - If the stack is empty:
       - Push the current index.
     - Else:
       - Update `maxLength = max(maxLength, current_index - stack.top())`.
5. Return `maxLength`.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - Each index is pushed onto and popped from the stack at most once.

- **Space Complexity:** `O(n)`
  - In the worst case (all `'('`), the stack stores all indices.


---

## Project Structure

```
.
├── README.md
└── solution.cpp
```

---

## Language Used

> C++


---

## Author

**Vikas Singh**
