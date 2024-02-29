#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <vector>

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

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  void heapify(int start);
  int ary;
  PComparator comp;
};

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
{
  ary = m;
  comp = c;
} 

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() 
{

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) 
{
  data.push_back(item);
  int idx = data.size() - 1;
    while (idx != 0) {
        int p_idx = (idx - 1) / ary;
        T& current = data[idx];
        T& parent = data[p_idx];
        if (comp(parent, current)) {
            break;
        }
        // swap current and parent
        std::swap(current, parent);
        idx = p_idx;
    }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("underflow error");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data.front();
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

    throw std::underflow_error("underflow error");
  }

  // switch front and back of vector
  std::swap(data[0], data[data.size()-1]);
  data.pop_back();

  heapify(0);
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return data.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return data.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int start)
{
  int c_idx = start * ary + 1;

  // if element does not have children
  if (c_idx >= data.size())
    return;

  T current = data[start];
  // finding best (elligible) child
  T best = data[c_idx];
  int best_idx = c_idx;

  for (int i = 1; i < ary; i++) {
    // checking siblings
    if (c_idx + i < data.size()) {
      T sib = data[c_idx+i];
      
      if (comp(sib, best)) {
        // save sib as new the best
        best = sib;
        best_idx = c_idx+i;
      }
    }
  }
  if (comp(current, best))
    return;
  // swap parent with its best child
  std::swap(data[start], data[best_idx]);
  
  heapify(best_idx);
}

#endif

