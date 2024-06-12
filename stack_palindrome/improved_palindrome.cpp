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
  string s = "aabba";
  int len = s.length();
  /*
  len%2
  even 0
  odd 1
   */

  bool is_palindrome = true;
  for (int i = 0; i < len / 2; i++){//* t:n/2
    int di = i + len / 2 + (len & 1);
    if (s[len/2-i-1] != s[di]){ is_palindrome = false; break; }
  }
  if (is_palindrome){
    cout << "it is palindrome";
  }
  else{
    cout << "it is not a palindrome";
  }
  return 0;
  //* ttl t:n/2 => n
  //* ttl s:1 => 1
}