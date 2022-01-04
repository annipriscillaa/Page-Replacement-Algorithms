#include <stdio.h>

int main() {
  printf("enter the number of entries : ");
  int n;
  scanf("%d", &n);
  printf("\n");

  int arr[n];
  for (int i = 0; i<n; i++){
    printf("enter entry %d: ", i+1);
    scanf("%d", &arr[i]);
  }
  printf("\n");

  printf("enter the size of buffer : ");
  int buf;
  scanf("%d", &buf);
  printf("\n");

  int buffer[buf];
  for (int i = 0; i<buf; i++){
    buffer[i] = -1;
  }

  int dummy1, pos;

  for (int i = 0; i<n; i++){
    for (int j = 0; j<buf; j++){
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

    if (dummy1 == -1){
      printf("page fault\n");
      buffer[pos] = arr[i];
      printf("contents of buffer : \n");
      for (int a = 0; a<buf; a++){
        printf("%d\n", buffer[a]);
      }
      printf("\n");
    }

    else if (dummy1 == 1){
      printf("page hit\n");
      printf("contents of buffer : \n");
      for (int a = 0; a<buf; a++){
        printf("%d\n", buffer[a]);
      }
      printf("\n");
    }
    else{
      int dummy2 = 0, dummy3 = 999;
      for (int k = 0; k<buf; k++){
        for (int l = i; l<n; l++){
          if (arr[l] == buffer[k]){
            dummy3 = l;
            break;
          }
        }
        if (dummy3 == 999){
          dummy2 = k;
          printf("page fault\n");
          buffer[dummy2] = arr[i];
          printf("contents of buffer : \n");
          for (int a = 0; a<buf; a++){
            printf("%d\n", buffer[a]);
          }
          printf("\n");
          goto loop_breaker;
        }
        else if (dummy3 > dummy2){
          dummy2 = dummy3;
          dummy3 = 999;
        }
      }
      
      printf("page fault\n");
      for (int m = 0; m<buf; m++){
        if (buffer[m] == arr[dummy2]){
          buffer[m] = arr[i];
        }
      }
      printf("contents of buffer : \n");
      for (int a = 0; a<buf; a++){
        printf("%d\n", buffer[a]);
      }
      printf("\n");

      loop_breaker:
        continue;
    }
  }
}
