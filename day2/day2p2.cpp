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

/** Converts a char into it's meaning */
int readMove(char move){
    if(move == 'A') return ROCK;
    if(move == 'B') return PAPER;
    if(move == 'C') return SCISSORS;
    if(move == 'X') return LOSS;
    if(move == 'Y') return DRAW;
    else return WIN;
}

/** Calculates the move that wins*/
int winMove(int move){
    if(move == ROCK)
        return PAPER;
    if(move == PAPER)
        return SCISSORS;
    else
        return ROCK;
}

/** Calculates the move that loses*/
int loseMove(int move){
    if(move == ROCK)
        return SCISSORS;
    if(move == PAPER)
        return ROCK;
    else
        return PAPER;
}

/** Calculate the points obtained on each round*/
int calculatePoints(int opMove, int result){
    if(result == DRAW)
        return DRAW + opMove;
    if(result == WIN)
        return WIN + winMove(opMove);
    else
        return LOSS + loseMove(opMove);
}

int main(){
    int sumPoints = 0;
    string line;

    while(getline(cin, line)){
        sumPoints += calculatePoints(readMove(line[0]),readMove(line[2]));
    }

    std::cout << "PART2 // My points: " << sumPoints << endl;
}