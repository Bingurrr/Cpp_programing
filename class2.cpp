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
  const Kvector v2(2,9); v2.print();
  Kvector v3(v2); v3.print();

  cout << "total length= " << Kvector::total_len << endl;
  v2.print();
  v3.print();
  cout << "total length= " << Kvector::total_len << endl;
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
