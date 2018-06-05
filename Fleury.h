
/**
* @file Fleury.h
* @brief This header file will contain all required
* definitions and basic utilities functions for Fleury algorithm.
*
* @author Pață Ionel-Daniel
*
* @date 1/6/2018
*/


#ifndef FLEURY_H_
#define FLEURY_H_

int n;
int b[100],finalPath[100];
char ajMat[100][100];
int fp;
int count;

int m[100][100];

void zero(int n);
int random_number(int n);
void display_matrix(int n);
void displayPath();
int getDegree(int node);
int findRoot();
int getIndex(int node);
int isLastNode(int node);
int getNextNode(int node);
int isHasOneEdge(int node);
int isCompleted();
void removeEdge(int root,int eNode);
void eularFind(int root);
void printbArray();
void citeste_matrice(int n);
#endif