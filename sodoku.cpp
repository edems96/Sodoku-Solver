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
	
	Sodoku() : col(0), row(0), block(0), val(0) {}
	
	bool isEmpty() { return val == 0; }
};

Sodoku sodoku[9*9];

void readFile();
void solve();
void print();

uint ctoi(char c);

bool hasInCol(uint col, uint v);
bool hasInRow(uint row, uint v);
bool hasInBlock(uint block, uint v);

int main() {
	cout << "main()" << endl;
	
	readFile();
	//solve();
	print();
	
	cout << "main() -- " << endl;
	return 1;
}

void solve() {
	cout << "solve()" << endl;
	
	while( true ) {
		bool ret = false;
		
		for(uint i = 0; i < 9*9; i++) {
			if( !sodoku[i].isEmpty() )
				continue;
			
			bool find = false;
			
			for(uint x = 1; x < 10; x++) {
				if( hasInCol(sodoku[i].col, x) )
					continue;

				if( hasInRow(sodoku[i].row, x) )
					continue;
					
				if( hasInBlock(sodoku[i].block, x) )
					continue;
					
				sodoku[i].val = x;
				find = true;
				
				print();
			}
			
			if( !find )
				ret = true;
		}
	
		if( !ret )
			break;
	}
	
	cout << "Solved" << endl;
}

void readFile() {
	FILE *f;
	
	f = fopen("sodoku.txt", "r");
	
	if( f == NULL ) {
		cout << "Failed to open file!" << endl;
		return;
	}
	
	uint col = 0, row = 0, block = 0, i = 0;
	
	while( !feof(f) ) {
		int c = fgetc(f);
		if( c == EOF )
			break;
			
		if( c == '\n' ) {
			col = 0;
			row++;
			
			if( row < 3 )
				block = 0;
			else if( row < 6 )
				block = 3;
			else 
				block = 6;
				
		} else {
			Sodoku s;
			
			s.col = col++;
			s.row = row;
			
			s.block = block;
			
			if( col % 3 == 0 )
				block++;
			
			if( c != '*' ) 
				s.val = ctoi(c);	
		
			sodoku[i++] = s;
		}
	}
	
	fclose(f);
}

void print() {
	cout << endl << endl;
	
	for(uint i = 0; i < 9*9; i++) {
		cout << sodoku[i].block << " ";
		
		if( (i+1) % 9 == 0 )
			cout << endl;
	}
	
	cout << endl << endl;
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

bool hasInCol(uint col, uint v) {
	for(uint i = 0; i < 9*9; i++) {
		if( sodoku[i].col != col )
			continue;
			
		if( sodoku[i].val == v )
			return true;
	}
	
	return false;
}

bool hasInRow(uint row, uint v) {
	for(uint i = 0; i < 9*9; i++) {
		if( sodoku[i].row != row )
			continue;
			
		if( sodoku[i].val == v )
			return true;
	}
	
	return false;
}

bool hasInBlock(uint block, uint v) {
	for(uint i = 0; i < 9*9; i++) {
		if( sodoku[i].block != block )
			continue;
			
		if( sodoku[i].val == v )
			return true;
	}
	
	return false;
}