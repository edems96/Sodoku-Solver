#include <iostream>
#inlcude <cstdio>
#include <cstdlib>

typedef unsigned int uint;

struct Sodoku {
	uint col;
	uint row;
	
	uint block;
	
	uint val;
	
	bool isEmpty() { return val == 0; }
}

int main() {
	FILE *f;
	
	f = fopen("sodoku.txt", "r");
	
	if( f == NULL ) {
		cout << "Failed to open file!" << endl;
		return 0;
	}
	
	uint col, row, block;
	
	Sodoku sodoku[9*9];
	uint i = 0;
	
	while( !feof(f) ) {
		int c = fgetc(f);
		
		if( c == -1 )
			break;
			
		if( c == '\n' ) {
			col = 0;
			row++;
			block++;
		} else {
			Sodoku s;
			
			s.col = col++;
			s.row = row;
			
			if( col != 0 && col % 3 == 0 )
				block++;
			
			s.block = block;
		
			sodoku[i] = s;
		}
	}
	
	fclose(f);
	
	return 1;
}