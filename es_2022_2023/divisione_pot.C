#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int num, pot=0, ris;
	
	scanf("%d", &num);
	ris = pow(2, pot);

	//!contorllo
	while(num%ris==0){
		ris = pow(2, pot);
		pot+=1;
	}
	if(ris<0){
        ris--;
    }

    //!stampa
	printf("%d", pot);
	return 0;
}