#include <iostream>
#include <cstring>
using namespace std;

class Kvector{
  int *m;
  int len;
public:
  static int total_len;
  Kvector(int sz = 0, int value = 0);
  Kvector(const Kvector& v);
  ~Kvector(){
    cout << this << " : ~Kvector() \n";
    delete[] m;
    total_len -= len;
  }
  Kvector& operator=(const Kvector& c);
  friend int operator==(const Kvector& c, const Kvector& d);
  friend int operator!=(const Kvector& c, const Kvector& d);
  int& operator[](int idx);
  friend ostream& operator<<(ostream& os, const Kvector& c);
  void print() const {
    for(int i = 0; i <len; i ++) cout << m[i] << " ";
    cout << endl;
  }
  void clear(){
    delete[] m;
    m = nullptr;
    len = 0;
  }
  int size(){ return len;}
};
int main(){
  Kvector v1(3); v1.print();
  Kvector v2(2,9); v2.print();
  Kvector v3(v2); v3.print();
  cout << (v1 == v2) << endl;
  cout << (v3 == v2) << endl;
  v3 = v2 = v1;
  cout << v1 << endl;
  cout << v2 << endl;
  cout << v3 << endl;
  cout << (v3 != v2) << endl;
  v1[2] = 2;
  v2[0] = v1[2];
  cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl;
  return 0;
}
Kvector::Kvector(int sz, int value){
  cout << this << " : Kvector(" << sz << ','<< value << ")\n";
  len = sz;
  total_len += len;
  if(sz==0){
    m = nullptr;
    return;
  }
  m = new int[sz];
  for(int i = 0; i < sz; i++){
    m[i] = value;
  }
}
Kvector::Kvector(const Kvector& a){
  cout << this << " : Kvector(*" << &a << ")\n";
  len = a.len;
  total_len += len;
  m = new int[len];
  for(int i = 0; i < len; i ++){
    m[i] = a.m[i];
  }
}
int Kvector::total_len = 0;

Kvector& Kvector::operator=(const Kvector& c){
  if(this == &c){
    return *this;
  }
  delete[] m;
  len = c.len;
  m = new int[len+1];
  for(int i = 0; i < len; i ++){
    m[i] = c.m[i];
  }
  return *this;
}
int operator==(const Kvector& c, const Kvector& d){
  return ((*c.m==*d.m )&&(c.len == d.len) ? 1 : 0);
}
int operator!=(const Kvector& c, const Kvector& d){
  return (!(c==d) ? 1 : 0);
}
int& Kvector::operator[](int idx) {
  return m[idx];
}
std::ostream& operator<<(std::ostream& os, const Kvector& c){
  for(int i = 0; i < c.len; i ++){
    os << c.m[i] << " ";
  }
  return os;
}
