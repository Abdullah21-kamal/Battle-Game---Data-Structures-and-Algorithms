//
//#include <iostream>
//#include <conio.h>
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include "Enemies\Enemy.h"
//#include "Generic_DS\Node.h"
//
//using namespace std;
//struct n // node declaration
//{
//	int priority;
//	Enemy info;
//	struct n* next;
//};
//  template <typename T>
//class enemy_Priority_Queue
//{
// private:
//	 Node<T>* a;
//	 Node<T>* b;
//
//public:
//	enemy_Priority_Queue()
//	{
//		f = nullptr;
//	}
//	template <typename T>
//	bool PQ<T>::enqueue(const T& newEntry)
//	{
//		Node<T>* newNodePtr = new Node<T>(newEntry);
//		
//		// Insert the new node
//		//if (isEmpty())
//		//	a = newNodePtr; // The queue is empty
//		//else
//		//	b->setNext(newNodePtr); // The queue was not empty
//		//b = newNodePtr; // New node is at back
//		////(backPtr->getItem())
//		//return true;
//	}
//	void insert(Enemy* x)
//	{
//		Enemy* t, * q;
//		//t = new n;
//		t = x;
//		//cout << x.GetPriority();
//		t->priority = x.GetPriority();
//		if (f == NULL || t->priority > f->priority)
//		{
//
//			t->next = f;
//			f = t;
//		}
//		else
//		{
//			q = f;
//			while (q->next != NULL && q->next->priority <= t->priority)
//				q = q->next;
//			t->next = q->next;
//			q->next = t;
//		}
//	}
//	void delet()
//	{
//		n* t;
//		if (f == NULL) //if queue is null
//			cout << "Queue Underflow\n";
//		else
//		{
//			t = f;
//			cout << "Deleted item is: " << t->info.GetID() << endl;
//			f = f->next;
//			free(t);
//		}
//	}
//	void show() //print queue {
//	{
//		n* ptr;
//		ptr = f;
//		if (f == NULL)
//			cout << "Queue is empty\n";
//		else
//		{
//			cout << "Queue is :\n";
//			cout << "Priority Item\n";
//			while (ptr != NULL)
//			{
//				cout << ptr->info.GetPriority() << "  " << ptr->info.GetID() << endl;
//				ptr = ptr->next;
//			}
//		}
//	}
//	//const Enemy toArray(int& count)
//	//{
//	//	n* ptr, *ptr2;
//	//	ptr = f;
//	//	if (f == NULL)
//	//	{
//	//		cout << "Queue is empty\n";
//	//	}
//	//		
//	//	else
//	//	{
//	//		cout << "Queue is :\n";
//	//		cout << "Priority Item\n";
//	//		
//	//		//while (ptr != NULL)
//	//	//	{
//	//		ptr2 = ptr;
//	//			cout << ptr->info.GetPriority() << ptr->info.GetID() << endl;
//	//			ptr = ptr->next;
//	//			return ptr2->info;
//	//			//}
//	//	}
//
//	//}
//	//template <typename T>
//	//const T* Queue<T>::toArray(int& count)
//	//{
//	//count = 0;
//
//	//if (!frontPtr)
//	//	return nullptr;
//	////counting the no. of items in the Queue
//	//Node<T>* p = frontPtr;
//	//while (p)
//	//{
//	//	count++;
//	//	p = p->getNext();
//	//}
//
//
//	//T* Arr = new T[count];
//	//p = frontPtr;
//	//for (int i = 0; i < count; i++)
//	//{
//	//	Arr[i] = p->getItem();
//	//	p = p->getNext();
//	//}
//	//return Arr;
// //    }
//
//	//Queue<Enemy*>  to_queue() {
//	//	// define q 
//	//	n* ptr;
//	//	ptr = f;
//	//	Queue<Enemy*> draw;
//	//	Enemy* ptr2;
//	//	while (ptr != NULL)
//	//	{
//	//		ptr2 = &ptr->info;
//	//		draw.enqueue(ptr2);
//	//		ptr = ptr->next;
//	//	}
//	//	return draw;
//	//}
//	int GetCounter()
//	{
//		n* ptr;
//		ptr = f;
//		int counter = 0;
//		while (ptr != NULL)
//		{
//			counter++;
//			ptr = ptr->next;
//		}
//		return counter;
//	}
//
//};