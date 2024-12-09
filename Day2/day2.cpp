#include <iostream>
#include <fstream>
#include <vector>
#include <string>


bool checkSafety(std::vector<int>* levels){
    bool safe = true;
    bool ascending = true;
    if(levels->at(0) > levels->at(1)) ascending = false;
    for(int i = 0; i < levels->size(); i++){
        if(i+1 >= levels->size()) continue;
        if((levels->at(i) < levels->at(i+1)) && !ascending) return(false);
        if((levels->at(i) > levels->at(i+1)) && ascending) return(false);
        if(abs(levels->at(i) - levels->at(i+1)) > 3) return(false);
        if(abs(levels->at(i) - levels->at(i+1)) == 0) return(false);
    }
    return(true);
}

int main(){

    std::string inputLine;
    std::vector<std::vector<int>> reports;
    int safeReports = 0;

    std::ifstream input("input.txt");
    for(int i = 0; std::getline(input, inputLine); i++){
        int space = 1;
        reports.push_back(std::vector<int>());
        while(true){
            space = inputLine.find_first_of(" ");
            reports[i].push_back(std::stoi(inputLine.substr(0, space)));
            if(inputLine.find_first_of(" ") == std::string::npos) break;
            inputLine.erase(0, space+1);
        }
    }
    input.close();


    for(int i = 0; i < reports.size(); i++){
        //if(checkSafety(&reports[i])) safeReports++;
        if(checkSafety(&reports[i]) == false){
            for(int j = 0; j < reports[i].size(); j++){
                int temp = reports[i][j];
                reports[i].erase(reports[i].begin()+j);
                if(checkSafety(&reports[i])){
                    safeReports++;
                    break;
                }
                reports[i].insert(reports[i].begin()+j, temp);
            }
        }else safeReports++;
    }

    std::cout << safeReports << std::endl;
    return(0);
}