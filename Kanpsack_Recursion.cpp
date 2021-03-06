#include <iostream> 
using namespace std; 

int knapsack(int wt[], int val[], int wob, int n) { 
    if(n == 0 || wob == 0) { 
        return 0; 
    } 
    
    if (wt[n-1] < wob) { 
        return max((val[n-1] + knapsack(wt, val, wob-wt[n-1], n-1)), knapsack(wt, val, wob, n-1)); 
        
    } else if (wt[n-1] > wob) { 
        return knapsack(wt, val, wob, n-1); 
        
    } 
} 

int main() { 
    int n = 2; 
    
    int wt[2] = {6,12}; 
    int val[2] = {6,8}; 
    
    int weightOfBag = 10; 
    
    int result; 
    
    result = knapsack(wt, val, weightOfBag, n); 
    
   cout<<"Total Possible profit earned can be: "<<result;
    
    return 0; 
}
