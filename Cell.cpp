/********************************
 * Title: Cell class
 * Author: Mark Piccirillil
 * Date: 10/25/18
 * Description: This is file contains the function implementationfor the Cell 
 * class.
 * *******************************************/

#include "Cell.hpp"

//default constructor
Cell::Cell() {
	set_state(0);
	set_surround(0);
}

//overload constructor
Cell::Cell(bool pop) {
	set_state(pop);
	set_surround(0);
}

//set cell
void Cell::set_state(bool pop) {
	state = pop; 
}

//get state
bool Cell::get_state() {
	return state;
}

//get surrounding
int Cell::get_surround() {
	return surround;
}

void Cell::set_surround(int surround_in) {
	surround = surround_in;
}	
