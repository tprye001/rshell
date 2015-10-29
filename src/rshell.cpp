#include <iostream>
#include "parse.h"
#include <queue>

using namespace std;

int main()
{
  while(1)
  {
    string commands;
    cout << "$ ";  
    getline(cin, commands);
 
    queue<ABC> toBeExecuted = parse(commands);
  }
  return 0;
}
