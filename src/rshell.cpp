#include <iostream>
#include "parse.h"
#include <queue>
#include <string>
#include "execute.h"
#include "isConnector.h"

using namespace std;

int executeAll(queue<string>);

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
          if(!q.front().empty()){
            q.front().erase(0, q.front().size());
          }
          q.front().append("exit");
        }
        else if(x == 2){
          if(!q.front().empty()){
            q.front().erase(0,q.front().size());
          }
          q.front().append("true");
        }
        else if(x == 1){
          if(!q.front().empty()){
            q.front().erase(0,q.front().size());
          }
          q.front().append("false");
        }
        return;
      }
      else if(counter != 0){
        counter--;
        if ( q.front().size() > 1 && q.front().at(q.front().size()-2) == ')') {
          q.front().erase(q.front().size()-1, 1);
          new_q.push(q.front());
        }
        else {
          new_q.push(q.front());
          q.pop();
        }
      }  
    }

    else if(!q.front().empty() && q.front().at(0) == '('){
      new_q.push(q.front());
      q.pop();
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
  int ret = 2;
  while(!q.empty()){
    if(!q.empty() && q.front().at(0) == '('){
      help(q);

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
        if(q.front().at(0) == '('){
          int cnt = 1;
          if(q.front().size() > 1){
            q.front().erase(0,1);
          }
          else
            q.pop();
          while(cnt > 0){
            if(q.front().at(0) == '('){
              cnt++;
            }
            else if(q.front().at(q.front().size()-1) == ')'){
              cnt--;
            }
            if(cnt != 0){
              q.pop();
            }
          } 
          q.front().erase(0,q.front().size());
          q.front().append("true");
        }
        else{
          while(!q.empty() && !isConnector(q.front())){
            q.pop();
          }
        }
      }
      else{
        ret = 1;
        q.pop();
      }
    }
    //Connecor AND- special case
    else if(!q.empty() && q.front() == "&&"){
      if(execute(cmd, args) == false){
        ret = 1;
        q.pop();
        if(q.front().at(0) == '('){
          int cnt = 1;
          if(q.front().size() > 1){
            q.front().erase(0,1);
          }
          else 
            q.pop();
          while(cnt > 0){
            if(q.front().at(0) == '('){
              cnt++;
            }
            else if(q.front().at(q.front().size()-1) == ')'){
              cnt--;
            }
            if(cnt != 0){
              q.pop();
            }
          } 
          q.front().erase(0,q.front().size());
          q.front().append("false");
        }
        else{
          while(!q.empty() && !isConnector(q.front())){
            q.pop();
          }
        }
      }
      else{
        q.pop(); //pops connector
      }
  }
    //Every other case
    else{
      ret = execute(cmd, args) + 1;
      if(!q.empty()){
        q.pop();
      }
    }
    args.clear();
  }
  return ret;
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
