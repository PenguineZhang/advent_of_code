#include <iostream>
#include <fstream>
#include <tuple>
#include <map>
#include <Eigen/Dense>
#include <vector>
#include <string>

using namespace std;
using namespace Eigen;

void string_parser(string src, int &x, int &y, int &width, int &height){

	string at_delimiter = "@ ";
	string comma_delimiter = ",";
	string colon_delimiter = ": ";
	char x_delimiter = 'x';

	size_t at_delimiter_pos = src.find(at_delimiter);
	size_t comma_delimiter_pos = src.find(comma_delimiter);
	size_t colon_delimiter_pos = src.find(colon_delimiter);
	size_t x_delimiter_pos = src.find(x_delimiter);

	x = stoi(src.substr(at_delimiter_pos+2, comma_delimiter_pos-1));
	y = stoi(src.substr(comma_delimiter_pos+1, colon_delimiter_pos-1));
	width = stoi(src.substr(colon_delimiter_pos+2, x_delimiter_pos-1));
	height = stoi(src.substr(x_delimiter_pos+1, src.length()-1));

	// cout << x << ", " << y << ", " << width << ", " << height << endl;

	// left = src.substr(0, delimiter_pos);
	// right = src.substr(delimiter_pos+delimiter_length, src.length());
}


int main(int argc, char** argv){
	if(argc != 2){
		cerr << "please provide input file" << endl;
		return -1;
	}

	ifstream f;
	string data;
	vector<string> size_data;

	int row_size = 1000;
	int col_size = 1000;

	MatrixXf quilt = MatrixXf::Zero(col_size, row_size);

	int row, col, width, height; 

	f.open(argv[1], ios::in);
	while(getline(f, data)){
		size_data.push_back(data);
		string_parser(data, row, col, width, height);
		for(int i = row; i < row+width; i++){
			for(int j = col; j < col+height; j++){
				quilt(i,j) += 1;
			}
		}
	}
	f.close();





	// part 1
	// int count = 0;
	// for(int i = 0; i < row_size; i++){
	// 	for(int j = 0; j < col_size; j++){
	// 		if(quilt(i,j) > 1){
	// 			count++;
	// 		}
	// 	}
	// }
	// cout << count << endl;





	// part 2
	vector<string>::iterator it;
	bool intact;
	string target;
	int i,j;

	for (it = size_data.begin(); it != size_data.end(); it++){
		string_parser(*it, row, col, width, height);
		intact = true;
		for(i = row; i < row+width; i++){
			for(j = col; j < col+height; j++){
				if(quilt(i,j) > 1){
					intact = false;
					break;
				}
			}

			if(intact == false){
				break;
			}
		}
		if(intact == true){
			target = *it;
		}
	}

	string id = target.substr(1, target.find(" @ ")-1);
	cout << id << endl;	


	return 0;
}