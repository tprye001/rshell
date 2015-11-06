#include <iostream>
#include "parse.h"
#include <queue>
#include <string>
#include "execute.h"

using namespace std;

/*returns true if s is a connector, false otherwise*/
bool connectorsCheck(string s)
{
  //vector of connectors
  vector<string> connectors;
  connectors.push_back(";");
  connectors.push_back("&&");
  connectors.push_back("||");

  for(unsigned c = 0; c < connectors.size(); c++)
  {
    if(connectors.at(c) == s)
      return true;
  }
  return false;
}

bool executeAll(queue<string> q){
  //executes all arguments in queue
  while(!q.empty()){
    string cmd = q.front();
    vector<string> args;
   
    while(!q.empty() && !connectorsCheck(q.front())){
      args.push_back(q.front());
      q.pop();
    }
     //Connector OR- special case
      if(!q.empty() && q.front() == "||"){
        if(execute(cmd, args) == true){
          while(!q.empty() && !connectorsCheck(q.front())){
            q.pop();
         }
         q.pop();
       }
       q.pop();
     }
     //Connecor AND- special case
     else if(!q.empty() && q.front() == "&&"){
        if(execute(cmd, args) == false){
         while(!q.empty() && !connectorsCheck(q.front())){
              q.pop();
         }
         q.pop(); //pops connector
        }
        q.pop(); //pops connector
     }
     //Every other case
     else{
      execute(cmd, args);
      if(!q.empty()){
        q.pop();
      }
    }
    args.clear();
    //cout << "Front of q: " << q.front();
    //q.pop(); //pop off connector

  }
  return true;
}

int main()
{
  while(1) {
    string line;
    cout << "$ ";  
    getline(cin, line);
 
    queue<string> toBeExecuted = parse(line);
    executeAll(toBeExecuted);

  }

  return 0;
}
//this is the end of the program
