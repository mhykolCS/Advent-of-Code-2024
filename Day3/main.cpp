#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int main(){

    std::ifstream file("input.txt");
    std::string line;
    std::vector<std::string> data;

    while(std::getline(file, line)){
        data.push_back(line);
    }
    file.close();
 
    std::string key = "0123456789,";
    int total = 0;
    bool enabled = true;
    for(int i = 0; i < data.size(); i++){
        
        for(;;){
            if(enabled){
                std::size_t mulPos = data[i].find("mul(");
                std::size_t dontPos = data[i].find("don\'t()");

                if(mulPos == std::string::npos) break;
                if(dontPos == std::string::npos) dontPos = mulPos+1;

                if(dontPos > mulPos){
                    data[i].erase(0, mulPos+4);
                }else{
                    data[i].erase(0, dontPos+7);
                    enabled = false;
                    continue;
                } 
            } else{
                    std::size_t doPos = data[i].find("do()");
                    if(doPos == std::string::npos) break;
                    data[i].erase(0, doPos+4);
                    enabled = true;
                    continue;
            }
            
            int result = 0;

            std::size_t endBracketPos = data[i].find_first_of(")");

            if(endBracketPos == std::string::npos) continue;
            if(data[i].substr(0, endBracketPos).find_first_not_of(key) != std::string::npos) continue;

            std::size_t commaPos = data[i].find_first_of(",");
            if(commaPos == std::string::npos) continue;

            int num1 = stoi(data[i].substr(0, commaPos));
            int num2 = stoi(data[i].substr(commaPos+1, endBracketPos));
            
            total+=(num1*num2);
        }

    }

    std::cout << total << std::endl;


    return(0);
}