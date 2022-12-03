#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define LOSS 0
#define DRAW 3
#define WIN 6
#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int readMove(char move){
    if(move == 'A' || move == 'X')
        return ROCK;
    if(move == 'B' || move == 'Y')
        return PAPER;
    else
        return SCISSORS;
}

int calculatePoints(int opMove, int myMove){
    if(myMove == opMove)
        return DRAW + myMove;
    if((myMove == ROCK && opMove == PAPER) || 
        (myMove == PAPER && opMove == SCISSORS) || 
        (myMove == SCISSORS && opMove == ROCK))
        return LOSS + myMove;
    else
        return WIN + myMove;
}

int main(){
    int sumPoints = 0;
    string line;

    while(getline(cin, line)){
        sumPoints += calculatePoints(readMove(line[0]),readMove(line[2]));
    }

    std::cout << "PART1 // My points: " << sumPoints << endl;
}