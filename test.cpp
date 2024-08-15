#include <iostream>
using namespace std;
int main() {
  // Write your code here
  int e = 4, f = 4;
  int opera[] = {+, -, /, *};
  for (int i = 0; i < 4; i++) {
    cout << e << opera[i] << f << endl;
  }
}
