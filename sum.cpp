#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int init_array(int a[], int n);
int sum_array1(int* a, int n);
void sum_array2(int* a, int n, int *p);
void sum_array3(int* a, int n, int &r);
int main(int argc, char *argv[]) {
  if (argc < 2) { cout << "one command line argument needed\n"; return -1; }

  int n = atoi(argv[1]);
  n = (n < 1) ? 1 : n;
  n = (n > 10) ? 10 : n;

  int* a = new int[n];
  if (!a) { cout << "allocation failed."<< endl; return -1;}
  int s;

  init_array(a, n);
  for (int i = 0; i < n; i++) cout << a[i] << " ";

  s = sum_array1(a, n);
  cout << endl << s << endl;

  sum_array2(a, n, &s);
  cout << s << endl;

  sum_array3(a, n, s);
  cout << s << endl;

  return 0;
}
int init_array(int a[], int n) {
    time_t t = time(NULL);
    srand(t);
    for (int i = 0; i < n; i++) {
        a[i] = rand()/10;
    }
    return *a;
}
int sum_array1(int* a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *a++;
    }
    return sum;
}
void sum_array2(int* a, int n, int* p){
    *p = 0;
    for (int i = 0; i < n; i++) {
        *p += *a++;
    }
}
void sum_array3(int* a, int n, int &r) {
    r = 0;
    for (int i = 0; i < n; i++) {
        r += *a++;
    }
}
