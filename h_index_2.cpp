#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   int hIndex(vector<int>& A) {
      
      int low = 0;
      int n = A.size();
      int high = n - 1;

      if (A.size() == 0) 
         return 0;
      
      while (low <= high) {
         int mid = low + (high - low) / 2;
         if (A[mid] == n - mid) {
            return A[mid];
         }
         else if (A[mid] > (n - mid)) {
            high = mid - 1;
         } else 
            low = mid + 1;
      }
      return n - (high + 1);
   }
};
main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
   freopen("Input.txt", "r", stdin);
// for writing output to output1.txt
   freopen("Output.txt", "w", stdout);
#endif

   int N;
   cin >> N;

   int input;
   vector<int> v;

   while (cin >> input)
      v.push_back(input);

   Solution ob;
   cout << (ob.hIndex(v));
}