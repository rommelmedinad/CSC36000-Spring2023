#include "AVLTree.hpp"
#include "AVLNode.hpp"

// File: main.cpp
// Author: S. Blythe
// Date: 1/2023
// Purpose: Test river for AVL Tree class

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  AVLTree tree;

  // pull "integers" from command line, and addeach to the tree
  for(int i=1; i<argc; i++)
    {
      int valToInsert = atoi(argv[i]);
      tree.insert(valToInsert);
      tree.display(cout);
      cout << "=============" << endl; 
    }

  // (keep) prompting user to enter values to delete and re-display tree
  int delMe;
  cout << "Enter value to delete (-1 to stop):" ;
  cin >> delMe;

  while(delMe != -1)
    {
      tree.remove(delMe);
      tree.display(cout);
      cout << "=============" << endl;
      cout << "Enter value to delete (-1 to stop):" ;
      cin >> delMe;
    }
  
  return 0;
}
