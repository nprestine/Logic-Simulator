#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream>



template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;
  void printall() const;

private:
  /// Add whatever helper functions and data members you need below
  int arryness; //varible for arraysize
  std::vector<T> s;
  PComparator comparator;
  void trickleup(int);
  void heapify(int);


};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
{
  arryness = m;
  comparator = c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){ //deconstructor

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleup(int node){
  int parent = (node-1)/arryness;
  while(parent >= 0 && comparator(s[node],s[parent])){
    std::swap(s[parent], s[node]);
    node = parent;
    parent = (node-1)/arryness;
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int node){ //trickle down
  unsigned int leftChild = (arryness*node)+1;
  unsigned int best = leftChild;
  //check to make sure children are inbounds
  if(leftChild >= s.size()) return;

  unsigned int rightChild = std::min(arryness*node+arryness,(int)s.size()-1);
  
  for(unsigned int currChild = leftChild+1; currChild <= rightChild; currChild++){ //iterate through heap
    //check if this is the best of the children
          //if yes, then assign this to be the best child
    if(comparator(s[currChild], s[best])){
      best = currChild;
    }
  }
  //check if this best child is better than the current node
    //if yes, swap and keep recurssing on the child node index
    //else return, you are done 
  if(comparator(s[best], s[node])){
    std::swap(s[node],s[best]);
    heapify(best);
  }
  else return;

}


template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  s.push_back(item);
  trickleup(s.size()-1);
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){ //throw exception for empty heap
    throw std::underflow_error("No data in stack");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return s[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("No data in stack");
  }
  std::swap(s[0],s[s.size()-1]);
  s.pop_back();
  heapify(0);
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  if(s.size() == 0) return true;
  else return false;
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return s.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::printall() const{
  std::cout << "current heap" << std::endl;
  for(int i = 0; i<s.size(); i++){
    std::cout << s[i] << std::endl;
  }
}
#endif

