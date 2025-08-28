#include <cassert>
#include "CyForgeDS/base/LLNode.h"
#include "CyForgeDS/lists/LinkBasedList.h"

int main(){
	LinkBasedList<int> LinkBList;

	assert(LinkBList.isEmpty() == true);
	LinkBList.add(0, 23);
	assert(LinkBList.isEmpty() == false);
	assert(LinkBList.getFront()->getData() == 23);
	LinkBList.add(1, 24);
	assert(LinkBList.getRear()->getData() == 24);
	assert(LinkBList.size() == 2);
	
	return 0;
}
