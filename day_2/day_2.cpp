#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <functional>

using namespace std;

int find_2(map<char, int> id_counts){
	map<char, int>::reverse_iterator rit;
	for(rit = id_counts.rbegin(); rit != id_counts.rend(); rit++){
		if(rit->second == 2){
			cout << "found_2: " << rit->first << endl;
			return 1;
		}
	}
	return 0;
}

int find_3(map<char, int> id_counts){
	map<char, int>::reverse_iterator rit;
	for(rit = id_counts.rbegin(); rit != id_counts.rend(); rit++){
		if(rit->second == 3){
			cout << "found_3: " << rit->first << endl;
			return 1;
		}
	}
	return 0;
}


int find_diff(string str_1, string str_2){
	int diff_count = 0;
	int diff_pos = 0;
	for(int i = 0; i < str_1.length(); i++){
		if(str_1[i] != str_2[i]){
			diff_count++;
			diff_pos = i;
			if(diff_count > 1){
				return 0;
			}
		}
	}
	return diff_pos;
	
}

int main(int argc, char** argv){
	if(argc != 2){
		cerr << "please provide input file" << endl;
		return -1;
	}

	string data;
	ifstream f;

	vector<string> string_data;

	f.open(argv[1], ios::in);
	while(!f.eof()){
		f >> data;
		string_data.push_back(data);
	}
	f.close();
	vector<string>::iterator it;
	vector<string>::iterator it_2;

	int twos = 0;
	int threes = 0;

	int found_2 = 0;
	int found_3 = 0;

	map<char, int> id_counts;
	string str_1;
	string str_2;

	// day 2 - part 1
	/*
	for(it = string_data.begin(); it != string_data.end(); it++){
		id_counts.clear();
		curr_str = *it;
		for (int i = 0; i < curr_str.length(); i++){
			if(id_counts.count(curr_str[i])>0){
				id_counts[curr_str[i]] += 1;

			}else{
				id_counts[curr_str[i]] = 1;
			}
			
		}

		twos += find_2(id_counts);
		threes += find_3(id_counts);
	}
	cout << twos*threes << endl;
	*/

	// day 2 - part 2

	string common_string;
	int diff_pos;
	for(it = string_data.begin(); it != string_data.end()-1; it++){
		for(it_2 = string_data.begin()+1; it_2 != string_data.end(); it_2++){
			diff_pos = find_diff(*it, *it_2);
			if(diff_pos != 0){
				common_string = *it;
				common_string.erase(diff_pos, 1);
			}
		}
	}

	cout << common_string << endl;

	return 0;
}