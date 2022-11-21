////#include <iostream>
////#include <vector>
////using namespace std;
////
////// Function to swap position of two elements
////void swap(int* a, int* b) {
////    int temp = *b;
////    *b = *a;
////    *a = temp;
////}
////
////// Function to heapify the tree
////void heapify(vector<int>& hT, int i) {
////    int size = hT.size();
////
////    // Find the largest among root, left child and right child
////    int largest = i;
////    int l = 2 * i + 1;
////    int r = 2 * i + 2;
////    if (l < size && hT[l] > hT[largest])
////        largest = l;
////    if (r < size && hT[r] > hT[largest])
////        largest = r;
////
////    // Swap and continue heapifying if root is not largest
////    if (largest != i) {
////        swap(&hT[i], &hT[largest]);
////        heapify(hT, largest);
////    }
////}
////
////// Function to insert an element into the tree
////void insert(vector<int>& hT, int newNum) {
////    int size = hT.size();
////    if (size == 0) {
////        hT.push_back(newNum);
////    }
////    else {
////        hT.push_back(newNum);
////        for (int i = size / 2 - 1; i >= 0; i--) {
////            heapify(hT, i);
////        }
////    }
////}
////
////// Function to delete an element from the tree
////void deleteNode(vector<int>& hT, int num) {
////    int size = hT.size();
////    int i;
////    for (i = 0; i < size; i++) {
////        if (num == hT[i])
////            break;
////    }
////    swap(&hT[i], &hT[size - 1]);
////
////    hT.pop_back();
////    for (int i = size / 2 - 1; i >= 0; i--) {
////        heapify(hT, i);
////    }
////}
////
////// Print the tree
////void printArray(vector<int>& hT) {
////    for (int i = 0; i < hT.size(); ++i)
////        cout << hT[i] << " ";
////    cout << "\n";
////}
////
////// Driver code
//////int main() {
//////    vector<int> heapTree;
//////
//////    insert(heapTree, 3);
//////    insert(heapTree, 4);
//////    insert(heapTree, 9);
//////    insert(heapTree, 5);
//////    insert(heapTree, 2);
//////
//////    cout << "Max-Heap array: ";
//////    printArray(heapTree);
//////
//////    deleteNode(heapTree, 4);
//////
//////    cout << "After deleting an element: ";
//////
//////    printArray(heapTree);
//////}
//
//#include <iostream>
//#include <conio.h>
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include "Enemies/Enemy.h"
//using namespace std;
//
//struct n // node declaration
//{
//    double priority;
//    int info;
//    struct n* next;
//};
//class Priority_Queue
//{
//private:
//    Enemy* f;
//
//public:
//    Priority_Queue()
//    {
//
//        f = NULL;
//    }
//    void insert(int i, double p)
//    {
//        Enemy* t, * q;
//        t = new Enemy;
//        t->info = i;
//        t->priority = p;
//        if (f == NULL || p < f->priority)
//        {
//            t->next = f;
//            f = t;
//        }
//        else
//        {
//            q = f;
//            while (q->next != NULL && q->next->priority <= p)
//                q = q->next;
//            t->next = q->next;
//            q->next = t;
//        }
//    }
//    void delet()
//    {
//        n* t;
//        if (f == NULL) //if queue is null
//            cout << "Queue Underflow\n";
//        else
//        {
//            t = f;
//            cout << "Deleted item is: " << t->info << endl;
//            f = f->next;
//            free(t);
//        }
//    }
//    void show() //print queue {
//    {
//        n* ptr;
//        ptr = f;
//        if (f == NULL)
//            cout << "Queue is empty\n";
//        else
//        {
//            cout << "Queue is :\n";
//            cout << "Priority Item\n";
//            while (ptr != NULL)
//            {
//                cout << ptr->priority << " " << ptr->info << endl;
//                ptr = ptr->next;
//            }
//        }
//    }
//};
///*int main()
//{
//    int c, i, p;
//    Priority_Queue pq;
//    do
//    {
//        cout << "1.Insert\n";
//        cout << "2.Delete\n";
//        cout << "3.Display\n";
//        cout << "4.Exit\n";
//        cout << "Enter your choice : ";
//        cin >> c;
//        switch (c)
//        {
//        case 1:
//            cout << "Input the item value to be added in the queue : ";
//            cin >> i;
//            cout << "Enter its priority : ";
//            cin >> p;
//            pq.insert(i, p);
//            break;
//        case 2:
//            pq.delet();
//            break;
//        case 3:
//            pq.show();
//            break;
//        case 4:
//            break;
//        default:
//            cout << "Wrong choice\n";
//        }
//    } while (c != 4);
//
//    return 0;
//}*/
#include <iostream>
#include <conio.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
struct n // node declaration
{
	int priority;
	Enemy info;
	struct n* next;
};

class enemy_Priority_Queue
{
private:
	n* f;

public:
	enemy_Priority_Queue()
	{
		f = NULL;
	}
	void insert(Enemy x)
	{
		n* t, * q;
		t = new n;
		t->info = x;
		//cout << x.GetPriority();
		t->priority = x.GetPriority();
		if (f == NULL || t->priority > f->priority)
		{
			
			t->next = f;
			f = t;
		}
		else
		{
			q = f;
			while (q->next != NULL && q->next->priority <= t->priority)
				q = q->next;
			t->next = q->next;
			q->next = t;
		}
	}
	void delet()
	{
		n* t;
		if (f == NULL) //if queue is null
			cout << "Queue Underflow\n";
		else
		{
			t = f;
			cout << "Deleted item is: " << t->info.GetID() << endl;
			f = f->next;
			free(t);
		}
	}
	void show() //print queue {
	{
		n* ptr;
		ptr = f;
		if (f == NULL)
			cout << "Queue is empty\n";
		else
		{
			cout << "Queue is :\n";
			cout << "Priority Item\n";
			while (ptr != NULL)
			{
				cout << ptr->info.GetPriority() << "  " << ptr->info.GetID() << endl;
				ptr = ptr->next;
			}
		}
	}
	//const Enemy toArray(int& count)
	//{
	//	n* ptr, *ptr2;
	//	ptr = f;
	//	if (f == NULL)
	//	{
	//		cout << "Queue is empty\n";
	//	}
	//		
	//	else
	//	{
	//		cout << "Queue is :\n";
	//		cout << "Priority Item\n";
	//		
	//		//while (ptr != NULL)
	//	//	{
	//		ptr2 = ptr;
	//			cout << ptr->info.GetPriority() << ptr->info.GetID() << endl;
	//			ptr = ptr->next;
	//			return ptr2->info;
	//			//}
	//	}

	//}
	//template <typename T>
	//const T* Queue<T>::toArray(int& count)
	//{
	//count = 0;

	//if (!frontPtr)
	//	return nullptr;
	////counting the no. of items in the Queue
	//Node<T>* p = frontPtr;
	//while (p)
	//{
	//	count++;
	//	p = p->getNext();
	//}


	//T* Arr = new T[count];
	//p = frontPtr;
	//for (int i = 0; i < count; i++)
	//{
	//	Arr[i] = p->getItem();
	//	p = p->getNext();
	//}
	//return Arr;
 //    }
	
	Queue<Enemy*>  to_queue() {
		// define q 
		n* ptr;
		ptr = f;
		Queue<Enemy*> draw;
		Enemy* ptr2;
		while (ptr != NULL)
		{
			ptr2 = &ptr->info;
			draw.enqueue(ptr2);
			ptr = ptr->next;
		}
		return draw;
	}
	int GetCounter()
	{
		n* ptr;
		ptr = f;
		int counter = 0;
		while (ptr != NULL)
		{
			counter++;
			ptr = ptr->next;
		}
		return counter;
	}
	
};