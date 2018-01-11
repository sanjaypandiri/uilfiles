#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream file;
  file.open("tic.dat");
	int n;
	file >> n;
	for(int i = 0; i < n; i++) {
		int moves;
	file >> moves;
	char board[9];
	for(int i = 0; i < 9; i++) board[i] = ' ';
	for(int i = 0; i < moves; i++) {
		int r, c;
		file >> r;
		file >> c;
		board[3*r + c] = i % 2 == 0 ? 'X' : 'O';
	}
	bool isIncom = false;
	for(int r = 0; r < 3; r++) {
		for(int c = 0; c < 3; c++) {
			cout << board[3*r + c];
			if(c != 2) cout << "|";
			if(board[3*r + c] == ' ') isIncom = true;
		}
		if(r != 2) cout << endl << "-----" << endl;
	}
	cout << endl;
	bool xWin = false, oWin = false;
	for(int r = 0; r < 3; r++) {
		if(board[3*r] == 'X' && board[3*r + 1] == 'X' && board[3*r + 2] == 'X')
			xWin = true;
		else if(board[3*r] == 'O' && board[3*r + 1] == 'O' && board[3*r + 2] == 'O')
			oWin = true;
			
		if(board[r] == 'X' && board[3 + r] == 'X' && board[6 + r] == 'X')
			xWin = true;
		else if(board[r] == 'O' && board[3 + r] == 'O' && board[6 + r] == 'O')
			oWin = true;
	}
	if((board[0] == 'X' && board[4] == 'X' && board[8] == 'X') || (board[2] == 'X' && board[4] == 'X' && board[6] == 'X'))
		xWin = true;
	else if((board[0] == 'O' && board[4] == 'O' && board[8] == 'O') || (board[2] == 'O' && board[4] == 'O' && board[6] == 'O'))
		oWin = true;
	if (moves == 8) {
	  if (((board[0] == board[1]) && (board[3] == board[4]) && (board[1] != board[2]) && (board[4] != board[5])) && ((board[6] == ' ') || (board[6] != board[4])))
	    isIncom = false;
	  if (((board[1] == board[2]) && (board[4] == board[5]) && (board[0] != board[1]) && (board[3] != board[4])) && ((board[8] == ' ') || (board[8] != board[4])))
	    isIncom = false;
	  if (((board[3] == board[4]) && (board[6] == board[7]) && (board[4] != board[5]) && (board[7] != board[8])) && ((board[2] == ' ') || (board[2] != board[4])))
	    isIncom = false;
	  if (((board[4] == board[5]) && (board[7] == board[8]) && (board[3] != board[4]) && (board[6] != board[7])) && ((board[0] == ' ') || (board[0] != board[4])))
	    isIncom = false;
	  if ((board[0] == board[5]) && (board[0] == board[6]) && (board[2] == board[3]) && (board[2] == board[8]) && (board[1] != board[7]))
	    isIncom = false;
	}
	if(xWin)
		cout << "X wins!";
	else if(oWin)
		cout << "O wins!";
	else {
	  if(isIncom)
	    cout << "Incomplete";
	  else
		  cout << "Tie Game!";
	}
	
	cout << endl << endl;
	}
	
	return 0;
}

