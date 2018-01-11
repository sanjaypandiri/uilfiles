#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream file;
  file.open("rock.dat");
  int games;
  file >> games;
  string line;
  getline(file, line);
  for (int i = 0; i < games; i++) {
  string outcomes;
  getline(file, outcomes);
  char alexAndBen = 'R';
  int wins = 0, losses = 0, ties = 0;
  
  for (int i = 0; i < outcomes.length(); i++) {
    if (outcomes.at(i) == 'R') {
      if (alexAndBen == 'R') {
        ties++;
      } else if (alexAndBen == 'P') {
        losses++;
      } else if (alexAndBen == 'S') {
        wins++;
        alexAndBen = 'P';
      }
    }
    if (outcomes.at(i) == 'P') {
      if (alexAndBen == 'R') {
        wins++;
        alexAndBen = 'S';
      } else if (alexAndBen == 'P') {
        ties++;
      } else if (alexAndBen == 'S') {
        losses++;
      }
    }
    if (outcomes.at(i) == 'S') {
      if (alexAndBen == 'R') {
        losses++;
      } else if (alexAndBen == 'P') {
        wins++;
        alexAndBen = 'R';
      } else if (alexAndBen == 'S') {
        ties++;
      }
    }
  }
  cout << "Wins: " << wins << endl;
  cout << "Losses: " << losses << endl;
  cout << "Ties: " << ties << endl;
  cout << "\n";
  }
  file.close();
  return 0;
}


  
