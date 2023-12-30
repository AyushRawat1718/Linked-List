# Constructors and Destructors

## Constructors

### Object declaration and memory allocation

When an object is created, the constructor is automatically called. Behind the scenes, two essential steps occur:

Memory allocation: The compiler allocates the necessary memory to hold the object's data members. This guarantees that the object has a physical space in memory to store its values.


Initialization of data members: The constructor then initializes the object's data members to their appropriate starting values, establishing its initial state.

## Destructors

### Memory deallocation and cleanup

When an object is no longer required, either due to going out of scope or being explicitly deleted using the delete keyword, the destructor is invoked. Its primary tasks are:

Deallocating memory: The destructor releases the memory that was originally allocated for the object, making it available for other uses in the program. This prevents memory leaks, which occur when unused memory is not properly freed.


Performing cleanup tasks: The destructor also provides an opportunity to perform any necessary cleanup actions, such as:
Closing files or network connections that were opened by the object.

Releasing external resources that were acquired by the object.

Handling any special data structures or dependencies that require proper termination.

## Linked Lists and Destructors

### Crucial role in preventing memory leaks

In the context of linked lists, destructors play a pivotal role in preventing memory leaks. The destructor of a linked list node typically performs the following actions:

Deleting dynamically allocated data within the node: If the node contains data that was allocated using new, the destructor must explicitly release that memory using delete.

Recursively deleting subsequent nodes: To ensure complete memory deallocation, the destructor of a linked list node typically calls the destructor of the next node in the list. This recursive process continues until all nodes in the list have been properly deleted and their memory freed.

Therefore before deleting the any node from a linked list we must update its next pointer to NULL, to avoid deletion of undesirable nodes.

Updating pointers to avoid dangling references: The destructor also carefully updates any pointers within the linked list structure to avoid dangling references, which can lead to program crashes or other issues.