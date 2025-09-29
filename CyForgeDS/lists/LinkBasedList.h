#pragma once

#include <cstddef>
#include <cstdint>
#include <iterator>
#include <stdexcept>
#include <string>
#include "../base/LLNode.h"

namespace cyforge {

template <typename T>
class LinkBasedList {
private:
	size_t element_num;
	LLNode<T>* front;
	LLNode<T>* rear;

public:
	class Iterator {
	private:
		LLNode<T>* current;
	public:
		Iterator(LLNode<T>* node) : current(node) {}

		Iterator& operator++() {
			current = current->getNext();
			return *this;
		}
		Iterator operator++(int) {
			Iterator iterator = *this;
			current = current->getNext();
			return iterator;
		}
		bool operator==(const Iterator& other) const { return current == other.current; }
		bool operator!=(const Iterator& other) const { return current != other.current; }

		T& operator*() { return current->getData(); } 
		T* operator->() { return &(current->getData()); }
	};

	Iterator begin() {
		return Iterator(front);
	}

	Iterator end() {
		return Iterator(nullptr);
	}

	LinkBasedList() : element_num(0), front(nullptr), rear(nullptr) {}

	LinkBasedList(const LinkBasedList<T>& sourceList):
		element_num(0),
		front(nullptr),
		rear(nullptr) {

		if (sourceList.isEmpty()) { return; }

		LLNode<T>* sourceNode = sourceList.getFront();
		
		while(sourceNode != nullptr) {
			push_back(sourceNode->getData());
			sourceNode = sourceNode->getNext();
		}
	}

	LinkBasedList& operator=(const LinkBasedList<T>& sourceList) {
		if (this == &sourceList) {
			return *this;
		}
		
		clear();

		if (sourceList.isEmpty()) { return *this; }
		
		LLNode<T>* sourceNode = sourceList.getFront();
		
		while(sourceNode != nullptr) {
			push_back(sourceNode->getData());
			sourceNode = sourceNode->getNext();
		}

		return *this;
	}

	~LinkBasedList() { clear(); }

	T set(size_t index, const T& element) {
		if (index < 0 || index >= element_num) {
			throw std::out_of_range("Index " + std::to_string(index) + 
				       " is out of bounds for list of size " + 
				       std::to_string(element_num));
		}

		if (index == 0) {
			front->setData(element);
			return front->getData();
		}
		else if (index == element_num-1) {
			rear->setData(element);
			return rear->getData();
		}
		else {
			LLNode<T>* node = getFront();

			for(size_t i = 0; i < (index); i++){
				node = node->getNext();
			}

			node->setData(element);
			return node->getData();
					
		}
	}

	void add(size_t index, const T& element){
		if (index < 0 || index > element_num) {
			throw std::out_of_range("Index " + std::to_string(index) + 
				       " is out of bounds for list of size " + 
				       std::to_string(element_num));
		}

		LLNode<T>* newNode = new LLNode<T>(element);

		if (index == 0) {
			if (front == nullptr) {
				front = newNode; rear = newNode;
			} 
			else {
				newNode->setNext(front);
				front = newNode;
			}
		}
		else if (index == element_num) {
			rear->setNext(newNode);
			rear = newNode;
		}
		else {
			LLNode<T>* node = front;
			for(size_t i = 0; i < (index - 1); i++){
				node = node->getNext();
			}
			newNode->setNext(node->getNext());
			node->setNext(newNode);
		}
		element_num++;

	}

	void remove(size_t index){
		if (element_num == 0) {
		    throw std::out_of_range("Cannot remove from empty list");
		}

		if (index < 0 || index >= element_num) {
			throw std::out_of_range("Index " + std::to_string(index) + 
				       " is out of bounds for list of size " + 
				       std::to_string(element_num));
		}

		if(index == 0) {
			LLNode<T>* node = front;
			front = front->getNext();
			
			if (element_num == 1) {
				rear = nullptr;
			} 
			else {
				node->setNext(nullptr);
			}

			delete node;
		}
		else {
			LLNode<T>* prevNode = front;

			for(size_t i = 0; i < index-1; i++) {
				prevNode = prevNode->getNext();
			}
			
			LLNode<T>* currNode = prevNode->getNext();
			LLNode<T>* nextNode = currNode->getNext();
			
			if (index == element_num-1) {
				rear = prevNode;
			}
			else {
				currNode->setNext(nullptr);
			}
			prevNode->setNext(nextNode);

			delete currNode;
		}
		element_num--;
	}

	void push_front(const T& element) {
		LLNode<T>* newNode = new LLNode<T>(element);

		if (isEmpty()) {
			rear = newNode;
		}
		newNode->setNext(front);

		front = newNode;
		element_num++;
	}

	void push_back(const T& element) {
		LLNode<T>* newNode = new LLNode<T>(element);
		
		if (isEmpty()) {
			front = newNode;
		}
		else {
			rear->setNext(newNode);
		}

		rear = newNode;
		element_num++;
	}

	void concat(const LinkBasedList<T>& other) {
		for (auto it = other.begin(); it != other.end(); ++it) {
			push_back(*it);
		}
	}

	T get(size_t index) const {
		LLNode<T>* node = front;
		
		for(size_t i = 0; i < index; i++) {
			node = node->getNext();
		}

		return node->getData();
	}

	size_t indexOf(const T& element) const {
		LLNode<T>* node = front;
		
		size_t index = 0;

		while(node) {
			if (node->getData() == element){
				return index;
			}
			node = node->getNext();
			index++;
		}

		throw std::out_of_range("Element not found in list");
	}

	bool contains(const T& element) const {
		LLNode<T>* node = front;

		while(node) {
			if (node->getData() == element){
				return true;
			}

			node = node->getNext();
		}
		return false;
	}

	size_t size() const {
		return element_num;
	}

	bool isEmpty() const {
		return element_num == 0;
	}


private:
	LLNode<T>* getFront() const {
		return front;
	}

	LLNode<T>* getRear() const {
		return rear;
	}

	void clear(){
		while(front) {
			LLNode<T>* toDelete = front;
			front = front->getNext();
			delete toDelete;
		}
		rear = nullptr;
		element_num = 0;
	}
};
}
