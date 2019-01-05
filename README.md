# FUNDAMENTALS

This repository marks my personal journey to learn and implement the most basic ingredients of a program - algorithms and data structures.

## Reference

- [coursera algorithm part 1](https://www.coursera.org/learn/algorithms-part1)
- [leetcode](https://leetcode.com/problemset/all/)

## Asymptotic Analysis

### (Running) Time

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

### (Memory) Space

For primitives it is a fixed byte size; for arrays it is the size of each item multiplied by N; for an object it must include overhead, reference and padding.

## Setup

Check [this](https://conda.io/docs/user-guide/install/index.html) out to install Miniconda.

```bash
# create environment
conda create -n fundamentals python=3.6

# activate environment
conda activate fundamentals

# install jupyter
conda install jupyter
conda install nb_conda_kernels

# start notebook
jupyter notebook

# install dependencies
conda install --yes --file requirements.txt
```
