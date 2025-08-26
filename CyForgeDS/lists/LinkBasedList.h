#pragma once


template <typename T>
#include "CyForgeDS/base/LLNode.h"

class LinkBasedList {
private:
	int element_num;
	LLNode* front;
	LLNode* rear;
public:
	LinkBasedList() : element_num(0), front(nullptr), rear(nullptr) {}

};
