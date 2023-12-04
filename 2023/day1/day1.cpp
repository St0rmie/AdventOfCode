#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool lookfortextnumber(string line, int i){
    vector<string> numbers{"one","two","three","four","five","six","seven","eight","nine"};

    for(int i=0; i<numbers.size(); i++){
        bool match = true;
        for(int j=0; j<numbers[i].length(); j++){
            if()
        }
    }

}


int main(){
    long int total = 0;
    string line;
    while(getline(cin, line)){

        vector<std::string> v;
        string value;

        for(int i=0; i<line.length(); i++){
            string digit;

            if(line[i]<='9' && line[i]>='0'){
                digit += line[i];
                v.push_back(digit);
            } else if(){

            }
        }
        
        value += v.front();
        value += v.back();
        total += stoi(value);
    }
    cout << "Total: " << total << "\n";
}