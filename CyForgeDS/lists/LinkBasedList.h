#pragma once

#include <cstddef>
#include <cstdint>
#include <iterator>
#include <stdexcept>
#include <string>
#include "CyForgeDS/base/LLNode.h"

template <typename T>


class LinkBasedList {
private:
	std::size_t element_num;
	LLNode<T>* front;
	LLNode<T>* rear;

public:
	LinkBasedList() : element_num(0), front(nullptr), rear(nullptr) {}

	T set(std::size_t index, const T& element) {
		if (index < 0 || index > element_num) {
			throw std::out_of_range("Index " + std::to_string(index) + 
				       " is out of bounds for list of size " + 
				       std::to_string(element_num));
		}

		if (index == 0) {
			front->setData(element);
			return front->getData();
		}
		else if (index == element_num-1) {
			front->setData(element);
			return front->getData();
		}
		else {
			LLNode<T>* node = new LLNode<T>(element);

			for(int i = 0; i < (index); i++){
				node = node->getNext();
			}

			node->setData(element);
			return node->getData();
					
		}
	}

	void add(std::size_t index, const T& element){
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
			for(int i = 0; i < (index - 1); i++){
				node = node->getNext();
			}
			newNode->setNext(node->getNext());
			node->setNext(newNode);
		}
		element_num++;

	}

	void remove(std::size_t index){
		if (index < 0 || index > element_num) {
			throw std::out_of_range("Index " + std::to_string(index) + 
				       " is out of bounds for list of size " + 
				       std::to_string(element_num));
		}

		if(index == 0) {
			if(front != nullptr) {
				LLNode<T>* node = front;
				front = front->getNext();
				node->setNext(nullptr);
				delete node;
			}
		}
		else {
			LLNode<T>* prevNode = front;

			for(int i = 0; i < index-1; i++) {
				prevNode = prevNode->getNext();
			}
			
			LLNode<T>* currNode = prevNode->getNext();
			LLNode<T>* nextNode = currNode->getNext();

			currNode->setNext(nullptr);
			prevNode->setNext(nextNode);

			delete currNode;
		}
		element_num--;
	}

	T get(std::size_t index){
		LLNode<T>* node = front;
		
		for(int i = 0; i < index; i++) {
			node = node->getNext();
		}

		return node->getData();
	}

	int indexOf(const T& element) {
		LLNode<T>* node = front;
		
		int index = 0;

		while(node) {
			if (node->getData() == element){
				return index;
			}
			node = node->getNext();
			index++;
		}

		throw std::out_of_range("Element not found in list");
	}

	bool contains(const T& element) {
		LLNode<T>* node = front;

		while(node) {
			if (node->getData() == element){
				return true;
			}

			node = node->getNext();
		}
		return false;
	}

	int size() const {
		return element_num;
	}

	bool isEmpty() {
		return element_num == 0;
	}

	LLNode<T>* getFront() const {
		return front;
	}

	LLNode<T>* getRear() const {
		return rear;
	}

	~LinkBasedList() {
		clear();
	}
private:
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
