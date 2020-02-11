#include<stdio.h>

void create_processes(int n, int bt[n], int at[n], int te[n], int wt[n], int rt[n], int* ts){ //Creates the processes 
	//bt=burst time;
	//at=arrival time;
	//te=number of quantum bursts;
	//wt=wait time;
	//rt=remaining time;
	//ts=quantum;
	printf("\nEnter burst time and arrival time\n");
  	for(int i=0;i<n;i++){
    	printf("P%d  \nburst time ",i+1);
    	scanf("%d",&bt[i]);
    	rt[i]=bt[i];
    	printf("arrival time   :  ");
    	scanf("%d",&at[i]);
    	te[i]=0;
    	wt[i]=0;
  	}
  	int x;
  	printf("\nEnter quantum:\t");
  	scanf("%d",&x);
  	*ts=x; 
}

void sort_arrays(int n, int at[n], int bt[n]){ //sort the processes after arrival time
  	int temp;
  	for(int i=0;i<n;i++){
    	for(int j=i+1;j<n;j++){
      		if(at[i]>at[j]){
        		temp=at[i];
        		at[i]=at[j];
        		at[j]=temp;
        		temp=bt[i];
        		bt[i]=bt[j];
        		bt[j]=temp;
      		}
    	}
  	}  
}

void print_processes(int n, int bt[n], int rt[n], int at[n]){ //printing the processes
  	printf("\nProcess      :");
  	for(int i=0;i<n;i++){
    	printf("  %d",i+1);
  	}
  	printf("\nBurst time   :");
  	for(int i=0;i<n;i++){
    	printf("  %d",bt[i]); 
  	}
  	printf("\nArrival time :");
  	for(int i=0;i<n;i++){
    	printf("  %d",at[i]);
  	}
}

void RoundRobin(int n, int rt[n], int te[n], int wt[n], int ts){
	//q=moment;
  	int q=0;
  	int checked=0;
  	while(1){
    	checked=0;
    	for(int i=0;i<n;i++){
      		if(rt[i]==0)  
        		continue;
        	checked=1;
      		if(rt[i]>ts){
        		q=q+ts;
        		rt[i]=rt[i]-ts;
        		te[i]=te[i]+1;
      		}
      		else{
        		wt[i]=q-te[i]*ts;
        		q=q+rt[i]; 
        		rt[i]=0;
      		}
    	}
    	if(checked==0){
    		break;
    	}
  	} 
}

void print_times(int n, int wt[n], int at[n]){
  	int aw;
  	float awt;
  	awt=0;
  	printf("\nProcess Waiting time");
  	for(int i=0;i<n;i++){
    	wt[i]=wt[i]-at[i];
    	printf("\n P%d      :   %d",i+1,wt[i]); 
    	awt=awt+wt[i];
  	}
  	aw=awt;
  	printf("\nTotal waiting time %d",aw);
  	printf("\nAverage waiting time %f",awt/n);
}

int main(){
  	int n,ts;
  	printf("Enter number of process :\t");
  	scanf("%d",&n);
  	int bt[n],wt[n],te[n],rt[n],at[n];
  	create_processes(n, bt, at, te, wt, rt, &ts);
  	sort_arrays(n, at, bt);
  	print_processes(n, bt, rt, at);
  	RoundRobin(n, rt, te, wt, ts);                       
  	print_times(n, wt, at);
}