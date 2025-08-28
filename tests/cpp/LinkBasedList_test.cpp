#include <cassert>
#include "CyForgeDS/base/LLNode.h"
#include "CyForgeDS/lists/LinkBasedList.h"

int main(){
	LinkBasedList<int> LinkBList;

	assert(LinkBList.isEmpty() == true);
	
	return 0;
}
