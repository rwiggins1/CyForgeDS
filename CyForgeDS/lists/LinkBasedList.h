#pragma once


template <typename T>
#include "CyForgeDS/base/LLNode.h"

class LinkBasedList {
private:
	int element_num;
	LLNode<T>* front;
	LLNode<T>* rear;

public:
	LinkBasedList() : element_num(0), front(nullptr), rear(nullptr) {}
	
	~LinkBasedList(){
		clear();
	}
private:
	void clear(){
		while(front){
			LLNode<T>* toDelete = front;
			front = front->getNext();
			delete toDelete;
		}
		rear = nullptr;
		element_num = 0;
	}
};
