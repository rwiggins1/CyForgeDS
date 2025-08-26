#pragma once


template <typename T>

class LLNode {
	private:
		T data;
		LLNode* next;
	public:
		LLNode(const T& value): data(value), next(nullptr){}

		T getData() const {
			return data;
		}
		
		LLNode* getNext() const {
		return next;
		}

		void setData(T value) {
		data = value;
		}
		
		void setNext(LLNode* node) {
		next = node;
		} 
};
