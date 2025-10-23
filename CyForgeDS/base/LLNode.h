#pragma once

namespace cyforge {

template <typename T>
class LLNode {
	private:
		T data;
		LLNode* next;
	public:
		LLNode(const T& value): data(value), next(nullptr){}

		T& getData() noexcept {
			return data;
		}

		const T& getData() const noexcept {
			return data;
		}
		
		LLNode* getNext() const noexcept {
		return next;
		}

		void setData(T value) noexcept {
			data = value;
		}
		
		void setNext(LLNode* node) noexcept {
			next = node;
		} 
};
}
