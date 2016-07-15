#include <stdio.h>

void calories(int, int *, int *, int *, int *);

int main()
{	
	int pizza = 0;
	int chips = 0;
	int apples = 0;
	int mustard = 0;
	int total = 0; 
	
	printf("\nHow many calories are you going to consume today? ");
	scanf("%f", &total);
	calories(total, &pizza, &chips, &apples, &mustard);
	
    printf("You can eat eat %d slices of pizza.\n", pizza);
    printf("You can eat eat %d bags of chips.\n", chips);
    printf("You can eat eat %d apples.\n", apples);
    printf("You can eat eat %d tsp of mustard.\n", mustard);    
	                   
    return 0;
}

void calories(int total, int *p, int *c, int *a, int *m)
{
	*p = total / 385;
	total = total - (*p * 385);
	
	*c = total / 170;
	total = total - (*c * 170);
	
	*a = total / 80;
	total = total - (*a * 80);
	
	*m = total / 5;
	
	return;
}