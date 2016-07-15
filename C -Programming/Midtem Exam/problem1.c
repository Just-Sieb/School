#include <stdio.h>
#define STAMP_COST 0.37

int main(){
    
    int envelopes = 0;
    float cost = 0;
    
    printf("How many envelopes do you need? ");
    scanf("%d", &envelopes);
    
    cost = envelopes * STAMP_COST;
    
    printf("You need %.2f dollars worth of stamps\n", cost);
    
    return 0;
}

