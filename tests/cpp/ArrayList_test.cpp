#include <cassert>
#include "../../CyForgeDS/lists/ArrayList.h"

using namespace cyforge;

int main() {
	ArrayList<int> vector(331);
	assert(vector.getSize() == 1);
	assert(vector.getCapacity() == 1);
	assert(vector[0] == 331);

	ArrayList<int> vector2 = {1,2,3,-4,5};
	assert(vector2[3] == -4);
	assert(vector2.getSize() == 5);
	assert(vector2.getCapacity() == 5);
	assert(vector2[-1] == 5);
	

	ArrayList<int> vector3 = {};
	assert(vector3.isEmpty() == true);
	assert(vector3.getSize() == 0);
	assert(vector3.getCapacity() == 0);
	vector3.push_back(0);
	assert(vector.isEmpty() == false);
	assert(vector3.getSize() == 1);
	assert(vector3.getCapacity() == 1);
	vector3.push_back(3);
	vector3.push_back(3);
	assert(vector3.getSize() == 3);
	assert(vector3.getCapacity() == 4);

	vector3.reserve(40);
	assert(vector3.getCapacity() == 40);
	assert(vector3.getSize() == 3);
	vector3.push_back(-22);
	vector3.shrink_to_fit();
	assert(vector3.getCapacity() == 4);

	vector3[0] = 100;
	assert(vector3[0] == 100);

	return 0;
}
