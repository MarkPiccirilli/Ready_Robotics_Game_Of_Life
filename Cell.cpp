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
}

//overload constructor
Cell::Cell(bool pop) {
	set_state(pop);
}

//set cell
void Cell::set_state(bool pop) {
	state = pop; 
}

//get state
bool Cell::get_state() {
	return state;
}
