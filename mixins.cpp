#include <string>
//from http://www.artima.com/weblogs/viewpost.jsp?thread=132988
#include <ctime>
#include <iostream>
using namespace std;

template<class T> class TimeStamped : public T {
  long timeStamp;
public:
  TimeStamped() { timeStamp = time(0); }
  long getStamp() { return timeStamp; }
};

template<class T> class SerialNumbered : public T {
  long serialNumber;
  static long counter;
public:
  SerialNumbered() { serialNumber = counter++; }
  long getSerialNumber() { return serialNumber; }
};

// Define and initialize the static storage:
template<class T> long SerialNumbered<T>::counter = 1;

int main() {
  TimeStamped<SerialNumbered<string> > mixin1, mixin2;
  mixin1.append("test string 1"); // A string method
  mixin2.append("test string 2");
  cout << mixin1 << " " << mixin1.getStamp() << " " <<
    mixin1.getSerialNumber() << endl;
  cout << mixin2 << " " << mixin2.getStamp() << " " <<
    mixin2.getSerialNumber() << endl;
} /* Output: (Sample)
test string 1 1129775318 1
test string 2 1129775318 2