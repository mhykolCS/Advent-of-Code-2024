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
    std::vector<int> sortedKeyData;
    std::vector<std::vector<int>> pageData;
    std::string line;
    std::ifstream file("input.txt");

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

    sortedKeyData.push_back(keyData[0].before);
    sortedKeyData.push_back(keyData[0].after);

    for(int i = 1; i < keyData.size(); i++){
        int beforePos = -1;
        int afterPos = -1;
        for(int j = 0; j < sortedKeyData.size(); j++){
            if(sortedKeyData[j] == keyData[i].before) beforePos = j;
            if(sortedKeyData[j] == keyData[i].after) afterPos = j;
        }

        if(beforePos == -1 && afterPos == -1){ // if neither are in sorted list
            sortedKeyData.push_back(keyData[i].before);
            sortedKeyData.push_back(keyData[i].after);
            continue;
        }

        if(beforePos != -1 && afterPos == -1){ // if before is in sorted list
            sortedKeyData.push_back(keyData[i].after);
            continue;
        }

        if(beforePos == -1 && afterPos != -1){ // if after is in sorted list
            std::vector<int>::iterator it = sortedKeyData.begin();
            sortedKeyData.insert(it+afterPos, keyData[i].before);
            continue;
        }

        if(beforePos != -1 && afterPos != -1){ // if both are in sorted list

            if(beforePos < afterPos) continue;

            std::vector<int>::iterator it = sortedKeyData.begin();
            sortedKeyData.erase(it+beforePos);
            it = sortedKeyData.begin();
            sortedKeyData.insert(it+afterPos, keyData[i].before);
            continue;
        }
    }
    //97 75 47 61 53 29 13
    //75, 47, 61, 53, 29
    //97, 61, 53, 29, 13

    // page data, grab item and check left, find key value and follow right. if data from right of key data is present left of page data, it's bad

    int total = 0;

    for(int i = 0; i < pageData.size(); i++){
        bool isSorted = true;
        for(int j = pageData[i].size()-1; j > 0; j--){
            if(isSorted == false) break;
            int keyPos = -1;
            for(int k = 0; k < sortedKeyData.size(); k++){
                if(pageData[i][j] == sortedKeyData[k]){
                    keyPos = k;
                    break;
                }
            }
            if(keyPos == -1) continue;

            for(int k = keyPos; k < sortedKeyData.size(); k++){
                for(int l = j-1; l >= 0; l--){
                    if(sortedKeyData[k] == pageData[i][l]){
                        isSorted = false;
                        break;
                    }
                }
                if(isSorted == false) break;
            }
        }

        if(isSorted){
            std::cout << pageData[i][pageData[i].size()/ 2] << std::endl;
            total += pageData[i][pageData[i].size()/ 2];
        }
    }

    std::cout << total << std::endl;

    return(0);
}