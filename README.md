# push_swap

**push_swap** is a sorting algorithm project from 42, where the challenge is to sort a stack of integers using **two stacks** (`A` and `B`) and a **limited set of operations**:  
- `sa`, `sb`, `ss` → swap  
- `pa`, `pb` → push  
- `ra`, `rb`, `rr` → rotate  
- `rra`, `rrb`, `rrr` → reverse rotate  

## The goal:
- Sort the numbers in as few moves as possible.  
- No cheating with `qsort` — you must build your own strategy.  

---

## ✨ How My Algorithm Works

My algorithm runs in **two phases**:

### 1. Splitting into chunks
- Start with stack `A` filled with all numbers.  
- Rotate through (`ra`) and selectively push numbers to stack `B` (`pb`) in **sorted chunks**.  
- This gradually moves the smaller values out of `A` and prepares them for reinsertion.  

---

### 2. Sorting back
- Once stack `B` is full, push everything back into `A` (`pa`) in descending order.  
- While reinserting, correct positions with swaps (`sa` / `ss`) and rotations (`ra` / `rra`).  
- This ensures that `A` ends up perfectly sorted from smallest → largest.  

---

### 3. Final Result
After the full sequence of operations:  
- ✅ Stack `A` is completely sorted  
- ✅ Stack `B` is empty  

---

## ✨ Features

- Handles small inputs (3–5 numbers) with optimized mini-sorts

- Efficient for 100 and 500 numbers using chunk strategy

- Visual and traceable sequence of moves

- A fun brain-teaser in algorithm design

