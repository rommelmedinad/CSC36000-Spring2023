#include "SequenceAligner.hpp"

#include <iomanip>
#include <iostream>

using namespace std;

int **M = nullptr;

int sequenceAlign(const std::string &X, const std::string &Y,
		  int delta, int alpha)
{
  int m = X.length();
  int n = Y.length();

  // make space for memo-ized 2-D array (M)
  if (!M) delete [] M;
  M = new int*[m+1];
  for (int row=0; row<=m; row++)
    M[row] = new int[n+1];

  for (int i=0; i<=m; i++)
    M[i][0]=i*delta;
  for (int j=0; j<=n; j++)
    M[0][j]=j*delta;

  for (int i=1; i<=m; i++)
    for (int j=1; j<=n; j++)
      {
	if (X[i-1]==Y[j-1])
	  M[i][j] = M[i-1][j-1];
	else
	  M[i][j] = alpha + M[i-1][j-1];
	M[i][j] = min (M[i][j], delta + M[i-1][j]);
	M[i][j] = min (M[i][j], delta + M[i][j-1]);
      }

  for (int i=0; i<=m; i++)
    {
      for (int j=0; j<=n; j++)
	cout << setw(4) << M[i][j] << " ";
      cout << endl;
    }
  return M[m][n];
}
