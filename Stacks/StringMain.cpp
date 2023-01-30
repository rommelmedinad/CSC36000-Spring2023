#include <cstdlib>
#include <iostream>
#include <string>

#include "Stack.tpp"

using namespace std;

int main(int argc, char *argv[])
{
  Stack<string> myStack;

  for (int argIndex=1; argIndex<argc; argIndex++)
    {
      myStack.push ( /*atoi(*/  argv[argIndex]  /*)*/  );
    }

  cout << "Top of stack is :" << myStack.top() << endl;

  cout << "The stack is:" << endl;
  while ( !myStack.isEmpty() )
    {
      string val = myStack.pop();
      cout << val << endl;
    }

  return 0;
}
