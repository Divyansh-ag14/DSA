/*  
    Heap is a special Tree-based data structure in which the tree is a complete binary tree. 
    Generally, Heaps can be of two types:

    Max-Heap: In a Max-Heap the key present at the root node must be greatest among the keys present at all of it’s children. 
              The same property must be recursively true for all sub-trees in that Binary Tree.
    
    Min-Heap: In a Min-Heap the key present at the root node must be minimum among the keys present at all of it’s children. 
              The same property must be recursively true for all sub-trees in that Binary Tree.


    complete tree: all the levels are completely filled except possibly the last level and the last level has all keys as left as possible 

    applications:
    1. heapsort
    2. graph algos like prim's and dijkstra's
    3. priority queue
    
    (it is genrally implemented using array)
    arr[0] - root 
    arr[(i-1)/2] - parent
    arr[(2*i)+1] - left child
    arr[(2*i)+2] - right child

    operations:
    1.1 getMin() - returns the root element of min heap, T: O(1);
    1.2 getMax() - returns the root element of max heap, T: O(1);

    2.1 extractMin() - removes the min element from min heap, T: O(logn)
        (min heap property is maintained after extraction, by calling heapify())

    2.2 extractMax() - removes the max element from max heap, T: O(logn)
        (max heap property is maintained after extraction, by calling heapify())
    
    3.  insert() - key is inserted at the end and then heapify is called to satisy min/max heap, T: O(logn)
    
    4.  delete() - to delete a key, replace it with INT_MIN/MAX (based on min/max heap) by calling decreaseKey()/
        increaseKey() then call heapify so that key bceomes the root, and then extract it using 2.1/2.2

    5.  heapify() - process of creating a heap data strcuture from a binary tree
        used to create min/max heap
*/

