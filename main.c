#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Fabricante{
	char nome[50];
	char nacionalidade[20];
	int anoFabricacao;
}Fabricante;

void lerDados(struct Fabricante *fabricantes){
	
	strcpy(fabricantes[0].nome,"Felipe");
	strcpy(fabricantes[0].nacionalidade,"Brasil");
	fabricantes[0].anoFabricacao = 2010;
	
	strcpy(fabricantes[1].nome,"Martins");
	strcpy(fabricantes[1].nacionalidade,"Italia");
	fabricantes[1].anoFabricacao = 2011;
	
	strcpy(fabricantes[2].nome,"Italo");
	strcpy(fabricantes[2].nacionalidade,"Estados Unidos");
	fabricantes[2].anoFabricacao = 2012;
	
	strcpy(fabricantes[3].nome,"Vitor");
	strcpy(fabricantes[3].nacionalidade,"Azerbaijao");
	fabricantes[3].anoFabricacao = 2013;
	
	strcpy(fabricantes[4].nome,"Gustavo");
	strcpy(fabricantes[4].nacionalidade,"Espanha");
	fabricantes[4].anoFabricacao = 2014;
	
	strcpy(fabricantes[5].nome,"Silvana");
	strcpy(fabricantes[5].nacionalidade,"Portugal");
	fabricantes[5].anoFabricacao = 2015;
	
	strcpy(fabricantes[6].nome,"Giovanny");
	strcpy(fabricantes[6].nacionalidade,"Islandia");
	fabricantes[6].anoFabricacao = 2016;
	
	strcpy(fabricantes[7].nome,"IFES");
	strcpy(fabricantes[7].nacionalidade,"Noruega");
	fabricantes[7].anoFabricacao = 2017;
	
	strcpy(fabricantes[8].nome,"Colatina");
	strcpy(fabricantes[8].nacionalidade,"Suecia");
	fabricantes[8].anoFabricacao = 2018;
}

/*void insertionSort(struct Fabricante *vet, int cont){
	struct Fabricante aux;
	int i, j;
	for(i=1; i<cont; i++){
		aux = vet[i];
		j = i - 1;
		while( (j>=0) && (strcmp(vet[j].nome, aux.nome) > 0)
        || (strcmp(vet[j].nome, aux.nome) == 0 && strcmp(vet[j].nacionalidade, aux.nacionalidade) > 0)
        || (strcmp(vet[j].nacionalidade, aux.nacionalidade) == 0 && vet[j].anoFabricacao > aux.anoFabricacao))
        {
        	vet[j+1] = vet[j];
        	j = j-1;
		}
		vet[j+1] = aux;
	}
}*/

void insertionSortAdaptado(struct Fabricante *vet, int cont, int f, int h){
struct Fabricante aux;
	int j, i;
	for(i=f+h; i<cont; i = i+h){
		aux = vet[i];
		j = i-h;
		while( (j>=f) && (strcmp(vet[j].nome, aux.nome) > 0)
        || (strcmp(vet[j].nome, aux.nome) == 0 && strcmp(vet[j].nacionalidade, aux.nacionalidade) > 0)
        || (strcmp(vet[j].nacionalidade, aux.nacionalidade) == 0 && vet[j].anoFabricacao > aux.anoFabricacao))
        {
        	vet[j+h] = vet[j];
        	j = j-h;
		}
		vet[j+h] = aux;
	}
}

void shellSort(struct Fabricante *vet, int cont, int np)
{
	int h, p, j;
	for(p = np; p>0; p--){
		h = (int) pow(2, (int) p-1);
		for(j=0; j<h; j++)
			insertionSortAdaptado(vet, cont, j, h);
}
}

void imprimeDados(struct Fabricante *vet, int cont){
	int i;
	for(i=0; i<cont; i++){
		printf(" Nome do Fabricante: %s \n", vet[i].nome);
		printf(" Nacionalidade do Fabricante: %s \n", vet[i].nacionalidade);
		printf(" Ano de Abertura: %d \n\n", vet[i].anoFabricacao);
	}
}

int main(){
	int cont=8;
	Fabricante fabricantes[8];
	lerDados(fabricantes);
	//insertionSort(fabricantes, cont);
	shellSort(fabricantes, cont, 2);
	imprimeDados(fabricantes, cont);
	return 0;
	}
