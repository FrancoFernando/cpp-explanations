#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;
 
int main() {
 
  string s2{"Test compare ranges functions."};
  string s1{"Test compare Ranges functions."};
   
  cout << "equal: " << equal(s1.begin(), s1.end(), s2.begin()) << endl;

  cout << "lexi compare: " << lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end()) << endl;
   
  auto pair = mismatch(s1.begin(), s1.end(), s2.begin());

  if (pair.first != s1.end()){
    cout << "s1 and s2 are different at position " << distance(s1.begin(), pair.first) 
              << " with (" << *pair.first << ", " << *pair.second << ")" << endl;
  } 
}
