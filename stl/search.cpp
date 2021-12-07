#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

bool isVowel(char c) {
  set<char> vowels{'a','e','i','o','u'};
  return (vowels.find(c) != vowels.end());
}

int main() {
  string r1{"abcdefghiijklmn"};  // range 1
  string r2{"def"};              // range 2

  cout << *find(r1.begin(), r1.end(), 'h') << endl;             // h
  cout << *find_if(r1.begin(), r1.end(), isVowel) << endl;      // a
  cout << *find_if_not(r1.begin(), r1.end(), isVowel) << endl;  // b
  
  auto it = find_first_of(r1.begin(), r1.end(), r2.begin(), r2.end());
  if (it != r1.end()) cout << *it << endl; // d

  auto it2 = adjacent_find(r1.begin(), r1.end());
  if (it2 != r1.end()) cout << *it2;       // i
}