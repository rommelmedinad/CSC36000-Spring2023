#ifndef _AVL_NODE_HPP_
#define _AVL_NODE_HPP_

// File: AVLNode.hpp
// Author: S. Blythe
// Date: 1/2023
// Purpose: Definition of an AVL node for an AVL tree

#include <iostream>

class AVLNode
{
private:
  int _val;        // actual value stored in AVL Node
  AVLNode *_left;  // pointer to node's left child (may be null)
  AVLNode *_right; // pointer to node's right child (may be null)
  int _height;     // height of subtree rooted at this node. 
public:
  // basic constructor for a node. Has no children, so height is 1
  AVLNode(int val):_val(val), _left(nullptr), _right(nullptr), _height(1) {}

  // accessors/modifiers for instance variables. 
  int value() const {return _val;}
  int& value() {return _val;}
  
  AVLNode* left() const {return _left;}
  AVLNode* &left() {return _left;}

  AVLNode* right() const {return _right;}
  AVLNode* &right() {return _right;}

  int height() const {return _height;}
  int &height()  {return _height;}

  // is this a leaf node (with no children)? 
  bool isLeaf() const {return !_left && !_right;}
  
  // print out node value and heights of children 
  std::ostream& print(std::ostream &os) const;
  
  // insert value into subtree rooted at this node
  AVLNode* insert(int newVal, AVLNode *intoSubTree);

  // remove value from subtree rooted at this node
  AVLNode* remove(int exstingVal, AVLNode *fromSubTree); 

  // overload << to display this node (not entire subtree rooted at node)
  friend  std::ostream& operator<<(std::ostream &os, const AVLNode &n); 
};

#endif
