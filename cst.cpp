#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define TARGET 'e'

int main(int argc, char *argv[]){
  if(argc < 2) { cout<<"one command line argument needed\n"; return -1;}
  int n = strlen(argv[1]);
  char *a = new char[n*2+3];
  if(!a){cout << "allocation failed.\n"; return -1;}
  a[0] = '!';
  char *r = argv[1];
  int i;
  for(i = 1; *r != '\0'; i++, r++){
    a[i] = *r;
    if(*r == 'e'){
      i++;
      a[i] = 'e';
    }
}
  a[i] = '.';
  cout << a << endl;


  string s = "!";
  s += argv[1];
  s += ".";
  int pos = 0;
  pos = s.find('e',pos);
  while(pos != string::npos){
    s.insert(pos,"e");
    pos+=2;
    pos = s.find('e',pos);
  }
  cout << s << endl;

  return 0;
}
