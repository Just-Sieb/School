#include <stdio.h>

int main(){
    
    int temp = 0;
    
    for(int counter = 1; counter < 8; counter ++) {
        
        printf("What is the temperature going to be on day %d? ", counter);
        scanf("%d", &temp);
        
        if (temp <= 100 && temp >= 90) {
            printf("It's a scorcher! Turn on the air conditioning!\n");
        }
        else if (temp <= 89 && temp >= 80) {
            printf("Another hot day! Go for a swim!\n");
        }
        else if (temp <= 79 && temp >= 70) {
            printf("A good day to tend to your garden!\n");
        }
        else if (temp <= 69 && temp >= 60) {
            printf("Bring along a sweater today!\n");
            // Why would you bring a sweater at 60 degrees? This is not that cold.
        } 
        else if (temp <= 59 && temp >= 0) {
            printf("Stay inside and study C programming!\n");
        }  
        else {
            printf("I am sorry. I do not know what to do for that temperature so it must be pretty extreme weather!\n");
        }
        
    }
    
    return 0;
}