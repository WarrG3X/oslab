#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

class Process{
	public:
		int id;
		int burst;
		float wait;
		float turn;
	}plist[10];
	
	
bool burstcomparator(Process a, Process b){
	return a.burst < b.burst;
}

	
void roundrobin(Process plist[],int n,int q){
	
	int ttime = 0;
	int dq = 0;
	
	std::deque<Process> buffer(plist,plist+n);
	std::deque<Process> final;
	
	while(buffer.size()>0){
		Process *k = &buffer.front();

		if(k->burst < q){
			dq = k->burst;
			k->burst = 0;
		}
		else{
			dq = q;
			k->burst += -q;
		}

		ttime += dq;
		for(int p = 1;p<buffer.size();p++)
			buffer[p].wait += dq;

		if(k->burst==0){
			Process j = buffer.front();
			j.turn = ttime;
			final.push_back(j);
			buffer.pop_front();
		}
		else{
			Process j = buffer.front();
			buffer.pop_front();
			buffer.push_back(j);
		}

	}
	
		
	int i;
	float avgWait=0;
	float avgTurn=0;


	
	for(i=0;i<n;i++){
		
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

	int n,q;
	std::cout<<"Enter Time Quantum - \n";
	std::cin >> q;
	std::cout<<"Enter no. of processes - \n";
	std::cin >> n;


	for(int i=0;i<n;i++)
	{
		std::cout<<"Process "<<i+1<<std::endl;
		std::cout<<"Enter Burst time - ";
		std::cin>>plist[i].burst;
		plist[i].id = i+1;
	}
	
	roundrobin(plist,n,q);

	return 0;
}

