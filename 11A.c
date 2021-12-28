#include <stdio.h>
#define MAX 100

int main(){
  int M[MAX][MAX],n,i,j,key,line,brige;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&key,&line);
    key--;//今回は二次配列が０から始まっていて０、１、２、３の４つで１、２、３、４がどの様に繋がっているかを表現するため、−１をして変換する必要がある。
    for(j=0;j<line;j++){
      scanf("%d",&brige);
      brige--;//今回は二次配列が０から始まっていて０、１、２、３の４つで１、２、３、４がどの様に繋がっているかを表現するため、−１をして変換する必要がある。
      M[key][brige]=1;
    }
  }

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(j==n-1){
	printf("%d\n",M[i][j]);
      }
      else{
	printf("%d ",M[i][j]);
      }
    }
  }
  
  return 0;
}
