#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <ctime>

using namespace std;

int main(int argc, char** argv){
	if(argc != 2){
		cerr << "please provide input file" << endl;
	}
	
	string data;
	ifstream f;
	f.open(argv[1], ios::in);

	vector<float> data_float;

	float curr_val = 0;
	while(!f.eof()){
		f >> data;
		curr_val = stof(data);
		data_float.push_back(curr_val);
	}

	float sum_of_element = 0;

	map<float, int> freq;
	int flag = 0;
	int count = 0;
	clock_t start = clock();
	double duration;
	while(1){
		for(vector<float>::iterator it=data_float.begin(); it != data_float.end(); it++){
			sum_of_element += *it;

			if(freq.find(sum_of_element)->second == 1){
				// cout << sum_of_element << endl;
				flag = 1;
				break;
			}else{
				freq[sum_of_element] = 1;
				
			}
		}
		cout << count++ << endl;
		if(flag){
			break;
		}
	}
	duration = (clock() - start)/(double)CLOCKS_PER_SEC;

	cout << "duration: " << duration << endl;
	cout << "final frequency: " << sum_of_element << endl;
	f.close();
	return 0;
}