//   SuDoku
#include <fstream>
using namespace std;
const bool slobodno = true;
int ij[3][3] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

int xy2xy(int i, int j) {
  i /= 3;
  j /= 3;
  return ij[i][j];
}

int sudoku[9][10] = {0}; // 10-ta kolona (index 9) je SENTINELA!
bool x[9][9], y[9][9], xy[9][9];

bool SuDoku(int ix, int jx) {
  bool gotovo;
  while (sudoku[ix][jx] != 0) {
    if (jx < 8)  jx++;
      else {
        jx = 0;
        ix++;
       }
    if (ix > 8)  return true;
  }
  for (int digit = 1; digit <= 9; digit++)
    if (x[ix][digit-1] == slobodno  &&
        y[digit-1][jx] == slobodno  &&
        xy[xy2xy(ix, jx)][digit-1] == slobodno) {
        sudoku[ix][jx] = digit;
        x[ix][digit-1] = !slobodno;
        y[digit-1][jx] = !slobodno;
        xy[xy2xy(ix, jx)][digit-1] = !slobodno;
        gotovo = SuDoku(ix, jx + 1);
        if (gotovo)  return true;
        sudoku[ix][jx] = 0;
        x[ix][digit-1] = slobodno;
        y[digit-1][jx] = slobodno;
        xy[xy2xy(ix, jx)][digit-1] = slobodno;
    }  
 return false;
}

int main() {
 for (int ix = 0; ix < 9; ix++) 
   for (int jx = 0; jx < 9; jx++)
     x[ix][jx] = y[ix][jx] = xy[ix][jx] = slobodno;

 ifstream ulaz("sudoku.in");
 for (int ix = 0; ix < 9; ix++) {
   for (int jx = 0; jx < 9; jx++) {
     int digit;
     ulaz >> digit;
     if (digit == 0)  continue;
     sudoku[ix][jx] = digit;
     x[ix][digit-1] = !slobodno;
     y[digit-1][jx] = !slobodno;
     xy[xy2xy(ix, jx)][digit-1] = !slobodno;
   }
   sudoku[ix][9] = 99; // 10-ta kolona (index 9) je SENTINELA!
 }

 SuDoku(0, 0);
 ofstream izlaz("sudoku.out");
 for (int ix = 0; ix < 9; ix++) {
   for (int jx = 0; jx < 9; jx++)
   {
     if (jx) izlaz << " ";
     izlaz << sudoku[ix][jx];
   }
   izlaz << endl;
 }

 return 0;
}