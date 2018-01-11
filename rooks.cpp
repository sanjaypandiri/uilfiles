#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream file;
  file.open("rooks.dat");
  int sets;
  file >> sets;
  for(int i=1; i<=sets; i++){
    int sideLength;
    file >> sideLength;
    unsigned long int product = 1;
    for(int j=1; j<=sideLength; j++){
      product = product * j;
    }
    cout << product << endl;
  }
  file.close();
}