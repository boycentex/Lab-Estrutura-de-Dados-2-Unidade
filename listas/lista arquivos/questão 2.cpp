#include<stdio.h> 
#include<math.h> 
#include<string.h> 
#include<locale.h> 
#include<stdlib.h> 
#include<ctype.h>



int main(){
    setlocale(LC_ALL, "portuguese");	
	
	
	int i=0;
	int v[10];
	
	FILE *arq = fopen("numeros.txt", "r");
	if(arq==NULL){ 
		printf("erro\n");
		exit(1);
	}
	else{ 
		printf("arquivo lido com sucesso\n");
		
		while(fscanf(arq, "%d", &v[i]) != EOF){ 
			printf("%d\n", v[i]);
			i++;
	}
	}
	fclose(arq);
	FILE *t = fopen("saida.txt", "w");
	float soma;
	int maior, menor = v[0]; 
	for(i=0; i<10; i++){ 
		if(maior < v[i]){ 
			maior = v[i];
		}
		if(menor > v[i]){ 
			menor = v[i];
		}
		soma += v[i];
	}
	fprintf(t, "menor elemento: %d\n", menor);
	fprintf(t, "maior elemento: %d\n", maior);
	fprintf(t, "media dos elementos é %.2f\n", soma/10);
	fclose(t);
	
	return 0;
}
