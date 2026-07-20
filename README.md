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

## Edge Cases Considered

---

## Project Structure

```
.
├── README.md
└── 
```

---

## Language Used

> C++


---

## Author

**Vikas Singh**
