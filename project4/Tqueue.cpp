#ifndef TQUEUE_CPP
#define TQUEUE_CPP

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T, int N>
class Tqueue {
public:
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor
  //Name: Copy Constructor
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue( const Tqueue<T,N>& x ); //Copy Constructor
  //Name: Destructor
  //Desc: Empties m_data
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor
  //Name: ClearData
  //Desc: Empties m_data
  //Precondition: Existing Tqueue
  //Postcondition: Empty m_data
  void ClearData();
  //Name: Enqueue
  //Desc: Adds item to the back of queue
  //Precondition: Existing Tqueue
  //Postcondition: Returns true if successful else false
  bool Enqueue(T data); //Adds item to queue (to back)
  //Name: Dequeue
  //Desc: Removes item from queue (from front)
  //Precondition: Existing Tqueue
  //Postcondition: Returns true if successful else false
  bool Dequeue();
  //Name: Sort
  //Desc: Sorts the contents of the Tqueue
  //NOTE: You may implement to only deal with dereferenced pointers
  //Precondition: Existing Tqueue
  //Postcondition: Contents of Tqueue is sorted (ascending)
  void Sort();
  //Name: IsEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int IsEmpty(); //Returns 1 if queue is empty else 0
  //Name: IsFull
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is full else 0
  int IsFull(); //Returns 1 if queue is full else 0
  //Name: Size
  //Desc: Returns size of queue
  //Precondition: Existing Tqueue
  //Postcondition: Returns size of queue
  int Size();
  //Name: Overloaded assignment operator
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T,N>& operator=( Tqueue<T,N> y); //Overloaded assignment operator for queue
  //Name: Overloaded [] operator
  //Precondition: Existing Tqueue
  //Postcondition: Returns object from Tqueue using []
  T& operator[] (int x);//Overloaded [] operator to pull data from queue
private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue
  int m_back; //Back of the queue
};

//**** Add class definition below ****


//Name: Tqueue - Default Constructor
//Precondition: None (Must be templated)
//Postcondition: Creates a queue using dynamic array
template <class T, int N>
Tqueue<T,N>::Tqueue() {
  m_front = 0;
  m_back = 0;
  m_data = new T[N];
  cout << "X run default" << endl;
}

//Name: Copy Constructor
//Precondition: Existing Tqueue
//Postcondition: Copies an existing Tqueue
template <class T, int N>
Tqueue<T,N>::Tqueue( const Tqueue<T,N>& x ) {
  
  m_front = x.m_front;
  m_back = x.m_back;
  m_data = new T[N];

  //iterate over array and copy each element.
  for (int i = 0; i < Size(); i++) { 
    m_data[i] = x.m_data[i];
  }

  cout << "X run copy\n";
}

//Name: Destructor
//Desc: Empties m_data
//Precondition: Existing Tqueue
//Postcondition: Destructs existing Tqueue
template <class T, int N>
Tqueue<T,N>::~Tqueue() {
  delete[] m_data;
  m_data = NULL;
  cout << "X run destructor\n";
}

//Name: ClearData
//Desc: Empties m_data
//Precondition: Existing Tqueue
//Postcondition: Empty m_data
template <class T, int N>
void Tqueue<T,N>::ClearData() {
  delete[] m_data;
  m_data = NULL;

  m_front = 0;
  m_back = 0;
  
  cout << "X run cleardata\n";
}

//Name: Enqueue
//Desc: Adds item to the back of queue
//Precondition: Existing Tqueue
//Postcondition: Returns true if successful else false
template <class T, int N>
bool Tqueue<T,N>::Enqueue(T data) {
  
  if (IsFull() != 1) {
    
    m_data[m_back] = data;
    m_back += 1;
    
    cout << "X run true nq\n";
    return true;
  }
  cout << "X run false nq\n";
  return false;
}

//Name: Dequeue
//Desc: Removes item from queue (from front)
//Precondition: Existing Tqueue
//Postcondition: Returns true if successful else false
template <class T, int N>
bool Tqueue<T,N>::Dequeue() {

  //if not empty remove item from front of queue.
  if (IsEmpty() != 1) {
    T* newArray = new T[N];

    //iterate over the array and copy starting from the second item.
    for (int i = m_front; i < m_back; i++) {
      newArray[i] = m_data[i + 1];
    }

    //change the length of the list
    int back = m_back - 1;
    ClearData();
    m_back = back;

    //set the cleared data to the new array
    m_data = newArray;
    cout << "X run true dq\n";
    return true;
  }
  cout << "X run false dq\n";
  return false;
  
}

//Name: Sort
//Desc: Sorts the contents of the Tqueue
//NOTE: You may implement to only deal with dereferenced pointers
//Precondition: Existing Tqueue
//Postcondition: Contents of Tqueue is sorted (ascending)
template <class T, int N>
void Tqueue<T,N>::Sort() {

  //used to start a loop
  bool notSorted = true;
  while (notSorted) {
    notSorted = false;

    for (int i = 1; i < m_back; i++) {

      //If the data is greater than the following.
      if (m_data[i - 1] > m_data[i]) {

	//set switch two data values around.
	T data = m_data[i - 1];
	m_data[i - 1] = m_data[i];
	m_data[i] = data;

	//make it so that the loop starts again after.
	notSorted = true;
      }
    }
  }
  cout << "X run sort\n";
}

//Name: IsEmpty
//Precondition: Existing Tqueue
//Postcondition: Returns 1 if queue is empty else 0
template <class T, int N>
int Tqueue<T,N>::IsEmpty() {

  //if the size of the array is empty.
  if (Size() == 0)
    return 1;
  return 0;
}

//Name: IsFull
//Precondition: Existing Tqueue
//Postcondition: Returns 1 if queue is full else 0
template <class T, int N>
int Tqueue<T,N>::IsFull() {
  if (Size() == (N + 1))
    return 1;
  return 0;
}

//Name: Size
//Desc: Returns size of queue
//Precondition: Existing Tqueue
//Postcondition: Returns size of queue
template <class T, int N>
int Tqueue<T,N>::Size() {
  int size = m_back - m_front;
  return size;
}
 
//Name: Overloaded assignment operator
//Precondition: Existing Tqueue
//Postcondition: Sets one Tqueue to same as a second Tqueue using =
template <class T, int N>
Tqueue<T,N>& Tqueue<T,N>::operator=( Tqueue<T,N> y) {

  //delete previous
  if (IsEmpty() != 1) {ClearData();}

  ClearData();
  m_front = y.m_front;
  m_back = y.m_back;
  m_data = new T[N];

  //iterate over array and copy each element.
  for (int i = 0; i < Size(); i++) { 
    m_data[i] = y.m_data[i];
  }
  cout << "X run overloaded\n";

  y.ClearData();
  return *this;
}

//Name: Overloaded [] operator
//Precondition: Existing Tqueue
//Postcondition: Returns object from Tqueue using []
template <class T, int N>
T& Tqueue<T,N>::operator[] (int x) {
  return m_data[x];
}






// To test just Lqueue follow these instructions:
//   1.  Uncomment out int main below
//   2.  make Tqueue
//   3.  ./Tqueue (try valgrind too!)


/*int main () {
  //Test 1 - Default Constructor and Push
  cout << "Test 1 - Default Constructor and Push Running" << endl;
  //Test Default Constructor
  Tqueue <string, 10> newTQ1;
  //Push 4 nodes into Lqueue
  newTQ1.Enqueue("One");
  newTQ1.Enqueue("Bob");
  newTQ1.Enqueue("One");
  newTQ1.Enqueue("Two");
  newTQ1.Enqueue("Fourteen");
  cout << endl;
  newTQ1.Sort();
  
  //Test 2 - Copy Constructor and Assignment Operator
  cout << "Test 2 - Copy Constructor and Assignment Operator Running" << endl;
  //Test Copy constructor
  Tqueue <string, 10> newTQ2(newTQ1);
  //Test Overloaded Assignment Operator
  Tqueue <string, 10> newTQ3;
  newTQ3 = newTQ1;
  cout << endl;

  cout << newTQ2.Size() << endl;
  cout << newTQ3.Size() << endl;
  cout << endl;
  
  //Test 3 - Test Dequeue
  cout << "Test 3 - Dequeue" << endl;
  for(int i = 0; i < newTQ1.Size(); i++){
    cout << newTQ1[i] << endl;
  }
  cout << newTQ1.Dequeue() << endl;
  cout << endl;
  newTQ1.Dequeue();

  //Test 4 - Test Overloaded []
  cout << "Test 4 - Test Overloaded []" << endl;
  for(int i = 0; i < newTQ1.Size(); i++){
    cout << newTQ1[i] << endl;
  }
  cout << endl;
  
  //Test 5 - Test Size and ClearData
  cout << "Test 5 - Size and ClearData" << endl;
  //Test GetSize()
  cout << "Outputting the size" << endl;
  cout << newTQ1.Size() << endl;
  //Test Clear()
  cout << "Clearing all nodes" << endl;
  newTQ1.ClearData();
  cout << "Outputting the size" << endl;
  cout << newTQ1.Size() << endl;
  cout << endl;
  
  return 0;
  }*/

#endif
