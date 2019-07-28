# FUNDAMENTALS

This repository marks my personal journey to learn and implement the most basic ingredients of a program - algorithms and data structures.

## References

- [coursera algorithm part 1](https://www.coursera.org/learn/algorithms-part1)
- [leetcode](https://leetcode.com/problemset/all/)
- [introduction to algorithms](https://en.wikipedia.org/wiki/Introduction_to_Algorithms)
- [deep learning](https://www.deeplearningbook.org/)

## Asymptotic Analysis

To measure the performance of an algorithm, we need to look at its running time and memory space size.

### Time

| order of growth | name         | example                      |
| --------------- | ------------ | ---------------------------- |
| 1               | constant     | one expression               |
| log N           | logrithmic   | divide by half               |
| N               | linear       | one loop                     |
| N log N         | linearithmic | divide and conquer           |
| N^2             | quadratic    | one loop inside another loop |
| N^3             | cubic        | triple nested loops          |
| 2^N             | exponential  | brute force search           |

| notation | name      | description                |
| -------- | --------- | -------------------------- |
| ~ N      | tilde     | approximate, leading terms |
| Θ(N)     | big theta | order of growth            |
| O(N)     | big oh    | upper bound, worst case    |
| Ω(N)     | big omega | lower bound, best case     |

If one algorithm has the same (or wihtin constant factor) upper bound and lower bound, we say it is optimal.

### Space

For primitives it is a fixed byte size; for arrays it is the size of each item multiplied by N; for an object it must include overhead, reference and padding.