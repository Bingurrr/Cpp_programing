#include <iostream>
#include "BitSet.h"
using namespace std;

BitSet::BitSet(int sz): Bvector(sz){}

void BitSet::insert(int v) {set(v);}
BitSet operator+(const BitSet& v1, const BitSet& v2)
{

  if(v1.NBITS != v2.NBITS)
    throw IncompatibleException(v1.NBITS, v2.NBITS);

  BitSet ret(v1.NBITS);
  for(int i = 0; i < ret.NBITS; i ++){
    //bit연산자로 구현
    ret.u_m[i] = v1.u_m[i] | v2.u_m[i];

  }
  return ret;
}
std::ostream& operator<<(std::ostream& os, const BitSet& s)
{
  os << "{ ";
  for(int i = 0; i <s.NBITS; i++){
    if(s[i]) os << i << " ";
  }
  os << "}";
  return os;
}

int main(int argc, char *argv[]){
  try{
  BitSet b1(132), b2(131);
  b1.insert(3); b1.insert(5); b1.insert(8);
  b2.insert(4); b2.insert(5); b2.insert(8); b2.insert(130);
  b1.print(); b2.print();
  cout << "b1= " << b1 << endl;
  cout << "b2= " << b2 << endl;
  cout << "b1+b2= " << b1+b2 << endl;
}
  catch(IncompatibleException& e){
    cout << "In + operation, the operands are not compatible.\n";
    cout << "The size of the first BitSet is " << e.v1 << endl;
    cout << "The size of the second BitSet is " << e.v2 << endl;
  }

  return 0;
}
