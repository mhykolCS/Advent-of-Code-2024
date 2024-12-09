#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(){


    std::ifstream input("input.txt");
    std::string line;
    std::vector<std::string> data;
    while(std::getline(input, line)){
        data.push_back(line);
    }

    int xmasCount = 0;
    int test;
    for(int row = 0; row < data.size(); row++){
        for(int col = 0; col < data[row].size(); col++ ){
            if(data[row][col] == 'A'){
                if(col < 1 || data[row].size() - col < 1) continue;
                if(row < 1 || data.size() - row <= 1) continue;

                if(data[row-1][col-1] == 'M' && data[row-1][col+1] == 'M' && data[row+1][col-1] == 'S' && data[row+1][col+1] == 'S') xmasCount++;
                if(data[row-1][col-1] == 'S' && data[row-1][col+1] == 'S' && data[row+1][col-1] == 'M' && data[row+1][col+1] == 'M') xmasCount++;
                if(data[row-1][col-1] == 'M' && data[row-1][col+1] == 'S' && data[row+1][col-1] == 'M' && data[row+1][col+1] == 'S') xmasCount++;
                if(data[row-1][col-1] == 'S' && data[row-1][col+1] == 'M' && data[row+1][col-1] == 'S' && data[row+1][col+1] == 'M') xmasCount++;

            }
        }
    }

    std::cout << xmasCount << std::endl;


    return(0);

}