#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <windows.h>
#include "Ros.h"

/** 
    * This method will be used to form the Eulerian cycle using  its Rosenstiehl algorithm
    * @param n - number of nodes in graph
    * @param u - current/start  node
    * @param v - some node 
*/ 



void rosenstiehl(int n,int u)
{
    int v; //nod oarecare

    st[++nr_st] = u; //adaug in stiva nodul de start/curent
    while(nr_st > 0) //cat timp stiva nu e vida
    {

        u = st[nr_st--]; //extrag ultimul element din stiva
        v = 0; //nodul oarecare este 0
        while (v < n) //cat timp nu am verificat toate nodurile
        {

            if (m[u][v] == 1) //verific daca exista muchie intre nodul u  si v
            {

                m[u][v] = 0; //sterg muchia dintre u si v
                m[v][u] = 0;
                st[++nr_st] = u; //adaug in stiva nodul u/add the node to the stack
                u = v; //nodul curent devine nodul v/the current node becomes node v
                v = 0;

            }
            else
                v++;
        }
         vec[nr++]=u; //se adauga nodul curent la ciclu/add the current node to the cycle

    }

}