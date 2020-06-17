#include <iostream>
#include<limits.h>
#define ll long long
using namespace std;
int numOFStudents(ll a[],ll n,ll m,ll maxRange) { 
      int students = 1;
      ll sum = 0;
      
      for(int i=0;i<n;i++){
          sum+=a[i];
          if(sum > maxRange){
              students++;
              sum = a[i];
          }
      }
 return students;
}
ll binarySearch(ll a[],ll n,ll sum,ll max,int givenCountOFStudents){
          if(n<givenCountOFStudents){ return -1; }
          
          ll start = max;
          ll end = sum;
          
          while(start < end)
          {
               ll maxRange = (start+end)/2;
               
               int studentCount = numOFStudents(a,n,givenCountOFStudents,maxRange);
               
               if(studentCount <= givenCountOFStudents){
                   end = maxRange;
               }
               else{
                   start = maxRange + 1;
               }
          }
    return start;      
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    ll a[n];
	    ll max = INT_MIN;
	    ll sum = 0;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        
	        sum += a[i];  // maxRange for BinarySearch
	        
	        if(a[i]>max)
	        {
	            max = a[i];    //MinRange forBinarySearch
	        }
	    }
	    ll students;
	    cin>>students;
	    
	    cout<<binarySearch(a,n,sum,max,students)<<"\n";
	}
	return 0;
}
