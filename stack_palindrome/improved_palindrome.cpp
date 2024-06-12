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
  string s = "aabbaa";
  int len = s.length();
  /*
  len%2
  even 0
  odd 1
   */

  for (int i = 0; i < len/2; i++){//* t:n/2
    s1.push(s[i]);//* s:n/2
  }
  bool is_palindrome = true;
  for (int i = 0; i < len / 2; i++){//* t:n/2
    int di = i + len / 2 + (len&1);
    int temp = s1.pop();
    if (temp != s[di]){ is_palindrome = false; break;}
  }
  // cout << c << endl;
  if (is_palindrome){
    cout << "it is palindrome";
  }
  else{
    cout << "it is not a palindrome";
  }
  return 0;
  //* ttl t:n => n
  //* ttl s:n/2 => n
}