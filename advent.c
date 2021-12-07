#include <stdio.h>
#include <stdlib.h>
#include <stdint-gcc.h>


//// HULP FUNCTIES
void binaryRepresentation12bit(uint8_t word, uint8_t resultlist[12]) {
    for (int i = 0; i< 12; i++) {
        resultlist[11-i] = word >> i &1;
    }
}

int decimalRepresentation12Bits(int list[16]) {
    uint32_t word = 0;
    uint32_t divider = 2048;
    for(int i = 0; i < 12; i++ ) {
        if(list[i] == 1) {
            word = word + divider;
        }
        divider = divider/2;
    }
    return word;
}

//// OPDRACHTEN
void opdracht1(){
	uint32_t array[2000];
	FILE *fptr = fopen("input1.txt", "r"); 
	for(int i = 0; i<2000;i++) {
		int number;
		fscanf(fptr, "%d", &number); 
		array[i] = number;
	}
	
	int counter = 0;
	for(int i = 1; i<2000 ; i ++) {
		if (array[i-1] < array[i]) {
			counter ++;
		}
	}
	printf("het resultaat is %d", counter);
	int counter2 = 0; 
	for(int i = 1; i<1998; i++) {
		int result1 = array[i-1]; 
		int result2 = array[i];
		int result3 = array[i+1];
		int result4 = array[i+2];
		if( (result1 + result2 + result3) < (result2+result3+result4)) {
			counter2++;
		}
	}
	printf("het resultaat voor puzzel2 is %d", counter2);
	
}

void opdracht2() {
	FILE *fptr = fopen("input2.txt", "r"); 
	int richting = 0;
	int diepte = 0; 
	int aim = 0;
	for(int i = 0; i<1000;i++) {
		char direction[20]; 
		int number;
		fscanf(fptr, "%s %d", direction, &number); 
		//printf("%c %d \n" , direction[0], number);
		if(direction[0] == 'd') {
			aim = aim + number;
		}
		if(direction[0] == 'f') {
			richting = richting + number;
			diepte = diepte + (aim*number);
		}
		if(direction[0] == 'u') {
			aim =  aim - number;
		}
		 //printf("%d", diepte); 
	}
	int result = diepte*richting; 
	printf("het resultaat is:%d", result);
	fclose(fptr); 

}

void opdracht3() {
	FILE *fptr = fopen("input3.txt", "r+");
	uint32_t chs = fgetc(fptr);
	int bits[12] = {0};
	int reversebits[12] = {0};
	int index = 0;

	while(chs != EOF ) {
		if(chs == '\n') {
			index =0;
			chs = fgetc(fptr);
			continue;
		}
		if (chs == '0') {
			bits[index] = bits[index]-1;                 
		} 
		if (chs == '1') {
			bits[index] = bits[index]+1;             
		}
		index++;
		chs = fgetc(fptr);
	}
	for (int i = 0; i<12; i++ ) {
		if(bits[i] < 0) {
			bits[i] = 0;
			reversebits[i] = 1;
		}
		else {
			bits[i] = 1; 
			reversebits[i] = 0;
		}			
	}
	int waarde1 = decimalRepresentation12Bits(bits);
	int waarde2 = decimalRepresentation12Bits(reversebits);
	printf("het resultaat is %d", waarde1*waarde2); 
}

void opdracht3b() {
	FILE *fptr = fopen("input3.txt", "r+");
	uint32_t chs = fgetc(fptr);
	int input[12][1000];
	int index = 0;
	for(int i = 0; i<1000; i++) { 
		if(chs == '\n') {
			index =0;
			chs = fgetc(fptr);
			continue;
		}
		if (chs == '0') {
			input[index][i] = 0;                 
		} 
		if (chs == '1') {
			input[index][i] = 1;
		} 
		index++;
		chs = fgetc(fptr); 
	}
	
	
	int waarde1 = decimalRepresentation12Bits(bits);
	int waarde2 = decimalRepresentation12Bits(reversebits);
	printf("het resultaat is %d", waarde1*waarde2); 

}
int main () {
	//opdracht1(); 
	//opdracht2();
	//opdracht3();
	opdracht3b();
	return 0;
}