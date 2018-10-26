/********************************
 * Title: Cell class
 * Author: Mark Piccirillil
 * Date: 10/25/18
 * Description: This is the header file for the Cell class
 * *******************************************/

#ifndef CELL_HPP
#define CELL_HPP

class Cell {

private:
	bool state; //0 will be unpopulate and 1 will be populated 

public:

	//default constructor
	Cell();

	//overload constructor
	Cell(bool);


	//setter
	void set_state(bool );

	//getter
	bool get_state();
};

#endif
