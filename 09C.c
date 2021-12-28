#include <stdio.h>
#define MAX 2000000

int H,A[MAX+1];
void insert(int);
void heapinc(int,int);
int heapext(void);
void maxHeapify(int);

int main(){
  int x;
  char com[20];
  while(1){
    scanf("%s", com);
    if ( com[0] == 'i' ){
      scanf("%d", &x);
      insert(x);
    }
    else if (( com[0] == 'e' )&&(com[1] == 'n')){
      break;
    }
    else{

    }
  }
  return 0;
}
void insert(int key){
  H++;
  A[H]=-MAX;//新しく入れるkeyが一番最後のkey以上のときのみ、heapの変更が行われることを保証している。
  heapinc(H,key);
}
void heapinc(int i,int key){
  int c;
  if(key<A[i]){
    return;
  }
  A[i]=key;
  while((i>1)&&(A[i/2]<A[i])){
    c=A[i/2];
    A[i/2]=A[i];
    A[i]=c;
    i=i/2;
  }
}

int heapext(){
  int maxv;
  if(H<1){
    return -MAX;
  }
  maxv=A[1];
  A[1]=A[H--];
  maxHeapify(1);
  return maxv;
}

void maxHeapify(int i){
  int l,r,largest,change=0;
  l = 2*i;
  r = 2*i+1;
  // 左の子、自分、右の子で値が最大のノードを選ぶ
  if ((l <= H)&&(A[l] > A[i])){
    largest = l;
  }
  else{
    largest = i;
  }
  if ((r <= H )&& (A[r] > A[largest])){
    largest = r;
  }

  if (largest != i)/* i の子の方が値が大きい場合 */{
    //A[i] と A[largest] を交換
    change=A[i];
    A[i]=A[largest];
    A[largest]=change;
    maxHeapify(largest); // 再帰的に呼び出し
  }
}

/*
  #include <stdio.h>
#define MAX 500000

int A[MAX],H;
void maxHeapify(int);

int main()
{
  int i;
  scanf("%d",&H);
  for(i=1;i<=H;i++)
    {
      scanf("%d",&A[i]);
    }
  for(i=H/2;i>=1;i--)
    {
      maxHeapify(i);
    }
  for(i=1;i<=H;i++)
    {
      printf(" %d",A[i]);
    }
  printf("\n");
  return 0;
}

void maxHeapify(int i)
{
  int l,r,largest,change=0;
  l = 2*i;
  r = 2*i+1;
  // 左の子、自分、右の子で値が最大のノードを選ぶ
  if ((l <= H)&&(A[l] > A[i]))
    {
      largest = l;
    }
  else
    {
      largest = i;
    }
  if ((r <= H )&& (A[r] > A[largest]))
    {
      largest = r;
    }

  if (largest != i)// i の子の方が値が大きい場合
    {
      //A[i] と A[largest] を交換
      change=A[i];
      A[i]=A[largest];
      A[largest]=change;
      maxHeapify(largest); // 再帰的に呼び出し
    }
}

  else if (( com[0] == 'e' )&&(com[1] == 'n'))
    {
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    }
 */
