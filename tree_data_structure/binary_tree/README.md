# Binary Tree Representation

## Array Representation of a Binary Tree
A binary tree can be efficiently represented using an array, especially for a **complete binary tree**, where all levels are fully filled except possibly the last level, which is filled from left to right.

### Index Relationships (0-Based Indexing):
1. **Left Child Index:** 
   - Formula: `2 * parent_index + 1`
   
2. **Right Child Index:**
   - Formula: `2 * parent_index + 2`

3. **Parent Index:**
   - Formula: `(child_index - 1) / 2` (integer division)

### Example of Array Representation:
For the binary tree:
```
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
```
The array representation will be:
```
[1, 2, 3, 4, 5, 6, 7]
```

---

## Full and Complete Binary Trees

### Full Binary Tree:
A binary tree is a **full binary tree** if every node has 0 or 2 children. This means:
- All non-leaf nodes have exactly two children.
- Leaf nodes have no children.

Example of a full binary tree:
```
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
```

### Complete Binary Tree:
A binary tree is a **complete binary tree** if:
- All levels, except possibly the last, are completely filled.
- The last level has all its nodes as far left as possible.

Example of a complete binary tree:
```
        1
      /   \
     2     3
    / \   / \
   4   5 6
```

---

## Linked List Representation of a Binary Tree
In this representation, each node contains the data and pointers to its left and right children.

### Example:
For the binary tree:
```
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
```
Each node points to its left and right children.

---

## Comparison of Representations
| Feature                  | Array Representation       | Linked List Representation |
|--------------------------|----------------------------|----------------------------|
| **Efficiency**           | Best for complete trees    | Best for sparse trees       |
| **Memory Usage**         | Fixed (depends on depth)   | Dynamic (depends on nodes)  |
| **Traversal Speed**      | Fast (index-based)         | Slower (pointer-based)      |
| **Flexibility**          | Limited                   | High                        |

---

In conclusion, the choice of representation depends on the type of binary tree and the operations being performed. For complete binary trees, an array is ideal, while a linked list works better for sparse or dynamically structured trees.

