# 42push_swap
Implementing a sorting algorithm in C using stack data structure.

### Description
The goal of this project is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you'll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.

- **push_swap** - calculates and displays on the standard output the smallest progam using Push_swap instruction language that sorts integer arguments received.

---

### Motivation
We thought creating our own algorithm to sort data would be a fun challenge.
After a lot of trial and error we finally came up with a solution that works.
The final verson of the algorithm is a many many iterations of the initial idea.
We learned a lot about how to optimize code and how to use the stack data structure.
This project helped us to improve our problem-solving skills, our ability to work in a team
and algorithmical thinking.

---

### Moves allowed to be performed on the stack
- **`sa`** - swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- **`sb`** - swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- **`ss`** - sa and sb at the same time.
- **`pa`** - push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- **`pb`** - push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- **`ra`** - rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- **`rb`** - rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- **`rr`** - ra and rb at the same time.
- **`rra`** - reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- **`rrb`** - reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- **`rrr`** - rra and rrb at the same time.

---

## Algorithm (Almighty Push Swap)
<img width="622" alt="Screenshot 2023-11-12 at 18 31 42" src="https://github.com/rajh-phuyal/42push_swap/assets/81531002/abb3b4e9-4913-47c8-8b68-c1c5d8aefb10">


### Preparing for the algorithm
The algorithm is based on the idea of sorting the data in chunks.
The size of the chunks is calculated based on the size of the stack.
(write a desc for the table beloow)
| Size of stack | Chunksize | Number of chunks | Remaining nodes on stack A|
| :-----------: | :-----------: | :-----------: | :-----------: |
| 100 | 12 | 8 | 4 |
| 500 | 35 | 14 | 10 |

For the rest of the other size for stack we use the following formula:
```
number of chunks = 10 % of stacksize
chunksize = stacksize / number of chunks
```

### Terminology
- **APS** - Almighty Push Swap
- **Stack** - A stack of numbers.
- **Node** - A number in the stack.
- **Stack A** - The stack that contains the numbers to be sorted.
- **Stack B** - The stack that is used to sort the numbers.
- **Chunk** - A group of numbers that are sorted in ascending order.
- **Chunksize** - The size of the chunk.
- **Number of chunks** - The number of chunks in the stack.
- **Edges** - The first and the last nodes of the stack being the edge.
- **Direction** - From the middle if the node is closer to the top, its North else its South.
- **Cost** - The cost of sending a node to the top of the stack and to the other stack.


### The algorithm
Starting from the two smallest chunks, APS tries to find lowest cost for the nodes of those chunks.
APS makes three comparisons for the nodes of the chunks:
```
1. The cost of the node nearest to the top edge and the node nearest to the bottom edge for the first chunk.
2. The same for the second chunk.
3. The comparision between the least costly nodes from both chunks.
```

Now, APS has the least costly node to send to the stack B.
Based on the proximity of the node form either edge (North or South), APS either does
`ra` or `rra` to the node until it is at the top of stack A and can be pushed to stack B.

Here is the stack b part of the algorithm

APS repeats the above steps until the stack A less the 4 nodes.

The cost of each of the nearest nodes from both chunks from the edge is taken into account the the least costly node is chosen.


### Exception (Small Data Set <= 5 numbers)
```
something here
```

---

### Installation && Usage
1. Clone the repo
```sh
git clone
```
2. Run make in the root directory
```sh
make
```
3. Run the program
```sh
./push_swap 1 2 3 4 5
```

