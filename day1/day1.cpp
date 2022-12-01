#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Elf{
    int elfN,elfC;
};

bool compareElvesCalories(Elf e1, Elf e2){
    return (e1.elfC > e2.elfC);
}

int main(){
    int currentElf=0,elfCaloriesTotal=0;
    string line;
    vector<Elf> vec;

    while(getline(cin, line)){
        if(line == ""){
            vec.push_back({currentElf,elfCaloriesTotal});
            currentElf++;
            elfCaloriesTotal=0;
        }else{
            elfCaloriesTotal += stoi(line);
        }
    }

    sort(vec.begin(),vec.end(),compareElvesCalories);

    std::cout << "PART1 // Elf n. " << vec[0].elfN << " has " << vec[0].elfC << " calories (max)." << endl;
    std::cout << "PART2 // Elfs n. " << vec[0].elfN << "," << vec[1].elfN << "," << vec[2].elfN << " have a total of " << vec[0].elfC+vec[1].elfC+vec[2].elfC << " calories." << endl;
}