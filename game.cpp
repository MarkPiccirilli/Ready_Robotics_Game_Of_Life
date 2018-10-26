/*******************************
 * Title: Game of life program (main function)
 * Author: Mark Piccirilli
 * Date: 10/25/2018
 * input: The user must input the file as a command line argument
 * Description: This program simulates the conways game of life based on a user 
 * input file.  It determines if there is a patter and reports the starting 
 * generation of the pattern and the number of generations that the pattern 
 * lasts.
 * **********************************************/

#include <iostream>
#include <fstream>
#include <string>

#include "Cell.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;

int main(int argc, char* argv[]) {

	ifstream file_in;

	file_in.open(argv[1]);

	string data;

	Cell grid[16][16]; //create an array of objects for the grid
	string line;

	for(int i=0; i<16; i++) {
		if(!file_in.eof()) { //if there is a line
			file_in >> line;
			if(line.length() < 16) { //if the lines are shorter than 16 make remaining cells unpopulated
				for(int x=line.length(); x<16; x++) { 
					line = line + '.';
				}
			}	
			for(int j=0; j<16; j++) {
				if(line.at(j) == '+') {
					grid[i][j] = Cell(1);
				}
				else if (line.at(j) == '.') {
					grid[i][j] = Cell(0);	
				}
				else {
					fprintf(stderr, "Invalid character in file!\n");
					exit(1);
				}
			} //end j for loop
		} //end if(line.length() < 16)
		else { //if there are less than 16 links in the file set the remain lines as unpopulated cells
			for(int k=0; k<16; k++) {
				grid[i][k] = Cell(0);
			}
		}
	} //end outside for loop

	//close file
	file_in.close();


	//testing code
	for(int i=0; i<16; i++) {
		for(int j=0; j<16; j++) {
			cout << grid[i][j].get_state();
		}
		cout << endl;
	}

	return 0;
}
