#include <stdio.h>
#define MAX 2000000

int h,a[MAX+1];

void maxHeapify(int i)
{
  int l,r,largest;
  int oki;
 
  l = 2 * i ;
  r = 2 * i + 1;

  if(l<=h && a[l] >a[i])largest=l;
  else largest = i;
  if(r <=h && a[r] > a[largest]) largest = r;

  if(largest != i){
    oki = a[i];
    a[i] = a[largest];
    a[largest] = oki;
    maxHeapify(largest);
  }
}
int main()
{
  int i;
  scanf("%d",&h);

  for(i=1;i<=h;i++) scanf("%d",&a[i]);

  for(i=h/2;i>=1;i--) maxHeapify(i);

  for(i=1;i<=h;i++){
    printf(" %d",a[i]);
  }
  printf("\n");

  return 0;
}
