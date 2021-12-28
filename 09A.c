#include<stdio.h>
#include<stdlib.h>

int main()
{
  int *A;
  int i,n,key;

  scanf("%d",&n);
  A = malloc(sizeof(int)*n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  printf("node 1: key = %d, left key = %d, right key = %d, \n",A[0],A[1],A[2]);
  for(i=1;i<n;i++){
    printf("node %d: key = %d, parent key = %d,",i+1,A[i],A[(i-1)/2]);
    if(i*2+1<n)printf(" left key = %d,",A[i*2+1]);
    if((i+1)*2<n)printf(" right key = %d,",A[(i+1)*2]);
    printf(" \n");
  }
  free(A);
  return 0;
}
