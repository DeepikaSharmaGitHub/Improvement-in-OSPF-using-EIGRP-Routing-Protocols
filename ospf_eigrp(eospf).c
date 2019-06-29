#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<math.h>
#include<limits.h>
#include <time.h> 
#include <unistd.h>

unsigned sleep(unsigned seconds);

int main()
{
	clock_t t; 
    t = clock(); 
	//Declaring the global variables
	int count,source,i,j,k,w,v,n;
	int bandwidth_matrix[100][100]={INT_MAX},delay_matrix[100][100]={INT_MAX},distance[2][100]={INT_MAX},last[100];
	int flag[100];
	long min;
	
	//Inputting the data 
	printf("\nEnter the no of routers: ");
	scanf("%d",&count); 
	
	printf("\nEnter the bandwidth and delay values:");
	for(i=0;i<count;i++)
	{
		for(j=0;j<count;j++)
		{
			
			if(i!=j)
			{
			
				printf("\nBandwidth from Router %d -> Router %d:",i,j);
				scanf("%d",&bandwidth_matrix[i][j]);
				printf("\ndelay from Router %d -> Router %d:",i,j);
				scanf("%d",&delay_matrix[i][j]);
		    }
		}
	}
	//Cost matrix is inputted at this point
	
	printf("\nEnter the source router: ");
	scanf("%d",&source);
	//All data is now inputted
	
	//filling the distance matrix
	int a,mind;
	for( a=0;a<=1;a++)
	{
		for(v=0;v<count;v++)
		{
			flag[v]=0;
			last[v]=source;
			distance[a][v]=((pow(10,7)/bandwidth_matrix[source][v])+(delay_matrix[source][v]+100+100))*256;
		}
		
		flag[source]=1;
		
		for(i=0;i<count;i++)
		{
			if(a!=0)
			{
				min=mind;
			}
			else
			{
				min=pow(10,5);
		    }
			for(w=0;w<count;w++)
			{
				if(!flag[w])
					if(a!=0)
					{
						if(mind>=distance[a][w])
						{
							v=w;
							min=distance[a][w];
						}
					}
					else
					{
						
						if(distance[a][w]<min)
						{
							v=w;
							min=distance[a][w];
						}
					}
			}
			flag[v]=1;
			
			for(w=0;w<count;w++)
			{
				if(!flag[w])
				if(min+((pow(10,7)/bandwidth_matrix[v][w])+(delay_matrix[v][w]+100+100))*256<distance[a][w])
				{
					distance[w][a]=min+((pow(10,7)/bandwidth_matrix[v][w])+(delay_matrix[v][w]+100+100))*256;
					last[w]=v;
					mind=distance[a][w];
				}
			}
		}
	}
	for(i=0;i<count;i++)
	{      
		if(source!=i)
			{
			printf("\nRouter %d ==> Router %d:\nPath taken:%d",source,i,i);
			w=i;	
			while(w!=source)
			{	
	 			printf("<--%d",last[w]);w=last[w];
			}
			printf("\nShortest path cost:%d\n",distance[0][i]);
		}
	   
	}

	//t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
  
    //printf("took %f seconds to execute \n", time_taken); 
    time_taken=0;
    sleep(5);
    time_taken=5;
    while(1)
    {
		if(time_taken==5)
    	{
    		printf("If neighbours change enter 0 otherwise enter 1\n");
    		scanf("%d",&n); 
    		switch(n)
    		{
    			case 1:
			
 					for(i=0;i<count;i++)
					{
						for(j=0;j<count;j++)
						{
				
							if(i!=j)
							{
			
								printf("\n Router %d -> Router %d",i,j);	
											
		    				}		
						}
					}
					printf("\n");
					printf("Neighbours are same\n");
					break;
				
				case 0:
					printf("Neighbours changed");
					break;
				default:
  			  		printf("Wrong choice entered, terminating");
  			  		exit(0);
  			}
  		}
  			sleep(5);
	}
}

