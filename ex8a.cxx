#include<bits/stdc++.h>




void FIFOreplace(std::deque<int> slots,std::deque<int> pages){
	
	int total_faults = 0;
	int pointer = 0;

	for(int i=0;i<pages.size();i++){

	if (std::find(slots.begin(),slots.end(),pages[i])==slots.end()){
		std::cout<<pages[i]<<" Not Found\n";
		total_faults +=1;
		slots[pointer] = pages[i];
		pointer +=1;
		if(pointer==slots.size())
			pointer = 0;


	}
	else{
		std::cout<<pages[i]<<" Found\n";

		
	}
	
	std::cout<<"Slots = ";
	for(int j=0;j<slots.size();j++)
		std::cout<<slots[j]<<" ";
	std::cout<<"\n\n";

	}

	std::cout<<"Total Page Faults = "<<total_faults<<"\n"; 

}


int main(){

	int f,p,c;
	std::string rawInput;
	std::deque<int> pages;
	std::deque<int> slots;

	std::cout<<"Enter No. of Slots - ";
	std::cin>>f;
	std::cout<<"Enter Page Reference String - ";
	std::cin.ignore();
	getline(std::cin,rawInput);
	std::istringstream iss(rawInput);

	
	while(iss >> c){
		pages.push_back(c);

	}



	for(int i=0;i<f;i++)
		slots.push_back(-1);
	std::cout<<"\n\n";
	FIFOreplace(slots,pages);
	return 0;

}
