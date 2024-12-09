#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void bubbleSort(std::vector<int>* vector){
    int swapped = 0;
    int temp = 0;
    
    do{
        swapped = 0;
        for(int i = 0; i < vector->size()-1; i++){
            if(vector->at(i) > vector->at(i+1)){
                temp = vector->at(i);
                vector->at(i) = vector->at(i+1);
                vector->at(i+1) = temp;
                swapped = 1;
            }
        }
    } while(swapped == 1);

    return;
}


int main(){

    std::ifstream inputData("input.txt");
    std::string lineData;
    std::vector<int> listOne, listTwo;
    int distance = 0;
    int similarity = 0;
    int counter = 0;
    

    while(std::getline(inputData, lineData)){
        listOne.push_back(std::stoi(lineData.substr(0, lineData.find_first_of(" "))));
        listTwo.push_back(std::stoi(lineData.substr(lineData.find_last_of(" "), lineData.size())));
    }
    inputData.close();

    bubbleSort(&listOne);
    bubbleSort(&listTwo);

    for(int i = 0; i < listOne.size(); i++){
        counter = 0;
        //distance += abs((listOne[i] - listTwo[i]));

        for(int j = 0; j < listTwo.size(); j++){
            if(listOne[i] != listTwo[j]) continue;
            if(listOne[i] > listTwo[j]) break;

            if(listOne[i] == listTwo[j]) counter++;
        }
        similarity += listOne[i] * counter;
    }

    std::cout << similarity << std::endl;


    return(0);
}