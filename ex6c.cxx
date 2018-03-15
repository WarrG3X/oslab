#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

class Node{
public:
	int val;
	int loc;
	Node* ptr;

	Node(){
		val = 0;
		loc = -1;
		ptr = NULL;
	}

}memory[100];





class File{
	public:
		int fileID;
		int size;
		int startval;
		Node* start;
	
	bool checkMem(int i){
		if(memory[i].val!=0)
			return false;
		return true;

	}

	int getMem(){

		int k = rand()%100;
		while(!checkMem(k))
			k = rand()%100;
		return k;

	}

	Node* getEnd(){
		Node* k = start;
		while(k->ptr!=NULL)
			k = k->ptr;
		return k;
	}

	void allocMem(){
		start = &memory[startval];
		start->val = fileID;
		start->loc = startval;
		for(int i=0;i<size-1;i++){
			int m = getMem();
			Node* e = getEnd();
			memory[m].val=fileID;
			memory[m].loc = m;
			e->ptr = &memory[m];
		}

	}

	void display(){
		Node* k = start;
		while(k->ptr!=NULL){
			std::cout<<k->loc<<" --> ";
			k = k->ptr;
		}

		std::cout<<k->loc<<std::endl;

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
		std::cout<<"Starting Block - ";
		std::cin>>files[i].startval;
		files[i].allocMem();
	}
	
	std::cout << "\n--------------\n";
	for(int i=0;i<n;i++){
		std::cout << "File "<<files[i].fileID<<std::endl;;
		files[i].display();
	}

	return 0;
}

