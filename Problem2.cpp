// Author : Michael Jay C. Zamoras
// AOC-2021 : Problem 2

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

int main(){
	
	int x;
	int sum1 = 0;
	
	std::vector<int> nums;
	while(std::cin>>x){
		nums.push_back(x);
	}
	
	for(int i = 0; i < nums.size()-3; i++){
		if((nums[i] + nums[i+1] + nums[i+2]) < (nums[i+1] + nums[i+2] + nums[i+3])){
			sum1++;
		}
	}
	
	std::cout << sum1;
	
}
