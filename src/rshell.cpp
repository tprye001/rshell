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
  for(unsigned i = 0; i < q.size(); i++){
    string cmd = q.front();
    vector<string> args;
   
    while(!q.empty() && !connectorsCheck(q.front())){
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
      execute(cmd, args);
    }
    args.clear();
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
