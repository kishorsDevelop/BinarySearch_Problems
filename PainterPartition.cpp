int numPainters(vector<int> &C,long maxLen){
      int num = 1;
      long total = 0;
      
      for(int i=0;i<C.size();i++){
          total += C[i];
          
          if(total > maxLen){
              total = C[i];
              num++;
          }
      }
      return num;
}

int Solution::paint(int painters, int Time, vector<int> &C) {

    long sum = 0;
    for(int i=0;i<C.size();i++){
        sum += C[i];
    }
 
    long maxRange = sum;
    long minRange = (long)(*max_element(C.begin(),C.end()));
    
    while(minRange < maxRange){
         long maxLen = (minRange+maxRange)/2;
         int requiredPainters = numPainters(C,maxLen);
         
         if(requiredPainters <= painters){
             maxRange = maxLen;
         }
         else{
             minRange = maxLen+1;
         }
    }
    
    return (int)((minRange*Time)%10000003);
}
