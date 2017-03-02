// Grace Milton
// CSE 20312 Lab 03 Part 3
// LinkedList.cpp
//
// Creates a linked list used to add two numbers together and return sum

#include <iostream>
#include <string>
using namespace std;

// Node class
template<typename T>
class Node {


  public:
     Node(const T &);
     T getValue() const; // Returns value contained in Node

     T value;
     Node<T> *next; // Points to next Node

};

// constructor for Node
template<typename T>
Node<T>::Node(const T &v) :value(v),next(nullptr) {}

// returns value for Node
template<typename T>
T Node<T>::getValue() const { return value; }

// List class
template<typename T>
class List {

  public:
     List();
     ~List();

     void pushFront(const T &);
     void print();
 
     Node<T> *head;
};

// Constructor for List
template<typename T>
List<T>::List() :head(nullptr) {}

// Deconstructor for List
template<typename T>
List<T>::~List()
{
   Node<T> *p = head; // Sets pointer to first node
   while (p != nullptr) 
   {
      Node<T> *next = p->next;
      delete p; // Deletes each node
      p = next;
   }
}

// Adds value to front of List
template<typename T>
void List<T>::pushFront(const T &v)
{

   Node<T> *x = new Node<T>(v);
   x->next = head;
   head = x;

}

// Displays value of List
template<typename T>
void List<T>::print()
{

   Node<T> *p = head;
   for ( ; p != nullptr; p = p->next)
   {
      cout << p->getValue();
   }
   cout << endl;

}

// Adds values stored in two Lists and returns third List
template<typename T>
List<T> addNumberLists(List<T> &l1, List<T> &l2)
{

   List<T> l3;
   Node<T> *p = l1.head;
   Node<T> *q = l2.head;
   int sum = 0, carry = 0;

   // Runs while one list not at end
   while (p != nullptr || q != nullptr)
   {  
      sum = carry;
      if (q != nullptr && p != nullptr) // Adds both lists is neither over
         sum = sum + p->getValue() + q->getValue();
      else if (p != nullptr && q == nullptr) // Adds List 1 if List 2 over
         sum += p->getValue();
      else if (p == nullptr && q != nullptr) // Adds List 2 if List 1 over
         sum += q->getValue();
      if (sum >= 10) // Carries the 1 if necessary
         carry = 1;
      else
         carry = 0;
      sum = sum % 10; // Takes modulus in case of carry
      l3.pushFront(sum); // Adds digit to List 3
      sum = 0; // Resets sum
      if (p != nullptr) // Increments pointer for List 1
         p = p->next;
      if (q != nullptr) // Increments pointer for List 2
         q = q->next;
   } 

   if (carry == 1) // Adds 1 to list if all digits added and need to carry
      l3.pushFront(1);   

   return l3;

}


// Driver
int main() {

   string numString1, numString2;
 
   while(cin >> numString1 >> numString2) // Runs until ctrl+d
   {
      List<int> numberone;
      List<int> numbertwo;

      // Adds numbers to List 1
      for (int i = 0; i < numString1.size(); i++)
      {
         numString1[i] = numString1[i] - 48;
         numberone.pushFront(numString1[i]);
      }
   
      // Adds numbers to List 2
      for (int i = 0; i < numString2.size(); i++)
      {
         numString2[i] = numString2[i] - 48;
         numbertwo.pushFront(numString2[i]);
      }
   
      // Sets List 3 with function
      List<int> numberthree = addNumberLists(numberone, numbertwo);
      numberthree.print(); // Prints sum of 2 numbers
   }

   return 0;

}
