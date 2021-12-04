//Author : Michael Jay C. Zamoras
//AOC-2021 : Problem 6

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>

std::string getBinary(std::vector<std::string> inputs, bool factorIsGreater){
	
	char prevBit = '0';
	int strCtr = 0;
	while(inputs.size() != 1){
		
		int arr[2] = {0,0};
		
		for(int i = 0; i < inputs.size(); i++){
			if(inputs[i][strCtr] == '0'){
				arr[0]++;
			}else{
				arr[1]++;
			}
		}

		
		if(arr[0]>arr[1]){
			if(factorIsGreater){
				prevBit='0';
			}else{
				prevBit='1';
			}
			strCtr++;
		}else{
			if(factorIsGreater){
				prevBit='1';
			}else{
				prevBit='0';
			}
			strCtr++;
		}
		
		for(int i = 0; i < inputs.size(); i++){
			if(inputs[i][strCtr-1] != prevBit){
				inputs.erase(inputs.begin() + i);
				i--;
			}
		}
	}
	
	return inputs[0];
}


int main(){
	
	std::string x;
	
	std::vector<std::string> inputs;
	
	while(std::cin >> x){
		if(x=="end") break;
		inputs.push_back(x);
	}
	
	
	std::string oxygenRate = getBinary(inputs, true);
	std::string co2Rate = getBinary(inputs, false);
	
	
	int oxygen = std::stoi(oxygenRate,0,2);
	int co2 = std::stoi(co2Rate,0,2);
	
	std::cout << oxygen * co2;
	
	
	
	
	return 0;
}
