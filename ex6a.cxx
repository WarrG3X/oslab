#include<iostream>
#include<vector>


const int BLOCK_SIZE = 1;
int memory[100] = {0};

class File{
	public:
		int fileID;
		int size;
		int start;
		std::vector<int> location;
	
	void checkMem(){
		for(int i = start;i<start+size;i++){
			if(memory[i]!=0)
				throw std::bad_alloc();	
		}

	}

	void allocMem(){
		try{
			checkMem();
			for(int i=start;i<start+size;i++){
				memory[i]=fileID;
				location.push_back(i);
			}
		}
		catch(const std::bad_alloc &e){
			std::cerr << "ERROR : ";
			std::cerr << e.what();
			std::cerr << "\nMemory Unavailable" << std::endl;
		}
	}


}files[10];


		

int main(){

	int n;
	std::cout<<"No. of files - ";
	std::cin>>n;

	for(int i=0;i<n;i++){
		files[i].fileID = i+1;
		std::cout<<"File "<<i+1<<std::endl;
		std::cout<<"File Size - ";
		std::cin>>files[i].size;
		std::cout<<"Starting Block - ";
		std::cin>>files[i].start;
		files[i].allocMem();
	}
	
	std::cout << "\n--------------\n";
	for(int i=0;i<n;i++){
		std::cout << "File "<<files[i].fileID<<std::endl;;
		std::cout << "Locations ";
		for(auto j : files[i].location)
			std::cout<< j << " ";
		std::cout<<std::endl;
	}

	return 0;
}

