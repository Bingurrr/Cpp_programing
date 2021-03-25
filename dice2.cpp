#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char*argv[]){

  if(argc != 2){
    cout << "usage: ./dice n" << endl;
    return -1;
}
  int n = atoi(argv[1]);
  srand(n);
  for(int i = 0; i <10; i ++){
    cout << rand()%6+1 << " ";
  }
  cout << endl;

  return 0;
}
