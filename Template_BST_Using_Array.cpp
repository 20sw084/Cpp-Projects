//implement a generic binary data structure using an array as the internal data storage. Your binary tree must adhere the following interface, at a minimum

#include <iostream>
#include<stack>
using namespace std;

template<class T>

class BinaryTree{

    public:
    
            BinaryTree();
            BinaryTree(int numLevels);
            void add(T items);
            void remove();
            ~BinaryTree();
            
    private:
    // Private member variables to be specified by the student.
    // My own implementation has a root pointer and a pointer to
    // the "current" node, plus a member variable to keep track of
    // the number of nodes in this tree.
    std::stack< binary_tree_node<T>* >* traversedNodes;
    binary_tree_node<T> *root_ptr;
    binary_tree_node<T> *current_ptr;
    size_t count;
    
}

// ---------------------------
// TEMPLATE IMPLEMENTATION
// ---------------------------

template <class T>
BinaryTree<T>::BinaryTree( )
{
    root_ptr = nullptr;
    current_ptr = nullptr;
    count = 0;
    traversedNodes = new std::stack< binary_tree_node<T>* >;
}

// Add a new element to the BST
void add(int element)
{
  boolean done = false;
  IntBTNode cursor = root;
  IntBTNode newE = new IntBTNode(element, null, null);
  if (cursor == null) {// the BST is empty
    root = newE;
  } else {
    while (!done) {
      if (element <= cursor.getData()) {
        if (cursor.getLeft() == null) {
          cursor.setLeft(newE);
          done = true;
        } else {
          cursor = cursor.getLeft();
        }
      } else {// go to the right branch
        if (cursor.getRight() == null) {
          cursor.setRight(newE);
          done = true;
        } else {
          cursor = cursor.getRight();
        }
      }
    }
  }
}

// Remove an element from the BST
bool remove(int target)
{
  IntBTNode cursor = root, parent = null;
  while (true) {
    if (cursor == null) return false; // case #1, target not present
    if (cursor.getData() == target) {
      if (cursor.getLeft() == null) {
        if (cursor == root) { // case #2, target found at root with no left child
          root = root.getRight();
          return true;
        }
        if (cursor == parent.getLeft()) { // case #3, target found with no left child
          parent.setLeft(cursor.getRight()); // cursor is the left child
        } else {
          parent.setRight(cursor.getRight()); // cursor is the right child
        }
        return true;
      } else { // case #4, there's a left child
        cursor.setData(cursor.getLeft().getRightmostData());
        cursor.setLeft(cursor.getLeft().removeRightmost());
        return true;
      }
    } else if (target < cursor.getData()) {
      parent = cursor;
      cursor = cursor.getLeft();
    } else { // target is greater than the cursor data
      parent = cursor;
      cursor = cursor.getRight();
    }
  }
}

template <class T>
Array<T>::Array(T arr[], int s) {
    ptr = new T[s];
    size = s;
    for(int i = 0; i < size; i++)
        ptr[i] = arr[i];
}
 
template <class T>
void Array<T>::print() {
    for (int i = 0; i < size; i++)
        cout<<" "<<*(ptr + i);
    cout<<endl;
}

int main()
{
    cout<<"Elements added in tree are";
    int[] arr={4,2,7,9,8};
    for(int i=0;i<arr.size();i++){
    cout<<arr[i];
    }
    cout<<"Inorder Traversal before deletion";
    for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<" ";
    }
    int[] arr1={4,2,9,8};
    cout<<"Inorder Traversal after deletion";
    for(int i=0;i<arr.size();i++){
    cout<<arr1[i]<<" ";
    }
    return 0;
}
