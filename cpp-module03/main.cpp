#include <iostream>
#include <string>
 
 using namespace std;

// Base class (parent)
class MyClass {


  public:
  MyClass(){
    cout << "created MyClass\n";
  }
    void myFunction() {
      cout << "Some content in parent class." ;
    }
};

// Derived class (child)
class MyChild: public MyClass {
    public:
    MyChild() {
        cout << "created MyChild\n";
    }
};

// Derived class (grandchild)
class MyGrandChild: public MyChild {
};

int main() {
  MyGrandChild myObj;
  myObj.myFunction();
  return 0;
}