#include <iostream> 
using namespace std;
int arr[100][100];

int knapsack(int wt[], int val[], int wob, int n) { 
    if(n == 0 || wob == 0) { 
        return 0; 
    } 
    
    if(arr[n][wob] == 0) {
        return arr[n][wob];
    }
    
    if (wt[n-1] < wob) { 
        return arr[n][wob] = max((val[n-1] + knapsack(wt, val, wob-wt[n-1], n-1)), knapsack(wt, val, wob, n-1)); 
        
    } else if (wt[n-1] > wob) { 
        return arr[n][wob] = knapsack(wt, val, wob, n-1); 
    } 
} 

int main() { 
    for(int i = 0;i < 100;i++) {
        for(int j = 0;j < 100;j++) {
            arr[i][j] = -1;
        }
    }
    
    int n = 3; 
    
    int wt[3] = {6,12,4}; 
    int val[3] = {6,8,10}; 
    
    int weightOfBag = 10; 
    
    int result; 
    
    result = knapsack(wt, val, weightOfBag, n); 
    
    cout<<"Total Possible profit earned can be: "<<result;
    
    return 0; 
}