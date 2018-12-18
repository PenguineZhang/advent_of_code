#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void strip(string src, string delimiter, vector<string>& output){
	
	output.push_back(src.substr(0, src.find(delimiter)));

}

int main(int argc, char** argv){
	if(argc != 2){
		cerr << "please provide input file" << endl;
		return -1;
	}

	ifstream f(argv[1], ios::in);
	string line;
	while(getline(f, line)){
		

	}
}