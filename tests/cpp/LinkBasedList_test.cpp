#include <array>
#include <cassert>
#include <map>
#include <string>
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

	//set
	assert(LinkBList.set(1, 8384) == 8384);

	//test array
	LinkBasedList<std::array<std::map<int, std::string>, 10>> mapArrayLink;
	std::array<std::map<int, std::string>, 10> mapArr;
	mapArrayLink.add(0, mapArr);

	LinkBasedList<std::array<int,  3>> arrayLink;
	std::array<int, 3> arr = {1,2,3};
	arrayLink.add(0, arr);
	
	return 0;
}
