#pragma once

#include <cstddef>
#include <exception>
#include <initializer_list>
#include <stdexcept>

namespace cyforge {
	
template <typename T>
class ArrayList {
private:
	T* data;
	size_t capacity;
	size_t curr_size;
	
public:
	ArrayList(): data{nullptr}, capacity{0}, curr_size{0} {}

	ArrayList(size_t size): data{nullptr}, capacity{size}, curr_size{0} {
		data = new T[capacity];
	}

	ArrayList(const T& element): data{nullptr}, capacity{1}, curr_size{0} {
		data = new T[capacity];
		data[0] = element;
		curr_size++;
	}

	ArrayList(const std::initializer_list<T> init)
		: data{nullptr}, capacity(init.size()), curr_size(0) {
		data = new T[init.size()];

		for (const auto& item : init) {
			data[curr_size++] = item;
		}
	}

	T& operator[](std::ptrdiff_t index) {
		if (index < 0) {
			std::ptrdiff_t index2 = curr_size + index;

			if (index2 >= 0) {
				return data[curr_size + index];
			}
			else {
				throw std::out_of_range("Index out of bounds");
			}
		}
		return data[index];
	}

	~ArrayList(){
		delete[] data;
	}

	void push_back(const T& element) {
		if (curr_size >= capacity){
			resize((capacity == 0) ? 1 : capacity * 2);
		}
		data[curr_size++] = element;
	}

	size_t getCapacity(){
		return capacity;
	}

	size_t getSize(){
		return curr_size;
	}

	void reserve(size_t newCapacity) {
		if (newCapacity > capacity) {
			resize(newCapacity);
		}
	}

private:
	void resize(size_t newCapacity) {
		T* newData = new T[newCapacity];

		for(size_t i = 0; i < curr_size; i++) {
			newData[i] = data[i];
		}

		delete[] data;
		data = newData;
		capacity = newCapacity;
	}

};
}
