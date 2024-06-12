#include <iostream>
#include "ankush_stack.hpp"
using namespace std;

int main() {
  // palindrome
  Stack s1;
  string s = "abbadabba";

  for (int i = 0; i < s.length(); i++){
    s1.push(s[i]);
  }
  string t;
  for (int i = 0; i < s.length(); i++){
    int temp = s1.pop();
    int a = temp;
    t.push_back(a);
  }
  // cout << c << endl;
  if (s==t){
    cout << "it is palindrome";
  }
  else{
    cout << "it is not a palindrome";
  }
  return 0;
}