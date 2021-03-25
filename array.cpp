#include <iostream>
using namespace std;

int main(){

  int arr[3][4] = {{10,-1,3},{2,5,6}};
  int i,j;
  for(i = 0; i < 3; i++)
    for(j = 0; j < 4; j++){
      cout << "arr[" << i << "][" << j << "] value: " << arr[i][j];
      cout << " address: "<< &arr[i][j] << endl;
    }

  return 0;

}
