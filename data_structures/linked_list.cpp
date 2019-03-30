/*
* linked_list.cpp - Implementation of linked list
*/

#include <iostream>

/* ============== Node =========== */
template <typename T>
struct Node {
	Node(T val = 0);
	~Node();
	Node *m_next;
	Node *m_prev;
	T m_data;
};

template <typename T>
Node<T>::Node(T val)
{
	m_next = nullptr;
	m_prev = nullptr;
	m_data = val;
}

template <typename T>
Node<T>::~Node()
{

}

/* ============================== List =========================== */
template <typename T>
class List {
	public:
		List();
		~List();
		bool insert(T val);
		bool remove(T val);
		void print_list();
		T operator[](unsigned int index);

		T head();
		T tail();
		bool insert_at_head(T val);
		bool remove_head();
	private:
		Node<T> *m_cur_node;
		Node<T> *m_head;
		Node<T> *m_tail;
		unsigned int m_size;
};

template <typename T>
List<T>::List()
{
	m_cur_node = nullptr;
	m_head = nullptr;
	m_tail = nullptr;
	m_size = 0;
}

template <typename T>
List<T>::~List()
{

}

template <typename T>
bool List<T>::insert(T val)
{
	if (!m_size) {
		m_head = new Node<T>(val);
		m_tail = m_head;
		m_size++;
		return true;
	}

	m_cur_node = m_head;
	while (m_cur_node->m_next)
		m_cur_node = m_cur_node->m_next;

	m_cur_node->m_next = new Node<T>(val);
	m_tail = m_cur_node->m_next;
	m_tail->m_prev = m_cur_node;
	m_size++;
	return true;
}

template <typename T>
T List<T>::head()
{
	if (m_size)
		return m_head->m_data;
	return 0;
}

template <typename T>
T List<T>::tail()
{
	if (m_size)
		return m_tail->m_data;
	return 0;
}

template <typename T>
bool List<T>::remove(T val)
{
	if (!m_size)
		return false;

	m_cur_node = m_head;
	unsigned int len = m_size;

	while (--len && (m_cur_node->m_data != val))
		m_cur_node = m_cur_node->m_next;

	if (m_cur_node->m_data == val) {
		if (m_cur_node == m_head) {
			if (m_size > 1) {
				m_head = m_cur_node->m_next;
				m_head->m_prev = nullptr;
				std::cout << "last elemetnt" << std::endl;
			}
		} else if (m_cur_node == m_tail) {
			if (m_size > 1) {
				m_tail = m_cur_node->m_prev;
				m_tail->m_next = nullptr;
			}
		} else {
			m_cur_node->m_prev->m_next = m_cur_node->m_next;
			m_cur_node->m_next->m_prev = m_cur_node->m_prev;
		}

		delete m_cur_node;
		m_size--;
		if (!m_size)
			m_head = m_tail = nullptr;
		return true;
	}
	return false;
}

template <typename T>
T List<T>::operator[](unsigned int index)
{
	unsigned int i = 0, len = m_size;
	m_cur_node = m_head;
	while (i++ != index && len--)
		m_cur_node = m_cur_node->m_next;

	if (!m_cur_node)
		return 0;
	return m_cur_node->m_data;
}

template <typename T>
void List<T>::print_list()
{
	/* No generic implementaion */
	/* Extend specific types only */
	std::cout << "Printing list is not supported for this data type" << std::endl;
}

template <>
void List<int>::print_list()
{
	std::cout << "Printing list :: size: " << m_size << std::endl;

	m_cur_node = m_head;
	for (unsigned int i = 0; i < m_size; i++) {
		std::cout << i << ":" << m_cur_node->m_data << std::endl;
		m_cur_node = m_cur_node->m_next;
	}
	std::cout << std::endl;
}

 /* ==================================Test Stubs===================================== */

void test_int_list()
{
	List<int> list;
	list.insert(2);
	list.insert(1);
	list.insert(-22);
	list.insert(-44);
	list.print_list();

	std:: cout << "head : " << list.head() << std::endl;

	list.remove(2);
	list.remove(5);
	list.print_list();

	std:: cout << "tail : " << list.tail() << std::endl;

	list.remove(-22);
	list.remove(-44);
	list.insert(-12);
	list.remove(1);
	list.print_list();

	list.insert(234);
	list.print_list();

	list.remove(234);
	list.remove(-12);
	list.print_list();

	std:: cout << "elements" << std::endl;
	std:: cout << list[0] << std::endl;
	std:: cout << list[1] << std::endl;
	std:: cout << list[2] << std::endl;
	std:: cout << list[3] << std::endl;

	std:: cout << "tail : " << list.tail() << std::endl;

}

/* ============================================================== */

int main()
{
	std::cout << "==============Linked List=============" << std::endl;


	test_int_list();

	return 0;
}


