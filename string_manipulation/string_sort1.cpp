//Baekjoon 1431

//shorter one first
//if same length sum of each digit is compared (only numbers)
//if not sorted then compare in dictionary order


#include <iostream>
#include <algorithm>

 using namespace std;

 string arr[20000];
 int n;

 int getSum(string str)
 {
     int length = str.length(), sum = 0;
     for(int i=0; i<length; i++)
     {
         //sum only if numbers
         if(str[i] - '0' <= 9 && str[i]-'0' >=0)
         {
             sum += str[i]-'0';
         }
     }
     return sum;
 }

 bool compare(string a, string b)
 {
     if(a.length() < b.length())
     {
         return true;
     }
     else if(a.length() > b.length())
     {
         return false;
     }
     else
     {
         int a_sum = getSum(a);
         int b_sum = getSum(b);
         if(a_sum != b_sum)
         {
             return a_sum < b_sum;
         }
         else
         {
             return a < b;
         }
     }
 }

 int main(void)
 {
     cin >> n;
     for(int i=0; i<n; i++)
     {
         cin >> arr[i];
     }

     sort(arr, arr+n, compare);

     for(int i=0; i<n; i++)
     {
         cout << arr[i] << '\n';
     }
     return 0;
 }
