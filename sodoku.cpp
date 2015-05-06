#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef unsigned int uint;

struct Sodoku {
	uint col;
	uint row;
	
	uint block;
	
	uint val;
	
	bool isEmpty() { return val == 0; }
};

Sodoku sodoku[9*9];

void readFile();
void solve();
void print();
uint ctoi(char c);

int main() {
	readFile();
	print();
	//solve();
	
	return 1;
}

void solve() {
/*	
	while( true ) {
	
	
	}
	*/
}

void readFile() {
	FILE *f;
	
	f = fopen("sodoku.txt", "r");
	
	if( f == NULL ) {
		cout << "Failed to open file!" << endl;
		return;
	}
	
	uint col, row, block;

	uint i = 0;
	
	while( !feof(f) ) {
		int c = fgetc(f);
		if( c == EOF )
			break;
			
		if( c == '\n' ) {
			col = 0;
			row++;
			block++;
			cout << endl;
		} else {
			Sodoku s;
			
			s.col = col++;
			s.row = row;
			
			if( col != 0 && col % 3 == 0 )
				block++;
			
			s.block = block;
			
			if( c != '*' )
				s.val = ctoi(c);	
		
			sodoku[i] = s;
		}
	}
	
	fclose(f);
}

void print() {
	cout << endl;
	
	for(uint i = 0; i < 9*9; i++) {
		if( (i+1) % 9 == 0 )
			cout << endl;
			
		cout << sodoku[i].val;
	}
	
	cout << endl;
}

uint ctoi(char c) {
	switch( c ) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
	}
}