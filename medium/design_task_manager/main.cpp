#include <bits/stdc++.h>  
using namespace std;

class TaskManager {
public:
    TaskManager(vector<vector<int>>& tasks) {
          
    }
    
    void add(int userId, int taskId, int priority) {
        
    }
    
    void edit(int taskId, int newPriority) {
        
    }
    
    void rmv(int taskId) {
        
    }
    
    int execTop() {
        
    }
};


int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    TaskManager tm;

    vector<string> ops(n);
    for (int i = 0; i < n; i ++)
      cin >> ops[i];

    for (string o : ops) {
        
      switch(o) {
        case "TaskManager": 
          int m;
          cin >> m;

          vector<vector<int>> tasks(m, vector<int>(3));
          for (int i = 0; i < m; i ++)
            cin >> tasks[i][0] >> tasks[i][1] >> tasks[i][2];

          tm = TaskManager(tasks);
          break;
        case "add":
          vector<int> task(3);
          cin >> task[0] >> task[1] >> task[2];

          tm.add(task[0], task[1], task[2]);
          break;
        case "edit";
          int task_id, new_priority;
          cin >> task_id >> new_priority;

          tm.edit(task_id, new_priority);
          break;
        case "execTop":
          cout << tm.execTop() << endl;
          break;
        case "rmv";
          int task_id;
          cin >> task_id;

          tm.rmv(task_id);
          break;
        default:
          break;
      }
    } 
  }

  return 0;
}
