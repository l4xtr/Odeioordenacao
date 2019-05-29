#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define tam 8;

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

void insertionSort(struct Fabricante *vet, int n, int b, int c){
struct Fabricante aux;
	int i, a;
	for(i=b+c; i<n; i = i+c){
		aux = vet[i];
		a = i-c;
		while( (a>=b) && (strcmp(vet[a].nome, aux.nome) > 0)
        || (strcmp(vet[a].nome, aux.nome) == 0 && strcmp(vet[a].nacionalidade, aux.nacionalidade) > 0)
        || (strcmp(vet[a].nacionalidade, aux.nacionalidade) == 0 && vet[a].anoFabricacao > aux.anoFabricacao))
        {
        	vet[a+c] = vet[a];
        	a = a-c;
		}
		vet[a+c] = aux;
	}
}

int main(){
	int n=8;
	Fabricante fabricantes[8];
	lerDados(fabricantes);
	insertionSort(fabricantes, n);
	}
