#include<stdio.h> 
#include<math.h> 
#include<string.h> 
#include<locale.h> 
#include<stdlib.h> 
#include<ctype.h>

typedef struct{ 
	char nome[30];
	float n1;
	float n2;
	float n3;
	float media;
}Aluno;

int main(){
    setlocale(LC_ALL, "portuguese");	
	
	char c;
	int cont;
	Aluno p[8];
	int i=0;
	FILE *arq = fopen("entrada_q3.txt", "r");
	if(arq==NULL){ 
		printf("erro\n");
		exit(1);
	}
	else{ 
		printf("arquivo lido com sucesso\n");
		
		while(fscanf(arq, "%s %f %f %f", p[i].nome, &p[i].n1, &p[i].n2, &p[i].n3) != EOF){ 
			printf("%s\t%.1f\t%.1f\t%.1f\n", p[i].nome, p[i].n1, p[i].n2, p[i].n3);
			p[i].media = (p[i].n1 + p[i].n2 + p[i].n3)/3;
			cont++;
			i++;
	}
	}
	printf("numero de aluno é %d\n", cont);
	fclose(arq);
	
	FILE *t = fopen("saída_q3.txt", "w");
	if(t==NULL){ 
		printf("erro\n");
		exit(1);
	}
	
	
	for(i=0; i<cont; i++){ 
		if(p[i].media >= 7){ 
			fprintf(t, "%s\t%.1f\taprovado\n", p[i].nome, p[i].media);
		}
		else{ 
			fprintf(t, "%s\t%.1f\treprovado\n", p[i].nome, p[i].media);
		}
	}
	
	fclose(t);
	return 0;
}
