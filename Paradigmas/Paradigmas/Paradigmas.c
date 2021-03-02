#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct {
	char Nome[30];
	int RA;
} Aluno;

typedef struct {
	char Nome[30];
	int RP;
} Professor;

void cadastrarAluno();
void cadastrarProfessor();
void cadastrarDisciplina();

void matricularAluno();
void matricularProfessor();

void desmatricularAluno();
void desmatricularProfessor();

void removerAluno();
void removerProfessor();
void removerDisciplina();

void listarAlunos();
void listarProfessores();
void listarDisciplinas();

void disciplinasDoAluno();
void disciplinasDoProfessor();

void alunosDaDisciplina();
void professoresDaDisciplina();

void printMenu() {
	printf("0  - Sair\n");
	printf("1  - Cadastrar Aluno(s)\n");
	printf("2  - Cadastrar Professor(es)\n");
	printf("3  - Cadastrar Disciplina(s)\n");

	printf("4  - Matricular Aluno(s)\n");
	printf("5  - Matricular Professor(es)\n");

	printf("6  - Desmatricular Aluno(s)\n");
	printf("7  - Desmatricular Professor(es)\n");

	printf("8  - Remover Aluno(s)\n");
	printf("9  - Remover Professor(es)\n");
	printf("10 - Remover Disciplina(s)\n");

	printf("11 - Listar Alunos\n");
	printf("12 - Listar Professores\n");
	printf("13 - Listar Disciplinas\n");

	printf("14 - Listar Disciplinas do Aluno\n");
	printf("15 - Listar Disciplinas do Professor\n");

	printf("16 - Listar Alunos da Disciplina\n");
	printf("17 - Listar Professores da Disciplina\n");
}


int main() {
	setlocale(LC_ALL, "Portuguese");

	int opcaoMenu = -1;

	while (opcaoMenu != 0) {

		printMenu();
		scanf_s("%d", &opcaoMenu);
		system("cls");

		switch (opcaoMenu) {
			case 0:
				printf("Obrigado por utilizar o sistema! :)\n");
				break;

			case 1:
				//cadastrarAluno();
				break;

			case 2:
				//cadastrarProfessor();
				break;

			case 3:
				//cadastrarDisciplina();
				break;

			case 4:
				//matricularAluno();
				break;

			case 5:
				//matricularProfessor();
				break;

			case 6:
				//desmatricularAluno();
				break;

			case 7:
				//desmatricularProfessor();
				break;

			case 8:
				//removerAluno();
				break;

			case 9:
				//removerProfessor();
				break;

			case 10:
				//removerDisciplina();
				break;

			case 11:
				//listarAlunos();
				break;

			case 12:
				//listarProfessores();
				break;

			case 13:
				//listarDisciplinas();
				break;

			case 14:
				//disciplinasDoAluno();
				break;

			case 15:
				//disciplinasDoProfessor();
				break;

			case 16:
				//alunosDaDisciplina();
				break;

			case 17:
				//professoresDaDisciplina();
				break;

			default:
				printf("Opção Inválida!\nPor favor, escolha novamente.\n");
				system("PAUSE");
				system("cls");
				break;
		}
	}

	system("PAUSE");
	return(0);
}