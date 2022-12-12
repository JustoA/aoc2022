#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

std::vector<std::string> barseInput(std::string filename){
    std::ifstream input(filename); // class constructor or smth idk c++ rlly well
    // read them bad bois into a string
    std::vector<std::string> rawIn;
    std::string line;

    while (input){ 
    std::getline(input, line);
    rawIn.push_back(line);
    }
    rawIn.pop_back(); //lole
    return rawIn;
}
// 1 beats 3
// 2 beats 1
// 3 beats 2
// AX1
// BY2
// CZ3
int part1(std::vector<std::string> input){
    std::map<char, int> game;

    game['A'] = 1;
    game['X'] = 1;
    game['B'] = 2;
    game['Y'] = 2;
    game['C'] = 3;
    game['Z'] = 3;

    int totalScore = 0;
    for(int i=0;i < input.size(); i++){
        std::string current_round = input[i];
        
        int opponent = game[current_round[0]];
        int me = game[current_round[2]];
        // std::cout << opponent << " vs " << me << std::endl;
        if (opponent == me) totalScore+=3; //tie 
        else if (me - opponent == 1 || me - opponent == -2) totalScore+=6; //win
        totalScore+=me; // bonus for playing shape

    }
    return totalScore;
}

// 1 beats 3 : -2
// 2 beats 1 : 1
// 3 beats 2 : 1

int part2(std::vector<std::string> input){
    std::map<char, int> game;
    std::map<int, int> outcomeToPoints;
    game['A'] = 1;
    game['B'] = 2;
    game['C'] = 3;
    game['X'] = -1;
    game['Y'] = 0;
    game['Z'] = 1;

    outcomeToPoints[-1] = 0;
    outcomeToPoints[0] = 3;
    outcomeToPoints[1] = 6;

    int totalScore = 0;
    for(int i=0;i < input.size(); i++){
        std::string current_round = input[i];
        
        int opponent = game[current_round[0]];
        int outcome = game[current_round[2]];
        
        int me = (opponent + outcome) % 3;
        if (me < 1) me+=3;
        
        totalScore+=me;
        totalScore+=outcomeToPoints[outcome]; // bonus for outcome

    }
    return totalScore;
}


int main(){
    std::vector<std::string> input = barseInput("input.txt");
    
    //std::cout << -2%3 << std::endl;
    std::cout << "Part 1: " << part1(input) << std::endl;
    std::cout << "Part 2: " << part2(input) << std::endl;

    return 0;
}