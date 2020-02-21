#pragma once

#include <memory>
#include <ostream>
#include <string>
#include <iostream>
#include "Person.h"


namespace LinkedList {
	template <typename T>
	class Node {
	private:
		const T value;    // The data held by the LinkedList
		std::unique_ptr<Node <T>> next; // unique_ptr to the next node
		Node<T>* prev;                 // raw (non-owning) ptr to the previous node
	public:
		Node() : value(), next(nullptr), prev(nullptr) {}
		// construct a node with string value, a unique_ptr to the next node, and a pointer to the previous node
		Node(const T& value, std::unique_ptr<Node <T>> next, Node <T>* prev)
			: value(value)
			, next(std::move(next))
			, prev(prev)
		{}
		// We can use the default destructor, since unique_ptr takes care of deleting memory
		~Node() = default;
		// return the value of the node
		T getValue() const { return value; }

		// return a raw (non-owning) pointer to the next node
		Node<T>* getNext() const { return next.get(); }
		// return a raw (non-owning) pointer to the previous node
		Node<T>* getPrev() const { return prev; }

		// write the value of the node to the ostream
		friend std::ostream & operator<<(std::ostream & os, const Node <T>& node)
		{
			os << node.getValue() << endl;
			return os;
		}

		template <typename U>
		friend class LinkedList;
	};

	template <typename T>
	class LinkedList {
	private:
		// ptr to the first node
		std::unique_ptr<Node <T>> head;
		// a raw pointer to the last node, the last node is always a dummy node
		// this is declared as a const ptr to a Node, so that tail never can
		// point anywhere else
		Node <T>* const tail;
	public:
		//create the dummy node, and make tail point to it
		LinkedList()
			: head(std::make_unique<Node <T>>())
			, tail(head.get())
		{}
		~LinkedList() = default;

		//if next is a nullptr (i.e. head is the dummy node), the list is emtpy
		bool isEmpty() const { return !head->next; }


		//return a pointer to first element
		Node <T>* begin() const { return head.get(); }
		//return a pointer to beyond-end element
		Node <T>* end() const { return tail; }

		// The insert function takes a pointer to node (pos) and a string (value). It creates a new
		// node which contains value. The new node is inserted into the LinkedList BEFORE the
		// node pointed to by pos.
		Node <T>* insert(Node <T>*pos, const T& value)
		{
			// Hvis value skal settes inn først, må next peke på det som nå er head
			if (pos == head.get())
			{
				head = std::make_unique<Node<T>>(value, move(head), nullptr);
				pos->prev = head.get();
				return head.get();
			}
			// Setter pos til next i den nye noden, og det som er før pos før den nye noden
			std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value, move(pos->prev->next), pos->prev);

			// Setter den nye noden inn etter elementet før pos
			pos->prev->next = move(newNode);

			// setter inn den nye noden før pos 
			pos->prev = pos->prev->next.get();

			return pos->prev;
		}

		// The find function traverses the linked list and returns a pointer to the first node
		// that contains the value given.
		// If the value isn't in the list, find returns a pointer to the dummy node at the end
		// of the list.
		Node <T>* find(const T& value)
		{
			Node <T>* node = head.get();
			while (node)
			{
				if (node->getValue() == value) 
				{ 
					return node;
				}
				node = node->getNext();
			}
			return tail;
		}

		// The remove function takes a pointer to a node, and removes the node from the list. The
		// function returns a pointer to the element after the removed node.
		Node <T>* remove(Node <T>* pos)
		{
			// Hvis head skal fjærnes, må next settes til head, og prev er nullptr.
			if (pos == head.get())
			{
				head = move(pos->next);
				head->prev = nullptr;
				return head.get();
			}

			// Ellementet etter pos må peke tilbake på det etter pos, pos ikke er sist
			if (pos->next)
			{
				pos->next->prev = pos->prev;
			}

			// Ellementet før pos må peke på det etter pos som neste element
			pos->prev->next = move(pos->next);

			
			return pos->next.get();
		}


		// The remove function takes a string and removes the first node which contains the value.
		void remove(const T& value)
		{
			remove(find(value));
		}

		// write a string representation of the list to the ostream
		friend std::ostream & operator<<(std::ostream & os, const LinkedList <T>& list)
		{
			Node <T>* node = list.head.get();
			while (node)
			{
				os << node->getValue() << endl;
				node = node->getNext();
			}
			return os;
		}
	};
}// namespace LinkedList

// test code 
void testLinkedList()
{
	std::cout << std::endl;
	LinkedList::LinkedList<int> l;
	l.insert(l.begin(), 1);
	l.insert(l.end(), 2);
	l.insert(l.end(), 5);
	std::cout << l << std::endl;
	l.insert(l.find(2), 9);
	l.insert(l.begin(), -3);
	l.remove(2);
	std::cout << l << std::endl;

	std::cout << std::endl;
	LinkedList::LinkedList<string> l2;
	l2.insert(l2.begin(), "en");
	l2.insert(l2.end(), "to");
	l2.insert(l2.end(), "fem");
	std::cout << l2 << std::endl;
	l2.insert(l2.find("to"), "ni");
	l2.insert(l2.begin(), "-tre");
	l2.remove("to");
	std::cout << l2 << std::endl;

	//std::cout << std::endl;
	//LinkedList::LinkedList<Person> l22;
	//Person p1{ "Olav", "Gran" };	//Person p2{ "Marieluise", "Gran" };	//Person p3{ "Sigrid", "Gran" };	//Person p4{ "Frauke", "Gran" };	//Person p5{ "Bjoern", "Gran" };
	//Person p6{ "Falsk", "Gran" };
	//Person p7{ "Ekte", "Gran" };
	//Person p8{ "Ikke noe", "Gran" };
	//l22.insert(l22.begin(), p1);
	//l22.insert(l22.end(), p2);
	//l22.insert(l22.end(), p3);
	//l22.insert(l22.end(), p6);
	//l22.insert(l22.end(), p4);
	//l22.insert(l22.end(), p5);
	//std::cout << l2 << std::endl;
	//l22.insert(l22.find(p6), p7);
	//l22.insert(l22.begin(), p8);
	//l22.remove(p6);
	//std::cout << l22 << std::endl;
}
//3b) Vet ikke...
//5b) operatorene == og << må være definert(overlastet) for datatypen vi vil bruke

