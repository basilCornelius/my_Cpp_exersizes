#include <stdio.h>
 
int main()
{
    int n;
    int i = 1;
    printf("input n:\n> ");
    scanf("%d", &n);
    
    while(n > 0){
        while(i <= n){
            printf("%d ", i);
            i++;
        }
        i = 1;
        n--;
        printf("\n");
    }
    
    return 0;
}