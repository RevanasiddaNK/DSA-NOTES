#include<bits/stdc++.h>

int largestarea(vector<int>arr, int n) {
  int maxArea = 0;
  for (int i = 0; i < n; i++) {
    int minHeight = INT_MAX;
    for (int j = i; j < n; j++) {
      minHeight = min(minHeight, arr[j]);
      maxArea = max(maxArea, minHeight * (j - i + 1));
    }
  }
  return maxArea;
}


int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	
	int maxArea = 0;
	vector<int>height(m,0);
	for(int i=0; i<n; i++){

		for(int j=0; j<m; j++){
			if(mat[i][j] == 1)
				height[j]++;
			else
				height[j] = 0;
		}

		int area = largestarea(height,m);
		maxArea = max(maxArea,area);
	}
	return maxArea;
}
