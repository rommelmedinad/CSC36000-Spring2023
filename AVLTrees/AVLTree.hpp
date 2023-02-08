#ifndef _AVL_TREE_HPP_
#define _AVL_TREE_HPP_

// File: AVLTree.hpp
// Author: S. Blythe
// Date: 1/2023
// Purpose: Definition of an AVL tree 

#include "AVLNode.hpp"

#include <iostream>

class AVLTree
{
private:
  AVLNode *_root;    // for a tree, all we need to know is its root
public:
  // default tree is empty
  AVLTree():_root(nullptr) {}

  // add a value to the tree
  void insert(int newVal);

  // rempove a value from the tree
  void remove(int val); 

  // "nicely" display the tree (sideways)
  std::ostream& display(std::ostream &os) const;
};
#endif
