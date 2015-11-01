#include <iostream>
#include "parse.h"
#include <queue>

using namespace std;

int main()
{
  while(1)
  {
    string line;
    cout << "$ ";  
    getline(cin, line);
 
    queue<string> toBeExecuted = parse(line);
    
    
  }
  return 0;
}
