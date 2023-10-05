
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};




class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {

       
       
        int curr_petrol = 0;
        int start = 0;
        
      //we traverse the given array and find out if the current petrol left
      //is less than 0, if yes then it means that current fuel left is 
      //insufficient and hence we need to select some start position after it
        
        for(int i=0;i<n;i++){
            // negative fuel
            if(curr_petrol < 0){
                curr_petrol = 0;
                start = i;
            }
            
            //petrol add krte jayenge har step ka
            curr_petrol += p[i].petrol - p[i].distance;
        }
        
        //as it is a circular path and we have to 
        //come back to starting position hence we traverse from 
        //0 to start and add them to currFuel and check previous condion
        
        for(int i =0;i<n;i++){
            if(curr_petrol < 0){
                return -1;
            }
            
            curr_petrol += p[i].petrol - p[i].distance;
        }
        
         //if after completing one round it is left with negative fuel 
         //then we return -1 as no start position possible
          
        if(curr_petrol < 0){
            return -1;
        }
        return start;
        
    }
};






int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

