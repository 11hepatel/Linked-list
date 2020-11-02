/* Sample tester
 * We've included std::list below to show you how your types should behave.
 * You can use that for debugging.
 * Add the -g flag if you want to use gdb or cgdb
 */

// Use this to test, but not for your actual program.
#include <list>

// This is yours 
#include "MyList.h"

int main()
{
  MyList<int> l;
  //std::list<int> l;
    
  l.push_back(4000);
  l.push_back(200);
  l.push_back(100);
  cout << l.front() << endl;
  l.front() = 33;
  cout << l.front() << endl;
  cout << l.back() << endl;

  cout << l.size() << endl;
  l.push_back(4000);
  l.push_back(200);
  l.push_back(100);
  cout << l.front() << endl;
  cout << l.back() << endl;
    
  l.push_front(423);

  cout << l.front() << endl;
    
  MyList<int> sink;
  sink = l;
  cout << sink.front() << endl;
  cout << sink.back() << endl;
    
  l.insert(l.begin(), 3);
  l.insert(l.end(), 20);
  l.pop_front();
  l.reverse();
     
  int j = 0;
  for(auto i = 0; i < l.size(); i++)
  {
    cout << l.back() << endl;
    l.pop_back();
    j++;
  }
  
  /* 
  MyList<string> s;
  s.insert(0, "Hello");
  
  MyList<int> i;
  i.insert(1, 3);
  i.insert(4, 5);
  i.push_back(2);
  i.pop_front();
  cout<< i.front() << endl;
  cout << i.back() << endl;
  i.assign(2, 4);
  i.insert(2, 0);
  i.pop_front();
  i.push_back(4);
  i.reverse();
  cout << i.front() << endl;
  */

  return 0;
}

