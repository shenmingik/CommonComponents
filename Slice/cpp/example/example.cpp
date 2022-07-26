#include <iostream>

#include "Slice.h"
using namespace std;

int main() {
  char *data = "hello world";

  Slice slice1(data);
  Slice slice2 = slice1;

  cout << slice2.Data() << " " << slice2.Size() << endl;
  cout << slice1.ToString() << endl;
  cout << slice1.Empty() << endl;
  cout << (slice1 == slice2) << endl;
  if (slice1 > slice2) {
    cout << "slice1 > slice2" << endl;
  } else {
    cout << "slice2 <= slice2" << endl;
  }

  char *test = "hello";
  cout << slice1.StandWith(test) << endl;
  if (slice1 > test) {
    cout << "slice1 > test" << endl;
  } else {
    cout << "slice2 <= test" << endl;
  }
}