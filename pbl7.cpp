/*
============================================================================
Name        : pbl7.cpp
Author      : Om
Subject     : Project Based Learning
Description : N-Queen Problem
============================================================================
*/
#include <iostream>
#include <cstdlib>
using namespace std;

class NQueens
{

public:
     int x[10];
     int n;
     void NQueen(int k, int n);
     bool Place(int k, int i);
     void printBoard();
};

void NQueens::NQueen(int k, int n)
{
     if (k > n)
     {
          printBoard();
          return;
     }

     for (int i = 1; i <= n; i++)
     {
          if (Place(k, i))
          {
               x[k] = i;
               NQueen(k + 1, n);


          }
     }

}

bool NQueens::Place(int k, int i)
{
     for (int j = 1; j < k; j++)
     {
          if (x[j] == i || abs(x[j] - i) == abs(j - k))
          {
               return false;
          }
     }
     return true;
}

void NQueens::printBoard()
{
      int solutionCount = 1;
    cout << "\nSolution " << solutionCount++ << ":\n";
     for (int i = 1; i <= n; i++)
     {
          for (int j = 1; j <= n; j++)
          {
               if (x[i] == j)
               {
                    cout << "Q" << j;
               }
               else
               {
                    cout << ". ";
               }
          }
          cout << endl;
     }
     cout << endl;
}

int main()
{
     NQueens nq;
     cout << "Enter number of queens: ";
     cin >> nq.n;
     nq.NQueen(1, nq.n);
     return 0;
}
