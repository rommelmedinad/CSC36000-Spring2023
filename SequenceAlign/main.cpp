#include <iostream>
#include <string>

#include "SequenceAligner.hpp"


using namespace std;

int main(int argc, char *argv[])
{
  if (argc!=3)
    {
      cout << "usage: " << argv[0] << " <str1> str2>" << endl;
      return 1;
    }
  int bestPenalty = sequenceAlign(argv[1], argv[2], 5, 1);

  cout << "Best penalty:" << bestPenalty << endl;

  return 0;
}
