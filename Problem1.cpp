// Author : Michael Jay C. Zamoras
// AOC-2021 : Problem 1

#include <iostream>

int main(){
	
	int x, prev = -1, greatCtr = 0;
	
	while(std::cin >> x){
		if(prev == -1){
			prev = x;
			continue;
		}else{
			if(x > prev){
				greatCtr++;
			}
			prev = x;
		}
		
	}
	
	std::cout << greatCtr;
	
}
