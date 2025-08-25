#include <cassert>
#include "CyForgeDS/base/LLNode.h"

int main(){
	LLNode<int> node1(10);
	assert(node1.getData() == 10);
	assert(node1.getNext() == nullptr);

	LLNode<int> node2(11);
	node1.setNext(&node2);
	assert(node1.getNext() == &node2);
	return 0;
}
