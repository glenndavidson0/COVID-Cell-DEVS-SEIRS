#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string cellIndexString(int x, int y);

int main(){

  ofstream outputFile;
  int x_dim = 50;
  int y_dim = 50;

  // define cell values to be written
  string borderCell   = " = 100 1 0.0 0.07 1 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.01 0.03 0.18 0.30 0.17 0.17 0.17 0.17 0.17 0.17 0.17 0.17 0.03 0.01 0.01 0.01 0.01 0.01 0.01 0.01 0.03 0 0 0 0";
  string infectedCell = " = 100 1 0.6 0.07 0.7 0.3 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.01 0.03 0.18 0.30 0.17 0.17 0.01 0.01 0.01 0.01 0.01 0.01 0.01 0.01 0.01 0.01 0.01 0.01 0.01 0.01 0.03 0.3 0 0 0";
  outputFile.open ("scenario1.val");

  // draw a border alone the x axis in the middle of the cell space
  for(int k = 0; k < x_dim; k++){
    if(k == 25){
      continue;
    }
    outputFile << cellIndexString(k,25) + borderCell << endl;
  }

  // insert infected cell in lower hemisphere
  outputFile << cellIndexString(25,30) + infectedCell << endl;

  // it appears that .val files need an empty newline character after every entry, so
  // a new line must be written to the very last value.

  outputFile.close();
  return 0;
}

// create a string of a cell's index given its coordinates x y = "(x,y)"
string cellIndexString(int x, int y){
  string s = "(";
  string sx = to_string(x);
  string sy = to_string(y);
  s.append(sx);
  s.append(",");
  s.append(sy);
  s.append(")");
  return s;
}
