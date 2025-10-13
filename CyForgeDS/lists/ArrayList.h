#pragma once

#include <cstddef>

namespace cyforge {
	
template <typename T>
class ArrayList {
private:
	T* data;
	size_t capacity;
	size_t curr_size;
	
public:
	ArrayList(): data(nullptr), capacity(0), curr_size(0) {}

	~ArrayList(){}
};
}
