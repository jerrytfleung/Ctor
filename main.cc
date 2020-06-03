#include <iostream>
#include <initializer_list>
using namespace std;

template<class T>
class object {
 public:
  object() { cout << "Default ctor!" << endl; }
  object(T size, T default_value) { cout << "Parameterized ctor!" << endl; }
  object(initializer_list<T> init) { cout << "Initializer list ctor!" << endl; }
  void print() { cout << "print() is called!" << endl; } 
};

int main() {
  object<int> o1;
  o1.print();
  object<int> o2(10, 1);
  o2.print();
  object<int> o3{10, 1};
  o3.print();
  object<int> o4{};
  o4.print();
  object<int> o5();
  // o5.print(); compile error
  /**
   * error: request for member ‘print’ in ‘o5’, which is of non-class type ‘object<int>()’
   * o5.print();
   *    ^~~~~
   */
  return 0;
}
