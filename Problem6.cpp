//Author : Michael Jay C. Zamoras
//AOC-2021 : Problem 6

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>

std::string getOxygenBinary(std::vector<std::string> inputs){
	
	int arr[2] = {0,0};
	
	std::string oxBinary = "";
	char prevBit = '0';
	bool runFunc = true;
	
	while(runFunc){
		for(int i = 0; i < inputs.size(); i++){
			if(inputs[i][oxBinary.size()] == '0'){
				arr[0]++;
			}else{
				arr[1]++;
			}
		}

		
		if(arr[0]>arr[1]){
			prevBit='0';
			oxBinary+="0";
		}else{
			prevBit='1';
			oxBinary+="1";
			
			if(arr[0] == arr[1]){
				runFunc = false;
			}
		}
		
		for(int i = 0; i < inputs.size(); i++){
			if(inputs[i][oxBinary.size()-1] != prevBit){
				inputs.erase(inputs.begin() + i);
				i--;
			}
		}
		
		arr[0] = 0;
		arr[1] = 0;
	}
	
	
	
	return oxBinary;
}

std::string getCO2Binary(std::vector<std::string> inputs){
	
	
	int arr[2] = {0,0};
	
	std::string co2Binary = "";
	char prevBit = '0';
	bool runFunc = true;
	
	while(runFunc){
		for(int i = 0; i < inputs.size(); i++){
			if(inputs[i][co2Binary.size()] == '0'){
				arr[0]++;
			}else{
				arr[1]++;
			}
		}
		
		if(arr[0] == 0 || arr[1] == 0){
			for(int l = co2Binary.size(); l < 12; l++){
				co2Binary += inputs[0][l];
			}
			break;
		}
		
		if(arr[0]>arr[1]){
			prevBit='1';
			co2Binary+="1";
		}else{
			prevBit='0';
			co2Binary+="0";
		}
		
		for(int i = 0; i < inputs.size(); i++){
			if(inputs[i][co2Binary.size()-1] != prevBit){
				inputs.erase(inputs.begin() + i);
				i--;
			}
		}
		
		arr[0] = 0;
		arr[1] = 0;
	}
	
	
	return co2Binary;
}


int main(){
	
	std::string x;
	
	std::vector<std::string> inputs;
	
	while(std::cin >> x){
		if(x=="end") break;
		inputs.push_back(x);
	}
	
	
	std::string oxygenRate = getOxygenBinary(inputs);
	std::string co2Rate = getCO2Binary(inputs);
	
	
	int oxygen = std::stoi(oxygenRate,0,2);
	int co2 = std::stoi(co2Rate,0,2);
	
	std::cout << oxygen * co2;
	
	
	
	
	return 0;
}
