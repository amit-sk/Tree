C++ Implementation of Phylogenetic Tree, using smart pointers, where each node holds a pointer to its parent node, and list to all subnodes ("doubly linked").

Another possible implementation could be that the vector of subnodes (children) is of unique_ptrs, and the parent pointer is a raw pointer. This could be more efficient in terms of runtime, but opens the user up for object lifetime errors.
