/*
* queue.h - Implementation of circular queue data structure
*/

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>

namespace cstd {

/*
 * Queue class
 */

//TODO DEBUG_PRINT macro

template <typename T>
class Queue {
	public:
		Queue(unsigned int maxsize, bool debug_enable = 0);
		~Queue();

		bool is_full();
		bool is_empty();
		bool enqueue(T *data, unsigned int count = 1);
		bool dequeue(T *data, unsigned int count = 1);
		unsigned int len();
		unsigned int get_maxsize();
		/* For access only, no assignment */
		T operator[](unsigned int index);

	private:
		bool m_debug_enable;
		T *m_arr;
		unsigned int m_maxsize;
		unsigned int m_size;
		unsigned int m_front;
		unsigned int m_rear;
};

template <typename T>
Queue<T>::Queue(unsigned int maxsize, bool debug_enable)
{
	m_maxsize = maxsize;
	m_size = 0;
	m_debug_enable = debug_enable;
	m_front = 0;
	m_rear = 0;
	m_arr = nullptr;

	m_debug_enable = debug_enable;
	if (m_debug_enable)
		std::cout << "Queue: Constructor:" << std::endl;

	if (m_maxsize) {
		m_arr = new T[m_size];
		memset(m_arr, 0, m_maxsize * sizeof(T));
	}
}

template <typename T>
Queue<T>::~Queue()
{
	if (m_debug_enable)
		std::cout << "Queue: Destructor:" << std::endl;
	if (m_arr)
		delete[] m_arr;
}

template <typename T>
inline bool Queue<T>::is_full()
{
	return (m_size == m_maxsize);
}

template <typename T>
inline bool Queue<T>::is_empty()
{
	return (m_size == 0);
}

template <typename T>
inline unsigned int Queue<T>::len()
{
	return m_size;
}

template <typename T>
inline unsigned int Queue<T>::get_maxsize()
{
	return m_maxsize;
}

template <typename T>
bool Queue<T>::enqueue(T *data, unsigned int count)
{
	if (!data)
		return false;

	if (is_full()) {
		std::cout<< "Queue is full!" << std::endl;
		return false;
	}

	if (count > (m_maxsize - m_size)) {
		std::cout<< "Requested size is greater than available size!" << std::endl;
		return false;
	}

	if (m_debug_enable)
		std::cout << "Queue: filling " << count << " items to queue " << std::endl;

	if ((count + m_rear) > m_maxsize) {
		unsigned int offset = m_maxsize - m_rear;
		memcpy(&m_arr[m_rear], data, offset * sizeof(T));
		memcpy(&m_arr[0], (data + offset), (count - offset) * sizeof(T));
	} else {
		memcpy(&m_arr[m_rear], data, count * sizeof(T));
	}

	m_rear += count;
	m_rear %= m_maxsize;
	m_size += count;

	return true;
}

template <typename T>
bool Queue<T>::dequeue(T *data, unsigned int count)
{
	if (!data)
		return false;

	if (is_empty()) {
		std::cout << "Queue: is empty" << std::endl;
		return false;
	}

	if (count > m_size) {
		std::cout<< "Requested size is greater than current queue length!" << std::endl;
		return false;
	}

	if (m_debug_enable)
		std::cout << "Queue: Removing " << count << " items from queue " << std::endl;

	if ((count + m_front) > m_maxsize) {
		unsigned int offset = m_maxsize - m_front;
		memcpy(data, &m_arr[m_front], offset * sizeof(T));
		memset(&m_arr[m_front], 0, offset * sizeof(T));

		memcpy((data + offset), &m_arr[0], (count - offset) * sizeof(T));
		memset(&m_arr[0], 0, (count - offset) * sizeof(T));
	} else {
		memcpy(data, &m_arr[m_front], count * sizeof(T));
		memset(&m_arr[m_front], 0, count * sizeof(T));
	}

	m_front += count;
	m_front %= m_maxsize;
	m_size -= count;

	return true;
}

template <typename T>
T Queue<T>::operator[](unsigned int index)
{
	if (index < m_maxsize)
		return m_arr[index];
	std::cout << "Out of bounds index !!" << std::endl;
	return m_arr[0];
}


} /* namespace cstd */

#endif /*__QUEUE_H__ */



