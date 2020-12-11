#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

bool triTest(double x){
	double ans;
	ans = sqrt((8.0*x)+1.0)-1.0;
	ans = ans / 2.0;
	if(ans == floor(ans))
		return true;
	return false;
}


int main(){
	int triangles = 0;
	ifstream infile("words.txt");
	while(infile){
		string s;
		if(!getline(infile,s)) break;
		istringstream ss(s);
		while(ss){
			string s;
			if(!getline(ss,s,',')) break;
			int score = 0;
			for(int i=1;i<s.length()-1;i++){
				score = score + (s[i] - 64);
			}
			if(triTest((double)score))
				triangles++;
		}
	}
	cout<<triangles<<endl;
	return 0;
}