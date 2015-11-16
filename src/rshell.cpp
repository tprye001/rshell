#include <iostream>
#include "parse.h"
#include <queue>
#include <string>
#include "execute.h"
#include "isConnector.h"

using namespace std;

void help(queue<string>& q){
  if(q.front().size() > 1){
    q.front().erase(0,1);
  }
  else
    q.pop();

  queue<string> new_q;
  int counter = 0;

  while(!q.empty()){
    if(q.front().at(q.front().size()-1) == ')'){
      if(counter == 0){
        if(q.front().size() > 1){
          q.front().erase(q.front().size()-1, 1);
          new_q.push(q.front());
        }
        
        int x = executeAll(new_q);

        if(x == 0){
          q.front().erase(0, q.front().size()-1);
          q.front().append("exit");
        }
        else if(x == 1){
          q.front().erase(0,q.front().size()-1);
          q.front().append("true");
        }
        else if(x == 2){
          q.front().erase(0,q.front().size()-1);
          q.front().append("false");
        }
        return;
      }
      else if(counter != 0){
        counter--;
      }  
    }

    else if(q.front().at(0) == '('){
      counter++;
    }

    else{
      new_q.push(q.front());
      q.pop();
    }
  }
  return;
}

int executeAll(queue<string> q){
  //executes all arguments in queue
  while(!q.empty()){
    if(!q.empty() && q.front().at(0) == '('){
      help(&queue<string> q);

    }
    string cmd = q.front();
    vector<string> args;

    if (cmd == "exit") return 0;

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

  while(executeAll(toBeExecuted) != 0) {
    cout << "$ ";  
    getline(cin, line);

    toBeExecuted = parse(line);
  }

  return 0;
}
