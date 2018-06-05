#include "Fleury.h"
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>


/** 
   * This function will be used to allocate the matrix m[i][j] value 0
   * @author Pață Ionel-Daniel
   * @param n - number of nodes in graph
*/

void zero(int n)
{
    int i,j;

     for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        m[i][j]=0;
    }
}

/** 
   * This function will be used to intialized random numbers
   * @author Pață Ionel-Daniel
   * @param a - random number
*/     	 
int random_number(int n)
{
   int a;
	//time_t t;
   
   //srand((unsigned) time(&t));
    a=rand() % n;

   return a;
   }

/** 
   * This function will be used to display the matrix
   * @param n - number of nodes in graph 
   */
//display the matrix
void display_matrix(int n)
{
    int i,j;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
		{
			printf("%d ",m[i][j]);
		    Sleep(70);
		}

        printf("\n");
    }
}

/** 
   * This function will be used to display the Euler circuit/path 
 */


//Display the Euler circuit/path
void displayPath()
{
     int i;
     for(i=1;i<fp;i++)
     {
       if(i<fp-1) printf("%d -> ",finalPath[i]);
       else printf("%d",finalPath[i]);
	   Sleep(300);
     }
}
/** 
   * This function will be used to get the current index of node in the array b[] of nodes
   * @param node-current node
   * 
 */

//To get the current index of node in the array b[] of nodes
int getIndex (int node)
{
    int k=0;
    while(node!=b[k])
    k++;
     //printf("inside while\n");

    //l++;
    return k;
}

/** 
   * This function will be used to get the degree of node i.e no of edges currently connected to the node
   */
   
//To get the degree of node i.e no of edges currently connected to the node
int getDegree (int node)
{
    int j,deg=0;
    int pos=getIndex(node);
    for(j=1;j<=n;j++)
    {
      if(ajMat[pos][j]=='y') deg++;
    }
    return deg;
}

/**
  * To assign the root of the graph
  * Condition 1: If all Nodes have even degree, there should be a euler Circuit/Cycle
  * We can start path from any node
  * Condition 2: If exactly 2 nodes have odd degree, there should be euler path.
  * We must start from node which has odd degree
  * Condition 3: If more than 2 nodes or exactly one node have odd degree, euler path/circuit not possible.

  * findRoot() will return 0 if euler path/circuit not possible
  *  otherwise it will return array index of any node as root
  */

/** 
    * This function will return 0 if euler path/circuit not possible
    * @author Pață Ionel-Daniel
	* @date 1/6/2018
	*/
	
	
int findRoot()
{

     int i,cur=1;//Assume root as 1
     for(i=1;i<=n;i++)
     {
        if(getDegree(b[i])%2!=0)
        {
           count++;
           cur=i;//Store the node which has odd degree to cur variable
        }
     }
     //If count is not exactly 2 then euler path/circuit not possible so return 0
     if(count!=0 && count!=2)
     {
        return 0;
     }
     else return b[cur];// if exactly 2 nodes have odd degree, it will return one of those node as root otherwise return 1 as root  as assumed
}


int isLastNode(int node)
{
    int i=0;
    int degSum=0;
    for(i=0;i<n;i++)
    {
     degSum=degSum+getDegree(b[i]);
    }
    if(degSum==2)
      return 1;
    else
      return 0;
}
int isHasOneEdge(int node)
{
    if(getDegree(node)==1)
      return 1;
    else
      return 0;
}

int getNextNode(int node)
{
    int i=0;
    int pos=getIndex(node);

    for(i=1;i<=n;i++)
    {
      if(ajMat[pos][i]=='y')
      {
        if(!isHasOneEdge(b[i]))
        {
          return b[i];
        }
        else
        {
            if(isLastNode(b[i]))
            return b[i];
        }
      }
    }
    return -1;
}



int isCompleted()
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(getDegree(b[i])>0)
             return 0;
    }
    return 1;
}
/** 
  * This function will be used  to remove the edge 
  * @author Pață Ionel-Daniel
  * @param root - is root node
  
  */
void removeEdge(int root,int eNode)
{
     int pos1=0,pos2=0;
     pos1=getIndex(root);
     pos2=getIndex(eNode);
     ajMat[pos1][pos2]='n';
     ajMat[pos2][pos1]='n';
}

/**
    *  This function will be used to find the Euler circuit/path and store it in finalPath[] array
	* @author Pață Ionel-Daniel
	* @param root - is root
*/	
	
	
//To find the Euler circuit/path and store it in finalPath[] array
void eularFind(int root)
{
     int eNode;
     while(!isCompleted())
     {
        eNode=getNextNode(root);   //get Next node
        finalPath[fp++]=eNode;     //add the node to euler path
        removeEdge(root,eNode);   //remove the edge
        root=eNode; //change the root
     }
    /* printf("root=%d\n",root);
        eNode=getNextNode(root);
        printf("getNextNode=%d \n",eNode);
        finalPath[fp++]=eNode;
        removeEdge(root,eNode);
        root=eNode;*/
}

/**
    *  This function will be used to store the nodes in b[] array
	*  @author Pață Ionel-Daniel
*/

	
void printbArray()
{
     int i;
      for( i=1; i<=n; i++)
    {
     printf("%d  ",b[i]);//store the nodes in b[] array
    }
}
/** 
   * This function will be used for to read the matrix 
   * @author  Pață Ionel-Daniel
   * @param n - is the number of nodes
   */

void citeste_matrice(int n)
{
        int i,j;

     for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
       scanf("%d ",&m[i][j]);
    }
}
