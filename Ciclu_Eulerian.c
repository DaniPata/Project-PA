#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "Fleury.h"
#include "Ros.h"


/**
* This is the main function
* @author Pață Ionel-Daniel
* @date 1/6/2018
*/




int main()
{
	int alg_choice;
	time_t t;
	/* Intializes random number generator */
	srand((unsigned) time(&t));
	printf("Alegeti algoritmul dorit:\n");
	scanf("%d", &alg_choice);
    switch(alg_choice) {
		case 1 : {
			int i,j,cycles,node_one,node_two;
			printf("Enter the number of nodes in a graph\n");
			scanf("%d",&n);
			
			printf("Enter the value of node of graph\n");
			for( i=1; i<=n; i++)
			{
			 b[i]=i;//store the nodes in b[] array
			}
			cycles=random_number(n*2);
			printf(" %d \n",cycles);

			while(cycles!=0)
			{
			node_one=0;
			node_two=0;



				  do
			 {
			 node_one=random_number(n);

			 }while(node_one==0);

			 do
			 {
			 node_two=random_number(n);

			 }while(node_two==node_one||node_two==0);


			  m[node_one][node_two]=1;

			  m[node_two][node_one]=1;


			 printf("%d -> %d  \n",node_one,node_two);
			 Sleep(300);

			 cycles--;
			}
			printf("\n");
			display_matrix(n);
			
			//Get the Graph details by using adjacency matrix

			for( i=1; i<=n; i++)
			printf(" %d ",b[i]);

			for( i=1;i<=n; i++)
			{
				for( j=1; j<=n; j++)
				{
					if(m[i][j]==1)
					{
						ajMat[i][j]='y';
					}
					else
					{
						ajMat[i][j]='n';
					}
				}
			}

			  //findRoot() will return 0 if euler path/circuit not possible
			//otherwise it will return array index of any node as root
			int root;
			if(root=findRoot())
			{
			  if(count) printf("Available Euler Path is\n");
			  else printf("Available Euler Circuit is\n");
			  finalPath[fp++]=root;
			  eularFind(root);
			  displayPath();
			}
			else printf("Euler path or circuit not available\n");
			getch();
			break;
		}
		case 2 : {
			int n;
			int i, j;
			
			n = random_number(50);
			for(i = 0; i < n; i++) {
				for(j = i; j < n; j++) {
					if ( i!=j ) {
						m[i][j] = m[j][i] = random_number(2);
					}

				}

			}
			display_matrix(n);
			printf("\n");

			rosenstiehl(n,0);

			for(i=0;i<nr;i++)
				printf("%d ",vec[i]+1);

			break;
		}
		
	}
}