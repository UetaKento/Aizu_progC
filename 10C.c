#include <stdio.h>
#include <string.h>
#define M 1000
char c1[M],c2[M];
int lcs(int,int);
int maxcomp(int,int);

int main(){
  int n,i,s1,s2;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s %s",c1,c2);
    s1=strlen(c1);
    s2=strlen(c2);
    printf("%d\n",lcs(s1,s2));
  }
  return 0;
}

int lcs(int s1,int s2){
  int i,j,c[M][M],maxl=0;
  for(i=0;i<=s1;i++){
    c[i][0]=0;
  }
  for(j=1;i<=s2;j++){
    c[0][j]=0;
  }
  for(i=1;i<=s1;i++){
    for(j=1;j<=s2;j++){
      if(c1[i]==c2[j]){
	c[i][j]=c[i-1][j-1]+1;
	//printf("\n");
	printf("c[%d][%d]=%d\n",i,j,c[i][j]);
      }
      else{
	printf("c[%d][%d]=%d c[%d][%d]=%d\n",i-1,j,c[i-1][j],i,j-1,c[i][j-1]);
	c[i][j]=maxcomp(c[i-1][j],c[i][j-1]);
      }
      maxl=maxcomp(maxl,c[i][j]);
    }
  }
  return maxl;
}

int maxcomp(int a,int b){
  if(a>b){
    return a;
  }
  else{
    return b;
  }
}
/*
  #include <stdio.h>
  #include <string.h>
  #define M 1000;
  char c1[M],c2[M];
  int lcs(int,int);

  int main(){
  int n,i,s1,s2;
  char c1[M],c2[M];
  scanf("%d",&n);
  for(i=0;i<n;i++){
  scanf("%s %s"c1,c2);
  s1=strlen(c1);
  s2=strlen(c2);
  printf("%d\n",lcs(s1,s2));
  }
  return 0;
  }

  int lcs(int s1,int s2){
  int c[M][M],maxl;
  char X[M],Y[M];
  
  }
*/
