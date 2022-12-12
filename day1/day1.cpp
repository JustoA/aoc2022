// abandon hope, all ye who enter here.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
int maxCalories(std::vector<std::string> vec){
    int max = 0;
    int cursum = 0;
    for(int i=0; i < vec.size(); i++){
        // std::cout << vec[i] << std::endl;
        if(vec[i].compare("")){
            cursum+= stoi(vec[i]);
        }
        else{
            max = cursum > max ? cursum : max; // I are cool and use ternary operashun 
            cursum = 0;
        }
    }
    return max;
}

int topThreeCalories(std::vector<std::string> vec){
    std::vector<int> topThree = {0,0,0};
    int cursum = 0;
    for(int i=0; i < vec.size(); i++){
        // std::cout << vec[i] << std::endl;
        if(vec[i].compare("")){
            cursum+= stoi(vec[i]);
            continue;
        }
        for (int j=0; j < 3; j++){
            if (topThree[j] < cursum){
                topThree[j] = cursum;
                break;
            }
        }
        sort(topThree.begin(), topThree.end());
        cursum = 0;
    }
    return topThree[0] + topThree[1] + topThree[2];
}

int main(){
    std::ifstream input("input.txt"); // class constructor or smth idk c++ rlly well
    // read them bad bois into a string
    std::vector<std::string> rawIn;
    std::string line;

    while (input){ 
        std::getline(input, line);
        rawIn.push_back(line);
    }
    rawIn.pop_back(); //lole

    // for(int i=0; i < rawIn.size(); i++){
    //     std::cout << rawIn[i] << std::endl;
    // }

    int max = maxCalories(rawIn);
    std::cout << "Part 1: " << max << std::endl;
    
    std::cout << "Part 2: " << topThreeCalories(rawIn) << std::endl;
    return 0;
}

