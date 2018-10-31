/******************************
 * Title: Queue
 * Author: Mark Piccirilli
 * Date: 10/30/18
 * Description: This is a queue to hold the 2d arrays generated by the game
 * ************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "Cell.hpp"
#include <iostream>

struct link {
	link* next;
	link* prev;
	Cell** val;
};

class Queue {

private:
	link* head;

public: 
	Queue();

	~Queue();

	bool isEmpty();

	void addBack(Cell**);

	void removeFront();

	Cell** getFront();

};

#endif