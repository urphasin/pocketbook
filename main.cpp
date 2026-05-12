#include <bits/stdc++.h>
#include <iomanip>
int main() {
 
  float ans = 150.69 * 0;
  std::cout 
    << std::fixed 
    << std::setprecision(6) 
    << "\x1b[1;93m" 
    << ans 
    << std::defaultfloat 
    << "\x1b[0m\n";


  std::vector<int> arr{1, 2, 3, 4, 5};

  int left = 0;
  int right = arr.size() - 1;

  while(left < right) {
    std::swap(arr[left], arr[right]);
    left++;
    right--;
  }





  return 0;
}