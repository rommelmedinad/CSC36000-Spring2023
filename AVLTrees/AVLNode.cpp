#include "AVLNode.hpp"

#include <iostream>

// File: AVLNode.cpp
// Author: S. Blythe
// Date: 1/2023
// Purpose: Implementation of an AVL node for an AVL tree

using namespace std;

// prototypes fro single rotation functions
AVLNode* rotateWithLeftChild(AVLNode *k2);
AVLNode* rotateWithRightChild(AVLNode *k2);

// method to figure out the height of a node ... EVEN IF IT IS NULL!
int getHeight(AVLNode *n)
{
  // if node does not exist
  if (!n) // (n==NULL)
    {
      return 0; // no node? then height is 0.
    }
  else
    {
      // conveniently, we kept the height with te node. 
      return n->height();
    }
}

// to display a node, print its vakue and the heights of its children
std::ostream&
AVLNode::print(std::ostream &os) const
{
  os << _val
     << " (" << getHeight(_left) << "<->" << getHeight(_right) << ")";
  return os;
}

// a single rotation , pulling up left child
//  k2 - the current root. 
//  returns the new root. 
AVLNode* rotateWithLeftChild(AVLNode *k2)
{
  // NOTE: See course notes for picture of what k1 and k2 (and Y) mean here
  AVLNode *k1 = k2->left();
  k2->left() = k1->right(); // Y
  k1->right() =  k2;

  // we just moved things around. Update associated subtree heights. 
  k2->height() = 1 + max (getHeight(k2->left()), getHeight(k2->right()) );
  k1->height() = 1 + max (getHeight(k1->left()), getHeight(k2) );

  return k1;
}

// the first of our double rotation options, pulling from left
//   k3 - the current root of subtree
//   returns new subtree
AVLNode* doubleWithLeftChild(AVLNode *k3)
{
  AVLNode *k1 = k3->left();
  k3->left() = rotateWithRightChild(k1);
  return rotateWithLeftChild(k3);
}

// a single rotation , pulling up right child
//  k2 - the current root. 
//  returns the new root. 
AVLNode* rotateWithRightChild(AVLNode *k2)
{
  // NOTE: See course notes for picture of what k1 and k2 (and Y) mean here
  AVLNode *k1 = k2->right();
  k2->right() = k1->left(); // Y
  k1->left() =  k2;

  // we just moved things around. Update associated subtree heights. 
  k2->height() = 1 + max (getHeight(k2->left()), getHeight(k2->right()) );
  k1->height() = 1 + max (getHeight(k1->right()), getHeight(k2) );

  return k1;
}

// the first of our double rotation options, pulling from right
//   k3 - the current root of subtree
//   returns new subtree
AVLNode* doubleWithRightChild(AVLNode *k3)
{
  AVLNode *k1 = k3->right();
  k3->right() = rotateWithLeftChild(k1);
  return rotateWithRightChild(k3);
}


// insert newVal into (sub)tree rooted at intoSubTree
AVLNode*
AVLNode::insert(int newVal, AVLNode *intoSubTree)
{
  // no subtree? we found the right place to insert (base case of recursion)
  if (intoSubTree==nullptr)
    {
      AVLNode *newRoot = new AVLNode(newVal);
      return newRoot;
    }

  // do we need to insert into left subtree? 
  else if (newVal < intoSubTree->_val)
    {
      // recursively insert into left subtree. 
      intoSubTree->_left=insert(newVal, intoSubTree->_left);

      // might need AVL rotations ... look at children's heights to decide
      int leftHeight = getHeight(intoSubTree->_left);
      int rightHeight = getHeight(intoSubTree->_right);

      // left imbalance
      if (leftHeight-rightHeight==2) 
	{
	  // is this a left-left imbalance?
	  if (newVal < intoSubTree->_left->_val )
	    {
	      intoSubTree=rotateWithLeftChild(intoSubTree);
	    }
	  // or is it a left-rght imabalance?
	  else
	    {
	      intoSubTree=doubleWithLeftChild(intoSubTree);
	    }
	}
    }
  // not a left insert, so try to insert in right subtree.
  else if (newVal > intoSubTree->_val)
    {
      // recursively insert into right subtree
      intoSubTree->_right=insert(newVal, intoSubTree->_right);

      // might need AVL rotations ... look at children's heights to decide
      int leftHeight = getHeight(intoSubTree->_left);
      int rightHeight = getHeight(intoSubTree->_right);

      // check for right imbalance
      if (rightHeight-leftHeight==2) 
	{
	  // is this a right-right imbalance?
	  if (newVal >  intoSubTree->_right->_val )
	    {
	      intoSubTree=rotateWithRightChild(intoSubTree);
	    }
	  // or is it a right-left imabalance?
	  else
	    {
	      intoSubTree=doubleWithRightChild(intoSubTree);
	    }
	}
    }
  else // node value already in tree (==)
    {
    }

  // now that we've mved things areound, need to update this nodes height. 
  intoSubTree->height() = 1 + max(getHeight(intoSubTree->left()),
				  getHeight(intoSubTree->right()) ); 

  // return new subtree
  return intoSubTree;
}

// remove existingVal from subtree rooted at fromSubTree
AVLNode*
AVLNode::remove(int existingVal, AVLNode *fromSubTree)
{
  // no subtree? no need to remove anything. 
  if (!fromSubTree)
    return nullptr;

  // is node we need to remove in left subtree?
  if (existingVal < fromSubTree->_val)
    {
      // recursively remove from left subtree
      fromSubTree->left() = remove(existingVal, fromSubTree->left() );
    }
  else if (existingVal > fromSubTree->_val)
    {
      // recursively remove from right subtree
      fromSubTree->right() = remove(existingVal, fromSubTree->right() );
    }
  else // this is the node we want to remove!
    {
      if (fromSubTree->isLeaf())  // 0 children
	{
	  fromSubTree=nullptr;
	}
      else if (fromSubTree->left() && fromSubTree->right() ) // 2 children
	{
          // find the largest node in the left subtree ...
	  AVLNode *toDel = fromSubTree->left();
	  while(toDel->right()!=nullptr)
	    {
	      toDel = toDel->right();
	    }

          // back up largest value in left subtree. 
	  int valueToMove = toDel->value();

          // remove node containing largest value in subtree ...
	  fromSubTree->left()=remove(valueToMove, fromSubTree->left());
          // ... butplace its value in the node we really want to "remove"
	  fromSubTree->value() = valueToMove;
	}
      else // 1 child
	{
	  if (fromSubTree->left() ) // no right subtree since only 1 child
	    fromSubTree = fromSubTree->left();
	  else // only have right child
	    fromSubTree = fromSubTree->right();
	}
      
    }

  // no tree left? return NULL
  if (!fromSubTree)
    return nullptr;
  
  // rebalance now if needed
  int balance = getHeight(fromSubTree->left()) -
                getHeight(fromSubTree->right()) ;

  // is the left subtree of height more than 2 bigger than right subtree
  if (balance==2)
    {
      int subBalance = getHeight(fromSubTree->left()->left()) -
	               getHeight(fromSubTree->left()->right());

      // left-left issue
      if (subBalance >= 0)
	{
	  fromSubTree = rotateWithLeftChild(fromSubTree);
	}
      else // left-right issue
	{
	  fromSubTree = doubleWithLeftChild(fromSubTree);
	}
    }
  
  // is the right subtree of height more than 2 bigger than left subtree
  if (balance==-2)
    {
      int subBalance = getHeight(fromSubTree->right()->left()) -
	               getHeight(fromSubTree->right()->right());

      // right-right issue
      if (subBalance < 0)
	{
	  fromSubTree = rotateWithRightChild(fromSubTree);
	}
      else // left-right issue
	{
	  fromSubTree = doubleWithRightChild(fromSubTree);
	}
    }

  // might have changed heights of children, so update subtree's height
  fromSubTree->_height = 1 + max( getHeight(fromSubTree->left()) ,
				  getHeight(fromSubTree->right()) );
  
  return fromSubTree;
}

// overloaded << is easy since we wrote a print method
ostream& operator<<(ostream &os, const AVLNode &n)
{
  return n.print(os);
}
