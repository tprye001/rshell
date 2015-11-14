#include <iostream>
#include "parse.h"
#include <queue>
#include <string>
#include "execute.h"
#include "isConnector.h"

using namespace std;

bool executeAll(queue<string> q){
  //executes all arguments in queue
  while(!q.empty()){
    string cmd = q.front();
    vector<string> args;

    if (cmd == "exit") return false;

    while(!q.empty() && !isConnector(q.front())){
      args.push_back(q.front());
      q.pop();
    }
    //Connector OR- special case
    if(!q.empty() && q.front() == "||"){
      if(execute(cmd, args) == true){
        q.pop();
        while(!q.empty() && !isConnector(q.front())){
          q.pop();
        }
      }
      else{
        q.pop();
      }
    }
    //Connecor AND- special case
    else if(!q.empty() && q.front() == "&&"){
      if(execute(cmd, args) == false){
        q.pop();
        while(!q.empty() && !isConnector(q.front())){
          q.pop();
        }
      }
      else{
        q.pop(); //pops connector
      }
    }
    //Every other case
    else{
      execute(cmd, args);
      if(!q.empty()){
        q.pop();
      }
    }
    args.clear();
  }
  return true;
}

int main() {
  string line = "";
  cout << "$ ";  
  getline(cin, line);
  queue<string> toBeExecuted = parse(line);

  while(executeAll(toBeExecuted)) {
    cout << "$ ";  
    getline(cin, line);

    toBeExecuted = parse(line);
  }

  return 0;
}
