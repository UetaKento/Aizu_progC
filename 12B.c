#include <stdio.h>
#define INF 1000000
#define MAX 100
#define W 0
#define G 1
#define B 2

int n,M[MAX][MAX];
void dik(void);

int main(){
  int i,j,k,c,u,v;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=INF;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d%d",&v,&c);
      M[u][v]=c;
    }
  }
  dik();
  return 0;
}

void dik(){
  int minv,i,u,v;
  int d[MAX],color[MAX];

  for(i=0;i<n;i++){
    d[i]=INF;
    color[i]=W;
  }
  d[0]=0;
  color[0]=G;
  while(1){
    minv=INF;
    u=-1;
    for(i=0;i<n;i++){
      if((minv>d[i])&&(color[i]!=B)){
	u=i;
	minv=d[i];
      }
    }
    if(u==-1){
      break;
    }
    color[u]=B;
    for(v=0;v<n;v++){
      if((color[v]!=B)&&(M[u][v]!=INF)){
	if(d[v]>d[u]+M[u][v]){
	  d[v]=d[u]+M[u][v];
	  color[v]=G;
	}
      }
    }
  }
  for(i=0;i<n;i++){
    if(d[i]==INF){
      printf("-1 ");
    }
    else{
      printf("%d ",d[i]);
    }
    printf("\n");
  }
}
/*
  #include <stdio.h>
  #define MAX 100
  #define INF 10000000
  #define W 0
  #define G 1
  #define B 2
  W,G,Bはcolor[v]を用いてvの訪問状態を表す
int prim(void);

int n,M[MAX][MAX];
M[u][v]はuからvへの辺の重みを記録する
int main(){
  int i,j,e;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      scanf("%d",&e);
      if(e==-1){
	M[i][j]=INF;
      }
      else{
	M[i][j]=e;
      }
    }
  }

  printf("%d\n",prim());
  
  return 0;
}

int prim(){
  int u,minv,i,v,sum;
  int color[MAX],d[MAX],p[MAX];
  color[v]はW,G,Bを用いてvの訪問状態を表す
    d[v]は頂点をつなぐ辺の中で、重みが最小の辺の重みを記録する
    p[v]は頂点vの親を記録する
  
初期化
  for(i=0;i<n;i++){
    d[i]=INF;
    p[i]=-1;
    color[i]=W;
  }
  d[0]=0;
  while(1){
    minv=INF;
    u=-1;
    for(i=0;i<n;i++){
      if((minv>d[i])&&(color[i]!=B)){
	u=i;
	minv=d[i];
      }
    }
    if(u==-1){
      break;
    }
    u=0の時はBに
    color[u]=B;
    for(v=0;v<n;v++){
      v=0の時はcolor[0]=Bで次のifは飛されるがforるーぷは回り、v=1の時、color[0]!=Bでifの条件に合い、d[v]>M[u][v]は辺の重みとINFで比べるので 
	d[v]=M[u][v];
	p[v]=u;
	color[v]=G;
	が実行される
      if((color[v]!=B)&&(M[u][v]!=INF)){ 
	if(d[v]>M[u][v]){
	  d[v]=M[u][v];
	  p[v]=u;
	  color[v]=G;
	}
      }
    }
  }
  sum=0;
  for(i=0;i<n;i++){
    if(p[i]!=-1){
      sum+=M[i][p[i]];
    }
  }
  return sum;
}

*/
