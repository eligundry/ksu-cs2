/*
 * Author: Eli Gundry
 * Date: 04/02/2012
 * Name: stack.h
 * Description: Header file for linked lists 
 */

#ifndef CS33001_STACK_H_
#define CS33001_STACK_H_

#include <iostream>
#include <cassert>

template <typename T>
class Node
{
public:
	Node(): data(), next(0) {};
	Node(T item): data(item), next(0) {};

	T data;
	Node<T> *next;
};


template <typename T>
class Stack 
{
public:
	/*
	 * Default constructor for stack. 
	 */
	Stack(void): tos(0) {};

	/*
	 * Stack copy constructor.
	 */
	Stack(const Stack<T>&);

	/*
	 * Default desctructor  for stack. 
	 */
	~Stack();

	/*
	 * Stack assignment operator.
	 * Ex: Stack thing = other_thing; 
	 */
	Stack<T>& operator=(Stack<T>);

	/*
	 * Tells you if stack is empty
	 * Ex: thing.isEmpty(); 
	 */
	bool isEmpty() const { return tos == 0; };

	/*
	 * Checks to see if stack is full
	 * Ex: thing.isFull(); 
	 */
	bool isFull(void) const; 

	/*
	 * Pops the last element off the stack
	 * Ex: thing.pop(); 
	 */
	T pop();

	/*
	 * Prints all items in the stack
	 * Ex: thing.printAll(); 
	 */
	void printAll() const;

	/*
	 * Pushes item to top of the stack
	 * Ex: thing.push(1); 
	 */
	void push(const T&);

	/*
	 * Swaps two stacks
	 * Ex: thing.swap(other_thing); 
	 */
	void swap(Stack<T>&);

private:
	Node<T> *tos;

};

/*
 * Stack copy constructor.
 */
template <typename T>
Stack<T>::Stack(const Stack<T>& actual)
{
	Node<T> *bottom,
			*temptos,
			*tempNode;

	temptos = actual.tos;

	tos = 0;

	while (temptos != 0) {
		tempNode = new Node<T>(temptos->data);

		if (tos == 0) {
			tos = tempNode;
			bottom = tempNode;
		} else {
			bottom->next = tempNode;
			bottom = tempNode;
		}

		temptos = temptos->next;
	}
}

/*
 * Default destructor for stack. 
 */
template <typename T>
Stack<T>::~Stack()
{
	while (tos != 0) {
		Node<T> *temp = tos;
		tos = tos->next;
		delete temp;
	}
}

/*
 * Stack assignment operator.
 * Ex: Stack thing = other_thing; 
 */
template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T> rhs)
{
	swap(rhs);
	return *this;
}

/*
 * Checks to see if stack is full
 * Ex: thing.isFull(); 
 */
template <typename T>
bool Stack<T>::isFull() const
{
	Node<T> *temp = new(std::nothrow) Node<T>();

	if (temp == 0)
		return true;

	delete temp;
	return false;
}

/*
 * Pops the last element off the stack
 * Ex: thing.pop(); 
 */
template <typename T>
T Stack<T>::pop()
{
	assert(tos != 0);
	Node<T> *temp = tos;
	T result = tos->data;
	tos = tos->next;
	delete temp;
	return result;
}

/*
 * Prints all items in the stack
 * Ex: thing.printAll(); 
 */
template <typename T>
void Stack<T>::printAll() const
{
	Stack<T> temp(*this);

	while (!temp.isEmpty()) {
		std::cout << temp.pop() << " ";
	}

	std::cout << std::endl;
}

/*
 * Pushes item to top of the stack
 * Ex: thing.push(1); 
 */
template <typename T>
void Stack<T>::push(const T& item)
{
	assert(!isFull());
	Node<T> *temp = new Node<T>(item);
	temp->next = tos;
	tos = temp;
}

/*
 * Swaps two stacks
 * Ex: thing.swap(other_thing); 
 */
template <typename T>
void Stack<T>::swap(Stack<T>& rhs)
{
	Node<T> *temp = tos;
	tos = rhs.tos;
	rhs.tos = temp;
}

#endif
