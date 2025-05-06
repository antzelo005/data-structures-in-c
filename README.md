# Data Structures in C

Αυτό το project περιέχει υλοποιήσεις βασικών δομών δεδομένων σε C, μαζί με αντίστοιχα παραδείγματα χρήσης (`main.c`).

## 🔧 Compilation Instructions

Για κάθε δομή μπορείς να μεταγλωττίσεις και να τρέξεις το αντίστοιχο αρχείο `main.c` με την παρακάτω εντολή:

```bash
gcc -o executable_name source.c main.c
./executable_name

Παραδείγματα:

🔹 Stack
gcc -o stack stack/stack.c stack/main.c
./stack

🔹 Queue (Simple)
gcc -o queue queue/queue.c queue/main.c
./queue

🔹 Circular Queue
gcc -o cqueue circular_queue/queue.c circular_queue/main.c
./cqueue

🔹 Linked List
gcc -o list list/list.c list/main.c
./list

🔹 Binary Tree
gcc -o tree tree/tree.c tree/main.c
./tree

🔹 Min Heap
gcc -o heap HeapTree/heap.c HeapTree/main.c
./heap

🔹 Binary Search Tree (BST)
gcc -o bst BSTree/BST.c BSTree/main.c
./bst

🔹 AVL Tree
gcc -o avl AVLTree/avl.c AVLTree/main.c
./avl

🔹 Graph
gcc -o graph Graph/graph.c Graph/main.c
./graph


📁 Project Structure:
project/
├── MyStack/
│   ├── stack.c
│   ├── stack.h
│   └── main.c
├── MyQueue/
│   ├── queue.c
│   ├── queue.h
│   └── main.c
├── CircularQueue/
│   ├── queue.c
│   ├── queue.h
│   └── main.c
├── LinkedList/
│   ├── list.c
│   ├── list.h
│   └── main.c
├── Tree/
│   ├── tree.c
│   ├── tree.h
│   └── main.c
├── HeapTree/
│   ├── heap.c
│   ├── heap.h
│   └── main.c
├── BSTree/
│   ├── BST.c
│   ├── BST.h
│   └── main.c
├── AVLTree/
│   ├── avl.c
│   ├── avl.h
│   └── main.c
├── Graph/
│   ├── graph.c
│   ├── graph.h
│   └── main.c
├── .gitignore
└── README.md



📄 .gitignore
# Object files and binaries
*.o
*.out
*.exe

# macOS
.DS_Store

# Backup/editor files
*~


ℹ️ Σημειώσεις
🔹Όλες οι δομές είναι ανεξάρτητες και υλοποιημένες σε ξεχωριστούς φακέλους.

🔹Δεν χρησιμοποιείται Makefile. Όλα τα παραδείγματα μεταγλωττίζονται με gcc.