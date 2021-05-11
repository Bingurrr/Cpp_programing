#include <iostream>
#include "Kvector.h"
using namespace std;

Kvector::Kvector(int sz, int value):len(sz){
  cout << this << " : Kvector(" << sz << ','<< value << ")\n";
  if(!sz){m = NULL; return;}
  m = new int[sz];
  for(int i = 0; i < sz; i++){
    m[i] = value;
  }
}
Kvector::Kvector(const Kvector& a){
  cout << this << " : Kvector(*" << &a << ")\n";
  len = a.len;
  if(!len){m = NULL; return;}
  m = new int[len];
  for(int i = 0; i < len; i ++){
    m[i] = a.m[i];
  }
}
Kvector::~Kvector(){
  cout << this << " : ~Kvector() \n";
  delete[] m;
}
Kvector& Kvector::operator=(const Kvector& r){
  cout << "Kvector::operator= " << &r << endl;
  if(this == &r){
    return *this;
  }
  delete[] m;
  len = r.len;
  m = new int[len];
  for(int i = 0; i < len; i ++){
    m[i] = r.m[i];
  }
  return *this;
}
bool operator==(const Kvector& l, const Kvector& r){
  if(l.len != r.len) return false;
  for(int i = 0; i <l.len; i++){
    if(l.m[i] != r.m[i]){
      return false;
    }
  }
  return true;
}
bool operator!=(const Kvector& l, const Kvector& r){
  return !(l==r);
}
std::ostream& operator<<(std::ostream& os, const Kvector& r){
  for(int i = 0; i < r.len; i ++){
    os << r.m[i] << " ";
  }
  return os;
}
