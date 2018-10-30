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
		file_in >> line;
		if(!file_in.eof()) { //if there is a line
			//cout << "test:" << i << endl; //testing code
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

	//int iterations=0; //testing code

	//play game
	//for(int turn=0; turn<100; turn++) {
		for(int i=0; i<16; i++) {
			for(int j=0; j<16; j++) {
				//create array to hold the surrounding cell state values
				int surrounding_cells[8];

				//fill array
				if(i>0 && j>0)
					surrounding_cells[0] = grid[i-1][j-1].get_state();
				else
					surrounding_cells[0] = 0;
				if(i>0) 
					surrounding_cells[1] = grid[i-1][j].get_state();
				else
					surrounding_cells[1] = 0;
				if(i>0 && j<15)
					surrounding_cells[2] = grid[i-1][j+1].get_state();
				else
					surrounding_cells[2] = 0;
				if(j<15) 
					surrounding_cells[3] = grid[i][j+1].get_state();
				else
					surrounding_cells[3] = 0;
				if(i<15 && j<15)
					surrounding_cells[4] = grid[i+1][j+1].get_state();
				else
					surrounding_cells[4] = 0;
				if(i<15)
					surrounding_cells[5] = grid[i+1][j].get_state();
				else
					surrounding_cells[5] = 0;
				if(i<15 && j>0) 
					surrounding_cells[6] = grid[i+1][j-1].get_state();
				else
					surrounding_cells[6] = 0;
				if(j>0) 
					surrounding_cells[7] = grid[i][j-1].get_state();
				else
					surrounding_cells[7] = 0;

				//find the number of live cells in the surrounding array
				int live_cell_total = 0;
				for(int k=0; k<7; k++) {
					live_cell_total = live_cell_total + surrounding_cells[k];
					//cout << "sck:" << surrounding_cells[k];
				}

				grid[i][j].set_surround(live_cell_total);

				//cout << live_cell_total;//testing code

				//cout << "interations: " << iterations << endl; //testing code
				//iterations++; //testing code
			} // end second inside for loop
		}//end first inside for loop
	//}//end ouside for loop
	

	//testing code
	for(int i=0; i<16; i++) {
		for(int j=0; j<16; j++) {
			cout << grid[i][j].get_state();
		}
		cout << endl;
	}

	cout << endl;

	//testing code
	for(int i=0; i<16; i++) {
		for(int j=0; j<16; j++) {
			cout << grid[i][j].get_surround();
		}
		cout << endl;
	}

	return 0;
}




