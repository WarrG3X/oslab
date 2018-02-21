#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

class Process{
	public:
		int id;
		int arrival;
		int burst;
		float wait;
		float turn;
	}plist[10];
	
	
bool burstcomparator(Process a, Process b){
	return a.burst < b.burst;
}

bool arrivalcomparator(Process a, Process b){
	return a.arrival > b.arrival;
}
	
void sjf_np(Process plist[],int n){
	
	int ttime = 0;
	
	std::vector<Process> buffer(plist,plist+n);
	std::sort(buffer.begin(),buffer.end(),arrivalcomparator);
	std::deque<Process> temp;
	std::deque<Process> final;
	
		while(buffer.size()>0){
			while(buffer.back().arrival <= ttime){
				if (buffer.size()==0) break;
				Process k = buffer.back();
				buffer.pop_back();
				temp.push_back(k);
				//std::cout<<"Pushing - "<<k.burst<<std::endl;
				//std::cout<<buffer.size()<<std::endl;	
			}
			
			if(temp.size()>0){
				std::sort(temp.begin(),temp.end(),burstcomparator);
				Process z = temp.front();
				final.push_back(z);
				temp.pop_front();
				ttime += z.burst;
				
			}
				
			}
		
		std::sort(temp.begin(),temp.end(),burstcomparator);
		while(temp.size()>0){
			Process z = temp.front();
			final.push_back(z);
			temp.pop_front();
		}

		//std::cout<<final.size()<<"$\n";	
		//for(Process k : final)
		//std::cout<<k.arrival<<std::endl;
				
	
	
	
	int i;
	float avgWait=0;
	float avgTurn=0;
	float time=0;	


	
	for(i=0;i<n;i++){
		final[i].wait = time;
		time += final[i].burst;
		final[i].turn = time;
		
		avgWait += final[i].wait;
		avgTurn += final[i].turn;
		
		std::cout<<"Wait Time for Process"<<final[i].id<<" = "<<final[i].wait<<std::endl;
		std::cout<<"Turnaround Time for Process"<<final[i].id<<" = "<<final[i].turn<<std::endl;

			
		
		
	}
	
	avgWait = avgWait/n;
	avgTurn = avgTurn/n;
	
	std::cout<<"Average Wait Time = "<<avgWait<<std::endl;
	std::cout<<"Average Turnaround Time = "<<avgTurn<<std::endl;
	
}



int main(){

	int n;
	std::cout<<"Enter no. of processes - \n";
	std::cin >> n;


	for(int i=0;i<n;i++)
	{
		std::cout<<"Process "<<i+1<<std::endl;
		std::cout<<"Enter Burst time - ";
		std::cin>>plist[i].burst;
		std::cout<<"Enter Arrival time  - ";
		std::cin>>plist[i].arrival;
		plist[i].id = i+1;
	}
	
	sjf_np(plist,n);

	return 0;
}
