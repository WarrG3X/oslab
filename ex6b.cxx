#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>


int memory[100] = {0};





class File{
	public:
		int fileID;
		int size;
		int index;
		std::vector<int> index_block;
	
	bool checkMem(int i){
		if(memory[i]!=0)
			return false;
		return true;

	}

	int getMem(){

		int k = rand()%100;
		while(!checkMem(k))
			k = rand()%100;
		return k;

	}


	void allocMem(){
		for(int i=0;i<size;i++){
			int m = getMem();
			memory[m]=fileID;
			index_block.push_back(m);
		}

	}


}files[10];


		

int main(){

	srand(time(NULL));
	int n;
	std::cout<<"No. of files - ";
	std::cin>>n;

	for(int i=0;i<n;i++){
		files[i].fileID = i+1;
		std::cout<<"File "<<i+1<<std::endl;
		std::cout<<"File Size - ";
		std::cin>>files[i].size;
		std::cout<<"Index Block - ";
		std::cin>>files[i].index;
		files[i].allocMem();
	}
	
	std::cout << "\n--------------\n";
	for(int i=0;i<n;i++){
		std::cout << "File "<<files[i].fileID<<std::endl;;
		for(auto j : files[i].index_block)
			std::cout<<files[i].index<<" --> "<< j << "\n";
		std::cout<<std::endl;
	}

	return 0;
}

