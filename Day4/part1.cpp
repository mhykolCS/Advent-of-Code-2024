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
            if(data[row][col] == 'X'){
                if(data[row].size() - col >= 3 && data[row][col+1] == 'M' && data[row][col+2] == 'A' && data[row][col+3] == 'S') xmasCount++; //check right
                if(col >= 3 && data[row][col-1] == 'M' && data[row][col-2] == 'A' && data[row][col-3] == 'S') xmasCount++; //check left
                if(row >= 3 && data[row-1][col] == 'M' && data[row-2][col] == 'A' && data[row-3][col] == 'S') xmasCount++; //check up
                if(data[row].size() - row >= 4 && data[row+1][col] == 'M' && data[row+2][col] == 'A' && data[row+3][col] == 'S') xmasCount++; //check down 
                if(row >= 3 && data[row].size() - col >= 3 && data[row-1][col+1] == 'M' && data[row-2][col+2] == 'A' && data[row-3][col+3] == 'S') xmasCount++; //check up->right
                if(row >= 3 && col >= 3 && data[row-1][col-1] == 'M' && data[row-2][col-2] == 'A' && data[row-3][col-3] == 'S') xmasCount++; //check up->left
                if(data[row].size() - row >= 4 && data[row].size() - col >= 3 && data[row+1][col+1] == 'M' && data[row+2][col+2] == 'A' && data[row+3][col+3] == 'S')xmasCount++; //check down->right
                if(data[row].size() - row >= 4 && col >= 3 && data[row+1][col-1] == 'M' && data[row+2][col-2] == 'A' && data[row+3][col-3] == 'S')xmasCount++; //check down->left
            }
        }
    }

    std::cout << xmasCount << std::endl;


    return(0);

}