#include <bits/stdc++.h> 
#include<vector>
void solveRec(int index,string &str,string &s,vector<string>&ans){
	// Base Case
	if(index >= str.size()){
		if(s != ""){
		ans.push_back(s);
		}
		return;
	}

	s.push_back(str[index]);
	solveRec(index+1,str,s,ans);
	s.pop_back();

	solveRec(index+1,str,s,ans);
}

vector<string> subsequences(string str){
	vector<string>ans;
	string s = "";
	int index = 0;
	solveRec(index,str,s,ans);
	return ans;
}
