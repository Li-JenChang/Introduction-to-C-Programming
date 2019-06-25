# Josephus Problem
There are n people forming a circle, numbered from 1 to n.

Starting from the number 1 person, kill every m-th person, and find out the last survival one.

## Algorithms
- Use an array to record the status of each person and mark the dead one
  - Time Complexity : O(n*log(n))
- Use circular linked list
  - Time Complexity : O(n)
- Use recursion to solve the specific case **_m = 2_**
  - Time Complexity : O(log(n))
