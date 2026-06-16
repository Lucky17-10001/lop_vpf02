#include <stdio.h>
#include <windows.h>

#define MAX_LETRAS 100
#define MAX_LINHAS 50

struct Funcionario{
	char nome[50];
	char cargo[100];
	float salario;
};

int main(){
	SetConsoleOutputCP(CP_UTF8);
	int qtdLinhas = 0;
	struct Funcionario funcionarios[MAX_LINHAS];
	FILE *arquivo = fopen("funcionarios.csv","r");
	if(arquivo == NULL){
		printf("Arquivo não encontrado.\n");
		getch();
		return 0;
	}
	char linha[MAX_LETRAS];
	while(fgets(linha,sizeof(linha),arquivo) != NULL && qtdLinhas < MAX_LINHAS){
		linha[strcspn(linha,"\n")] = '\0';
		qtdLinhas++;
		
		if(qtdLinhas > 1){
			sscanf(linha,"%49[^,],%99[^,],%f\n",
			funcionarios[qtdLinhas - 2].nome,
			funcionarios[qtdLinhas - 2].cargo,
			&funcionarios[qtdLinhas - 2].salario
			);
		}
	
	}
	fclose(arquivo);
	
	double media = 0;
	printf("Nome\tCargo\tSalário\n");
	for(int i = 0; i < qtdLinhas - 1; i++){
		printf("%s\t%s\t%.2f\n",funcionarios[i].nome, funcionarios[i].cargo, funcionarios[i].salario);
		media += funcionarios[i].salario;
	}
	media = media / (float)(qtdLinhas - 1);
	printf("\nForam analizados %d funcionários\n", qtdLinhas - 1);
	printf("A média salarial da empresa é de %.1f reais.\n", media);
	getch();
}