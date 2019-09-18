#include <stdio.h>

int main(int arc, char ** argv){
    int f = 1;

    while(f <= 1 || f > 18){
        printf("What Floor would You Like to go to? floors 1-18\n");
    scanf("%d",&f);
    
    if(f <= 1){
        printf("You are already on that floor\n");
    }else if(f > 18){
        printf("You can't go to that floor, 18 is the top\n");
    }
    }
    
    printf("Entered Floor is %d \n", f);



for(int i = 1; i < f; i++){

printf("Floors Passed: %d\n", i);


}
return 0;
}