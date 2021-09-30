/*
The brute force method is to run three loops and keep track of the number of triangles possible so far. 
The three loops select three different values from an array. The innermost loop checks for the triangle 
property which specifies the sum of any two sides must 
be greater than the value of the third side).

for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
 
            // The innermost loop checks for
            // the triangle property
            for (int k = j + 1; k < n; k++)
 
                // Sum of two sides is greater
                // than the third
                if (
                    arr[i] + arr[j] > arr[k]
                    && arr[i] + arr[k] > arr[j]
                    && arr[k] + arr[j] > arr[i])
                    count++;
        }
    }
    
2 pointer method:

Algorithm:

Sort the array and then take three variables l, r and i, pointing to start, end-1 and array element starting from end 
of the array.

Traverse the array from end (n-1 to 1), and for each iteration keep the value of l = 0 and r = i-1

Now if a triangle can be formed using arr[l] and arr[r] then triangles can obviously formed 
from a[l+1], a[l+2]…..a[r-1], arr[r] and a[i], because the array is sorted , which can be directly 
calculated using (r-l). and then decrement the value of r and continue the loop till l is less than r

If a triangle cannot be formed using arr[l] and arr[r] then increment the value of l and continue the loop till l is less than r 
 
So the overall complexity of iterating 

Time complexity: O(n^2). 
As two nested loops are used, but overall iterations in comparison to the above method reduces greatly.
Space Complexity: O(1). 
*/

#include <bits/stdc++.h>
using namespace std;
 
void CountTriangles(vector<int> A)
{
 
    int n = A.size();
 
    sort(A.begin(), A.end());
 
    int count = 0;
 
    for (int i = n - 1; i >= 1; i--) {
        int l = 0, r = i - 1;
        while (l < r) {
            if (A[l] + A[r] > A[i]) {
 
                // If it is possible with a[l], a[r]
                // and a[i] then it is also possible
                // with a[l+1]..a[r-1], a[r] and a[i]
                count += r - l;
 
                // checking for more possible solutions
                r--;
            }
            else
 
                // if not possible check for
                // higher values of arr[l]
                l++;
        }
    }
    cout << "No of possible solutions: " << count;
}
int main()
{
 
    vector<int> A = { 4, 3, 5, 7, 6 };
 
    CountTriangles(A);
}
