/*
* stack.h - Implementation of stack data structure
*/


#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

namespace cstd {

/*
 * Stack class
 */

template <typename T>
class Stack {
	public:
		Stack();
		Stack(unsigned int size);
		~Stack();
		bool push(T* data, unsigned int count = 1);
		bool pop(T *data, unsigned int count = 1);
		bool peek(T *data);
		bool is_full();
		bool is_empty();
		unsigned int get_size();
		unsigned int get_top_index();
		void print_stack();

	private:
		T *m_arr;
		unsigned int m_size;
		int m_top;
};

template <typename T>
Stack<T>::Stack()
{
	m_size = 5;
	m_arr = new T[m_size];
	memset(m_arr, 0, m_size * sizeof(T));
	m_top = -1;
	std::cout << "Stack ininitialized: size " << m_size << std::endl;
}

template <typename T>
Stack<T>::Stack(unsigned int size)
{
	if (!m_size) {
		std::cout << "Cannot ininitialize Stack of size zero!" << std::endl;
		std::cout << "Ininitialiing to default size: 5" << std::endl;
		m_size = 5;
	} else {
		m_size = size;
	}
	m_arr = new T[m_size];
	memset(m_arr, 0, m_size * sizeof(T));
	m_top = -1;
	std::cout << "Stack ininitialized" << std::endl;
}

template <typename T>
Stack<T>::~Stack()
{
	std::cout << "Destroying stack" << std::endl;
	delete[] m_arr;
}

template <typename T>
bool Stack<T>::push(T *data, unsigned int count)
{
	if (!data)
		return false;

	if (count + m_top >= m_size) {
		std::cout << "Insufficient stack size - requested: " << count
			<< " available: " << (m_size - m_top - 1) << std::endl;
		return false;
	}

	memcpy(&m_arr[m_top + 1], data, count * sizeof(T));
	m_top += count;
	return true;
}

template <typename T>
bool Stack<T>::pop(T *data, unsigned int count)
{
	if (!data)
		return false;

	if ((int)m_top - (int)count < 0) {
		std::cout << "Insufficient stack size - requested: " << count
			<< " available: " << (m_top + 1) << std::endl;
		return false;
	}

	memcpy(data, &m_arr[m_top - count + 1], count * sizeof(T));
	memset(&m_arr[m_top - count + 1], 0, count * sizeof(T));
	m_top -= count;

	/* Popped data must be stored in reverse order */
	T start = 0, end = count - 1, temp;
	while (start < end) {
		temp = data[start];
		data[start] = data[end];
		data[end] = temp;
		start++;
		end--;
	}

	return true;
}

/* TODO return correct type : cannot return NULL type for string */
template <typename T>
bool Stack<T>::peek(T *data)
{
	if (!data)
		return false;

	if (is_empty())	{
		std::cout << "Stack is empty!" << std::endl;
		return false;
	}

	*data = m_arr[m_top];
	return true;
}

template <typename T>
bool Stack<T>::is_full()
{
	return (m_top == (m_size - 1));
}

template <typename T>
bool Stack<T>::is_empty()
{
	return (m_top == -1);
}

template <typename T>
unsigned int Stack<T>::get_size()
{
	return m_size;
}

template <typename T>
unsigned int Stack<T>::get_top_index()
{
	return m_top;
}

template <typename T>
void Stack<T>::print_stack()
{
	/* No generic implementaion */
	/* Extend specific types only */
	std::cout << "Printing stack is not supported for this data type" << std::endl;
}

template <>
void Stack<int>::print_stack()
{
	std::cout << "Printing stack" << std::endl;
	for (int i = 0; i < m_size; i++) {
		if (i == m_top)
			std::cout << i << ": " << m_arr[i] << "(TOP)" << std::endl;
		else
			std::cout << i << ": " << m_arr[i] << std::endl;
	}
}

} /* namespace cstd */

#endif /*__STACK_H__ */

