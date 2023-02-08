// File: AVLTree.cpp
// Author: S. Blythe
// Date: 1/2023
// Purpose: Implementation of an AVL tree 

#include "AVLTree.hpp"

#include <iostream>

using namespace std;

// insert newValue into tree
void
AVLTree::insert(int newVal)
{
  // no root? tree is just anew node. 
  if (!_root)
    _root = new AVLNode(newVal);

  // use AVLNode's insert to get the job done. 
  _root = _root->insert(newVal, _root);
}

// remove toDel from the tree
void
AVLTree::remove(int toDel)
{
  // no root? nothing to do. 
  if (!_root)
    return;
  else
    {
      // use AVLNode's remove method. 
      _root = _root->remove(toDel, _root);
    }
}

int depth; // used in helper to figure out indentation while displaying

// recursive helper for printing an AVL  (sub)tree
void helper(ostream &os, AVLNode *node)
{
  // no node? Nothing to print. 
  if (!node) return;

  // we're one mre node into recurseve depth, and therefore tree depth
  depth++;
  // print right child
  helper(os, node->right());

  // move bak "up" tree to print this node
  depth--;

  // print this node, but first move it "over" enough to show depth of node
  for (int i=0; i<depth; i++)
    os << "    ";
  // ue AVL Node's print to print the node
  node->print(os);
  os << endl;

  // now, move "down" again to print child. 
  depth++;
  
  // print right subtree
  helper(os, node->left());

  // all done with this subtree, go back to previous depth. 
  depth--;
}

// shows "tree" on stream os
ostream& 
AVLTree::display(ostream &os) const
{
  // initial depth is 0. 
  depth=0;

  // use recursive helper function to display tree ("subtree" rooted at _root)
  helper(os, _root);

  return os; 
}
