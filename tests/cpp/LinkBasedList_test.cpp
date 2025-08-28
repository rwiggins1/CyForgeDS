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
	LinkBList.remove(0);
	
	// test remove
	LinkBList.add(1, 45);
	LinkBList.add(2, 90);
	LinkBList.remove(1);
	assert(LinkBList.size() == 2);
	assert(LinkBList.getFront()->getData() == 24);
	assert(LinkBList.getRear()->getData() == 90);

	//test get
	assert(LinkBList.get(1) == 90);

	//indexOf
	assert(LinkBList.indexOf(90) == 1);

	//contains
	assert(LinkBList.contains(90) == true);
	assert(LinkBList.contains(8384) == false);
	
	return 0;
}
