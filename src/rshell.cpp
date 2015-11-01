#include <iostream>
#include "parse.h"
#include <queue>
#include <string>

using namespace std;

/*returns true if s is a connector, false otherwise*/
bool connectorsCheck(string s)
{
  //vector of connectors
  vector<string> connectors = {";", "&&", "||"};

  for(int c = 0; c < connectors.size(); c++)
  {
    if(connectors.at(c) = s)
      return true;
  }
  return false;
}

bool executeAll(queue<string> q){
  //Vector of connectors
  vector<string> connectors = {";", "&&", "||"}

  //executes all arguments in queue
  for(int i = 0; i < q.size(); i++){
    string cmd = q.front();
    q.pop();
    vector<string> args;
   
    while(!connectorsCheck(q.front())){
      args.push_back(q.front());
      q.pop();
    }

    //Connector OR- special case
    if(q.front() == "||"){
      if(execute(cmd, args) == true){
        while(!connectorsCheck(q.front())){
          q.pop();
        }
        q.pop();
      }
    }

    //Connecor AND- special case
    else if(q.front() == "&&"){
      if(execute(cmd, args) == false){
        while(!connectorsCheck(q.front())){
            q.pop();
        }
        q.pop();
      }
    }

    //Everyother case
    else{
      bool s = execute(cmd, args);
    }

    args.clear();
  }
  return true;
}

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
