int numOfStudents(vector<int> A,int givenCountOfStudents,long allocatedRange){
    int students = 1;
    long required_Range_For_student = 0;
    
    for(int i=0;i<A.size();i++)
    {
        required_Range_For_a_student += A[i];
        
        if(required_Range_For_a_student > allocatedRange)
        {
            students++;
            required_Range_For_a_student = A[i];        // new range for next Student
        }
    }
    return students;
}
int Solution::books(vector<int> &A, int givenStudents) 
{
    if(A.size() < givenStudents) return -1;
 
    long sum = 0;
    for(int i=0;i<A.size();i++){
         sum+=A[i];
    }
    long minRange = (long)*max_element(A.begin(),A.end());
    long maxRange = sum;
    
    while(minRange < maxRange){
        
          long allocatedRange = (minRange + maxRange)/2;
          
          int requiredStudents = numOfStudents(A,givenStudents,allocatedRange);
          
          if(requiredStudents <= givenStudents){
               maxRange = allocatedRange;         // could be answer
          }
          else {
               minRange = allocatedRange+1;
          }
    }
    return (int)minRange;
}
