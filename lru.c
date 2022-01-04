#include <stdio.h>

int main() {
  //get the no. of entries
  printf("enter the number of entries : ");
  int n,i,j,a,k,m,l;
  scanf("%d", &n);
  printf("\n");

  //get the value of entries
  int arr[n];
  for ( i = 0; i<n; i++){
    printf("enter entry %d: ", i+1);
    scanf("%d", &arr[i]);
  }
  printf("\n");

  //get the size of buffer/register
  printf("enter the number of frames : ");
  int buf;
  scanf("%d", &buf);
  printf("\n");

  //fill the frames with -1 to indicate enpty places
  int buffer[buf];
  for ( i = 0; i<buf; i++){
    buffer[i] = -1;
  }

  //assign vars dummy1 to indicate the status of buffer(ie. one place in buffer empty OR one place in buffer is an element yo place OR no element in buffer is equal to the element to allocate)
  int dummy1, pos;

  //enter a for loop to cycle through all the elements
  for ( i = 0; i<n; i++){
    // for loop to check whether the element already exists in the buffer or a free place is there in the buffer or the element doesnot exist in the buffer
    for ( j = 0; j<buf; j++){
      if (buffer[j] == -1){
        dummy1 = -1;
        pos = j;
        break;
      }
      else if (buffer[j] == arr[i]){
        dummy1 = 1;
        break;
      }
      else{
        dummy1 = 0;
      }
    }

    //if dummy1 is -1 indicates there is a free place
    if (dummy1 == -1){
      printf("page fault\n");
      buffer[pos] = arr[i];
      printf("contents of buffer : \n");
      for ( a = 0; a<buf; a++){
        printf("%d\n", buffer[a]);
      }
      printf("\n");
    }

    //if dummy1 is 1 indicated there is a page hit
    else if (dummy1 == 1){
      printf("page hit\n");
      printf("contents of buffer : \n");
      for ( a = 0; a<buf; a++){
        printf("%d\n", buffer[a]);
      }
      printf("\n");
    }

    //if neither then page fault with no free slots in buffer therefore page replacement
    else{
      //alloate dummy2 as arbitary large number to compare the index position of elements in buffer in the actual entries given and dummy3 is to get the most rescent entry of the element of the buffer in the given entry
      int dummy2 = 999, dummy3;
      //for loop to cycle through the elements of the buffer
      for ( k = 0; k<buf; k++){
        //for loop to cycle through the elements of the entry till the point where the page fault is guessed
        for ( l = 0; l<=i; l++){
          //condition to save the most rescent entry of the element
          if (arr[l] == buffer[k]){
            dummy3 = l;
          }
        }
        //comparison to find the least rescent element
        if (dummy3 < dummy2){
          dummy2 = dummy3;
        }
      }
      
      printf("page fault\n");
      //loop to replace the elemet in the buffer
      for ( m = 0; m<buf; m++){
        if (buffer[m] == arr[dummy2]){
          buffer[m] = arr[i];
          break;
        }
      }
      printf("contents of buffer : \n");
      for ( a = 0; a<buf; a++){
        printf("%d\n", buffer[a]);
      }
      printf("\n");
    }
  }
}
