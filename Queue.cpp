/******************************
 * Title: Queue
 * Author: Mark Piccirilli
 * Date: 10/30/18
 * Description: This is a queue to hold the 2d arrays generated by the game.
 * This file contains the function implementation
 * ************************************/

#include "Queue.hpp"

Queue::Queue() {
	head = NULL;
}


Queue::~Queue() {
	while(!isEmpty()) {
		removeFront();
	}
}

bool Queue::isEmpty() {
	if(head == NULL) 
		return true;
	else
		return false;
}

void Queue::addBack(Cell** val) {
	link* l = new link;
	l->val = val;
	//if the list is empty
	if(isEmpty()) {
		l->prev = head;
		l->next = head;
	}
	//if there is one element
	else if(head->next == head) {
		head->next = l;
		head->prev = l;
		l->prev = head;
		l->next = head;
	}
	//if there are more than one element
	else {
		link* temp = head->prev;
		temp->next = l;
		l->prev = temp;
		l->next = head;
		head->prev = l;
	}
}

void Queue::removeFront() {
	//make sure list is not empty before trying to remove element
	if(!isEmpty()) {
		//if there is only one element
		if(head->next == head) {
			delete head;
			head = NULL; //set head equal to NULL
		}
		//if there are more than one element
		else {
			//remove and reset head
			link* temp;
			temp = head;
			head = head->next;
			head->prev = temp->prev;
			temp->prev->next = head;
			delete temp;
		}
	}
}

Cell** Queue::getFront() {
	return head->val;
}