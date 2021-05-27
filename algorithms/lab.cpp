#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
#include "team.h"
using namespace std;

template <class T>
void print_container(const T& container, string s=""){
  cout << s << "(" << container.size() << ")";
  auto it = container.begin();
  for(; it != container.end(); it++) cout << *it << " ";
  cout << endl;
}
bool teamCmp_byName (const Team& a, const Team& b){return a.name < b.name;}
struct TeamCmp_byVictory{
  bool operator()(const Team& a, const Team& b) {return a.wins < b.wins;}
};

int main(){
  Team t[] = {Team("Bulls", 7), Team("Warriors", 5), Team("Spurs",2)};

  vector<Team> v(&t[0], &t[3]);
  print_container(v, "1. v= ");
  sort(v.begin(), v.end(), teamCmp_byName);
  print_container(v, "2. v= ");
  sort(v.begin(), v.end(), TeamCmp_byVictory());
  print_container(v, "3. v= ");
  v.insert(v.begin(), Team("Lakers",3));
  print_container(v, "4. v= ");

  set<Team,TeamCmp_byVictory> s(t, t+3);
  print_container(s, "1. s= ");
  s.insert(Team("Lakers",3));
  print_container(s, "2. s= ");

  priority_queue<Team, vector<Team>, TeamCmp_byVictory> p(t, t+3);
  // for(int i = 0; i < 3; i ++){
  //   p.push(t[i]);
  // }
  p.push(Team("Lakers",3));
  cout << "priotity queue= ";
  while(!p.empty()){
    cout << p.top() << " ";
    p.pop();
  }
  cout << endl;
  return 0;
}
