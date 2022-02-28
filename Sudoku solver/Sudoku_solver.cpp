#include <iostream>


using namespace std;

char mp[9][9];
int backtrack_cnt = 0;

bool solve(int i, int j);
void next_cell_to_fill(int& i, int& j);
bool is_valid(int i, int j, char k);
void print_sudoku();


int main()
{
	cout << "This program will solve sudoku\n";
	cout << "To enter sudoku, please give this program\n";
	cout << "9x9 numbers; if box is empty, please enter number '0'\n";
	cout << "please enter numbers:\n";

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> mp[i][j];
		}
	}

	if (!solve(0, 0)) {
		cout << "Sorry, I could not solve you sudoku\n";
	}
	else {
		cout << "I have solve your sudoku!^^\n";
		print_sudoku();
		cout << "Also, I did " << backtrack_cnt << " backtracks!\n";
	}
	return 0;
}

bool solve(int i, int j) {

	next_cell_to_fill(i, j);

	if (i==-1) {
		return true;
	}

	for (char k = '1'; k <= '9'; k++) {
		if (is_valid(i, j, k)) {
			mp[i][j] = k;
			if (solve(i, j)) {
				return true;
			}
			backtrack_cnt++;
			mp[i][j] = '0';
		}
	}
	return false;
}

void next_cell_to_fill(int& i, int& j) {
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (mp[i][j] == '0') {
				return;
			}
		}
	}
	i = j = -1;
}

bool is_valid(int i, int j, char k) {

	for (int ii = 0; ii < 9; ii++) {
		if (mp[i][ii] == k) {
			return false;
		}
	}

	for (int jj = 0; jj < 9; jj++) {
		if (mp[jj][j] == k) {
			return false;
		}
	}

	int top_x = 3 * (i / 3), top_y = 3 * (j / 3);
	for (int ii = top_x; ii < top_x + 3; ii++) {
		for (int jj = top_y; jj < top_y + 3; jj++) {
			if (mp[ii][jj] == k) {
				return false;
			}
		}
	}

	return true;

}

void print_sudoku() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << mp[i][j] << ' ';
		}
		cout << '\n';
	}
}
