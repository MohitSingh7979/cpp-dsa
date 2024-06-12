#include<iostream>
using namespace std;
/*
t-> time
s-> space
ttl-> total
bst-> best
wrst-> worst
 */
 // palindrome
#include "ankush_stack.hpp"
int main(){
  Stack st;
  string s = "racecar";

  for (int i = 0; i < s.length(); i++){//* t:n
    st.push(s[i]);//* s:n
  };

  //! bool is_palindrome = true;
  for (int i = 0; i < s.length(); i++){//* t:n
    if (!(st.pop() == s[i])/* (st.pop() != s[i]) */){//* bst t:1 //* wrst t:n
      //! is_palindrome = false;
      //! break;
      cout << "not palindrome";
      return 1;//! not recommended
    };
  }
  //! output should be nearby
  cout << "it is palindrome";
  return 0;
  //* ttl t:2n => n
  //* ttl s:n
}
