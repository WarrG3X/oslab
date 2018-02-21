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
	
	Process(){
		wait = 0;
		turn = 0;
	}
	}plist[10];
	
	
bool burstcomparator(Process a, Process b){
	return a.burst < b.burst;
}

bool arrivalcomparator(Process a, Process b){
	return a.arrival > b.arrival;
}
	
void sjf_p(Process plist[],int n){
	
	int ttime = 0;
	
	std::vector<Process> buffer(plist,plist+n);
	std::sort(buffer.begin(),buffer.end(),arrivalcomparator);
	std::deque<Process> temp;
	std::deque<Process> final;

	
		while(buffer.size()>0 | temp.size() > 0){
			while(buffer.back().arrival <= ttime){
				if (buffer.size()==0) break;
				Process k = buffer.back();
				buffer.pop_back();
				temp.push_back(k);
				//std::cout<<"Pushing - "<<k.burst<<" "<<ttime<<std::endl;
				//std::cout<<buffer.size()<<std::endl;	
			}

			if(temp.size()>0){
				std::sort(temp.begin(),temp.end(),burstcomparator);
				//for(Process k: temp)
				//std::cout<<k.id<<":"<<k.burst<<" ";
				//std::cout<<"\n";
				temp.front().burst -= 1;
				ttime +=1;
				for(int p = 1;p<temp.size();p++)
					{
					temp[p].wait +=1;
					}	
				if(temp.front().burst==0)
					{temp.front().turn = ttime - temp.front().arrival;
					 final.push_back(temp.front());
					 temp.pop_front();
					 }
				

				
			}else{
			
				ttime += 1;
			
			}

			}
		

		//std::cout<<temp.size()<<"$\n";	
		//for(Process k : final)
		//std::cout<<k.burst<<std::endl;
				
	
	
	
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
	
	sjf_p(plist,n);

	return 0;
}
