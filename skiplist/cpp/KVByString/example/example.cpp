#include <iostream>

#include "SkipList.h"
using namespace std;
int main() {
  SkipList skiplist;

  //添加语义测试
  for (int i = 0; i < 10; i++) {
    string key = to_string(i);
    string value = to_string(random() % 1000);
    skiplist.Put(key, value);
    cout << skiplist.Get(key) << endl;
  }

  //修改语义测试
  string key = to_string(0);
  skiplist.Put(key, "1433223");
  cout << skiplist.Get(key) << endl;

  //IsExist接口测试
  cout << skiplist.IsExist("9") << endl;
  cout << skiplist.IsExist("100") << endl;

  //Delete接口测试
  skiplist.Delete("9");
  cout << skiplist.IsExist("9") << endl;
}