#include <iostream>
#include "ankush_stack.hpp"
using namespace std;
/*
t-> time
s-> space
ttl-> total
bst-> best
wrst-> worst
 */
int main() {
  // palindrome
  Stack s1;
  string s = "abbadabba";

  for (int i = 0; i < s.length(); i++){//* t:n
    s1.push(s[i]);//* s:n
  }
  string t;
  for (int i = 0; i < s.length(); i++){//* t:n
    int temp = s1.pop();
    t.push_back(temp);//* s:n
  }
  // cout << c << endl;
  if (s == t){  //* t:n
    cout << "it is palindrome";
  }
  else{
    cout << "it is not a palindrome";
  }
  return 0;
  //* ttl t:3n => n
  //* ttl s:n => n
}