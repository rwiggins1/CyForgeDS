#include <array>
#include <cassert>
#include <map>
#include <string>
#include "../../CyForgeDS/lists/LinkBasedList.h"
#include <iostream>

using namespace cyforge;

int main(){
	LinkBasedList<int> LinkBList;

	assert(LinkBList.isEmpty() == true);
	LinkBList.add(0, 23);
	assert(LinkBList.isEmpty() == false);
	auto LBL = LinkBList.begin();
	assert(*LBL == 23);
	LinkBList.add(1, 24);
	LBL++;
	assert(*LBL == 24);
	assert(LinkBList.size() == 2);
	LinkBList.remove(0);
	
	// test remove
	LinkBList.add(1, 45);
	LinkBList.add(2, 90);
	LinkBList.remove(1);
	assert(LinkBList.size() == 2);
	assert(*LinkBList.begin() == 24);

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

	// test copy constructor
	LinkBasedList<int> Lbl;
	Lbl.add(0, 3);
	Lbl.add(1, 5);

	LinkBasedList<int> Lbl2 = Lbl;
	assert(*Lbl2.begin() == *Lbl.begin());
	
	// test copy asignment operator
	Lbl.add(2 , 32);
	Lbl = Lbl2;

	// test Iterator
	for (auto it = Lbl.begin(); it != Lbl.end(); ++it) {
		std::cout << *it << ",";
	} std::cout << "\n";

	// test push back
	LinkBasedList<int> list1;
	list1.push_back(12);
	auto it2 = list1.begin();
	assert(*it2 == 12);

	LinkBasedList<int> list3;
	list3.push_front(11);
	auto it3 = list3.begin();
	assert(*it3 == 11);
	list3.push_back(17);


	list1.concat(list3);

	for (auto it = list1.begin(); it != list1.end(); ++it) {
		std::cout << *it << ",";
	}
	
	
	return 0;
}
