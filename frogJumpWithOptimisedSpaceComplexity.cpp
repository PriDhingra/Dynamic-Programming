#include<bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
	
	int prev2 = 0;
	int prev = 0;
	
	for(int i = 1;i < n;i++) {
		int first = prev + abs(heights[i] - heights[i - 1]);
		
		int second = INT_MAX;
		if(i > 1)
			second = prev2 + abs(heights[i] - heights[i - 2]);
		
		int curr = min(first, second);
		prev2 = prev;
		prev = curr;
	}
	
	return prev;
}
