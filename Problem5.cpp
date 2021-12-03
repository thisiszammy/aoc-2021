//Author : Michael Jay C. Zamoras
//AOC-2021 : Problem 5

#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>

int main(){
	
	std::string x;
	
	int zeroSum[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
	int oneSum[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
	
	while(std::cin >> x){
		if(x == "end") break;
		
		for(int i = 0; i < 12; i++){
			if(x[i] == '0'){
				zeroSum[i]++;
			}else{
				oneSum[i]++;
			}
		}
	}
	
	std::string gammaRate = "";
	std::string epsilonRate = "";
	
	for(int i = 0; i < 12; i++){
		if(zeroSum[i] > oneSum[i]){
			gammaRate += "0";
			epsilonRate += "1";
		}else{
			gammaRate += "1";
			epsilonRate += "0";
		}
	}
	
	int gamma = std::stoi(gammaRate,0,2);
	int epsilon = std::stoi(epsilonRate,0,2);
	
	std::cout << gamma*epsilon;
	
	
	return 0;
}
