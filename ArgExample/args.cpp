#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  cout << "There were " << argc
       << " arguments " << endl;

  for (int index=0; index<argc; index++)
    cout << argv[index] << endl;

  /*
  if (argv[1] == "arg")
  */
  string firstArg = argv[1];
  if (firstArg == "arg") // or maybe "bubble" ?? 
    {
      cout << "1st argument is arg"
	   << endl;
    }
  else// if (firstArg == "heap") 
    {
      cout << "1st argumen wwas not arg"
	   << endl
	   << "it was :\"" << argv[1]
	   << "\"" << endl;
    }
  
  return 0;
}
