#include<iostream>
#include<vector>



const int m = 3;
const int n = 5;


void subtract(int need[n][m],int max[n][m],int allocation[n][m]){
	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			need[i][j] = max[i][j] - allocation[i][j];

	}

}




bool finished(int finish[]){

	for(int i=0;i<n;++i){
		if(finish[i]==0)
			return false;
	}

	return true;

}


bool checkAlloc(int need[],int available[]){

	for(int i=0;i<m;i++){
		if (need[i] > available[i])
			return false;


	}


	return true;
}


void Alloc(int allocation[n][m],int available[],int p){

	for(int i=0;i<m;i++)
		available[i] += allocation[p][i];

}


void detectDeadlock(int available[m],int max[n][m],int allocation[n][m],int need[n][m]){

	int finish[n] = {0};

	while(!finished(finish)){

		
		bool deadlock = true;

		for(int i=0;i<n;i++){

			if(finish[i]==0 && checkAlloc(need[i],available)){
				
				deadlock = false;	
				finish[i]=1;
				Alloc(allocation,available,i);
				
				

			}

			

	
		}

		if(deadlock){
			std::cout<<"Deadlock Detected\n";
			return;
		}


	
	
	}



	std::cout<<"No Deadlock. Safe State\n";
	return;


}







int main(){
	
	int available[m] = {3,3,2};
	int max[n][m] = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
	int allocation[n][m] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
	int need[n][m];
	subtract(need,max,allocation);
	detectDeadlock(available,max,allocation,need);




	return 0;

}
