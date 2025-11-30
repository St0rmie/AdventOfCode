#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> numbers{"one", "two",   "three", "four", "five",
                       "six", "seven", "eight", "nine"};

string lookfortextnumber(string line, int a) {
	for (int i = 0; i < numbers.size(); i++) {
		int match = i;

		for (int j = 0; j < numbers[i].length(); j++) {
			if ((j + a) > line.length() || line[a + j] != numbers[i][j]) {
				match = -1;
				break;
			}
		}

		if (match != -1) {
			string num;
			num += (match + 1);
			std::cout << num << endl;
			return num;
		}
	}
	return "";
}

int main() {
	long int total = 0;
	string line;
	while (getline(cin, line)) {
		vector<std::string> v;
		string value;

		for (int i = 0; i < line.length(); i++) {
			string digit;

			if (line[i] <= '9' && line[i] >= '0') {
				digit = line[i];
				v.push_back(digit);
			} else if ((digit = lookfortextnumber(line, i)) != "") {
				v.push_back(digit);
			}
		}

		value += v.front();
		value += v.back();
		std::cout << "Value " << value << "length " << value.length() << endl;
		total += stoi(value);
	}
	cout << "Total: " << total << "\n";
}