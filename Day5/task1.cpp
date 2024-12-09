#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Key{
    int before;
    int after;
};

int main(){
    std::vector<Key> keyData;
    std::vector<std::vector<int>> pageData;
    std::string line;
    std::ifstream file("input1small.txt");

    while(std::getline(file, line)){
        if(line == "") break;
        int before = std::stoi(line.substr(0, line.find_first_of('|')));
        int after = std::stoi(line.substr(line.find_first_of('|')+1, line.size()));
        keyData.push_back(Key{before, after});
    }

    for(int i = 0;std::getline(file, line); i++){
        pageData.push_back(std::vector<int>());
        for(;;){
            int commaPos = line.find_first_of(',');
            if(commaPos == std::string::npos){
                pageData[i].push_back(std::stoi(line));
                break;
            }
            pageData[i].push_back(std::stoi(line.substr(0, commaPos)));
            line.erase(0, commaPos+1);

        }
    }

    return(0);
}