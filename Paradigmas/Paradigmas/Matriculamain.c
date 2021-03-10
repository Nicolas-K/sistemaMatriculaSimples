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

    printf(" ooooooooooo                                    o888  oooo                              \n");
    printf(" 888    88   oooooooo8    ooooooo     ooooooo   888   888ooooo    ooooooo        ooo    \n");
    printf(" 888ooo8    888ooooooo  888     888 888     888 888   888   888   ooooo888       888    \n");
    printf(" 888    oo          888 888         888     888 888   888   888 888    888       ooo    \n");
    printf(" o888ooo8888 88oooooo88    88ooo888    88ooo88  o888o o888o o888o 88ooo88 8o     888    \n\n\n");


    printf("------------------------------------ \n");
	printf("| | 0 | - Sair                      | \n");
    printf("|                                   | \n");
	printf("| | 1 | - Cadastrar Aluno(s)        | \n");
	printf("|                                   | \n");
	printf("| | 2 | - Cadastrar Professor(es)   | \n");
	printf("|                                   | \n");
	printf("| | 3 | - Cadastrar Disciplina(s)   | \n");
	printf("|                                   | \n");
	printf("| | 4 | - Matricular Aluno(s)       | \n");
	printf("|                                   | \n");
	printf("| | 5 | - Matricular Professor(es)  | \n");
	printf("|                                   | \n");
	printf("| | 6 | - Remover ou desmatricular  | \n");
	printf("|                                   | \n");
	printf("| | 7 | - Impressões                | \n");
	printf("------------------------------------ \n");
}


int main() {
	setlocale(LC_ALL, "Portuguese");

	int opcaoMenu = -1;

	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("oooooooooo                                                            o88                     oooo          \n");
    printf("888    888  ooooooooo8 oo ooo oooo                       oooo   oooo oooo  oo oooooo    ooooo888   ooooooo   \n");
    printf("888oooo88   888oooooo8   888 888 888       ooooooooo       888   888   888   888   888 888    888 888     888  \n");
    printf("888    888  888          888 888 888                        888 888    888   888   888 888    888 888     888 \n");
    printf("o888ooo888    88oooo888 o888o888o888o                         888     o888o o888o o888o  88ooo888o  88ooo88 \n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");

    printf("\t\t\tSistema de Matrículas Puc Campinas\n\n");

    system ("pause");
    system("cls");

	while (opcaoMenu != 0) {

		printMenu();
		scanf("%d", &opcaoMenu);
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
    printf("------------------------------------\n");
	printf("| | 0 | - Voltar                     |\n");
    printf("|                                    |\n");
	printf("| | 1 | - Desmatricular Aluno(s)     |\n");
	printf("|                                    |\n");
	printf("| | 2 | - Desmatricular Professor(es)|\n");
	printf("|                                    |\n");
	printf("| | 3 | - Remover Aluno(s)           |\n");
	printf("|                                    |\n");
	printf("| | 4 | - Remover Professor(es)      | \n");
	printf("|                                    |\n");
	printf("| | 5 | - Remover Disciplina(s)      |\n");
	printf("------------------------------------\n");


                     opcaoMenu = -1;

                    while (opcaoMenu != 0) {
                        scanf("%d", &opcaoMenu);
                        system("cls");

                    switch (opcaoMenu) {


                    case 1: //desmatricularAluno();
                    break;

                    case 2://desmatricularProfessor();
                    break;

                    case 3://removerAluno();
                    break;

                    case 4: //removerProfessor();
                    break;

                    case 5://removerDisciplina();
                    break;
                    }
                    }

				break;

			case 7:
    printf("-------------------------------------------\n");
	printf("| | 0 | - Voltar                           |\n");
    printf("|                                          |\n");
	printf("| | 1 | - Listar Alunos                    |\n");
	printf("|                                          |\n");
	printf("| | 2 | - Listar Professores               |\n");
	printf("|                                          |\n");
	printf("| | 3 | - Listar Disciplinas(s)            |\n");
	printf("|                                          |\n");
	printf("| | 4 | - Listar Disciplinas do Aluno      |\n");
	printf("|                                          |\n");
	printf("| | 5 | - Listar Disciplinas do Professor  |\n");
	printf("|                                          |\n");
	printf("| | 6 | - Listar Alunos da Disciplina      |\n");
	printf("|                                          |\n");
	printf("| | 7 | - Listar Professores da Disciplina |\n");
	printf("-------------------------------------------\n");


				  opcaoMenu = -1;

                    while (opcaoMenu != 0) {
                        scanf("%d", &opcaoMenu);
                        system("cls");

                    switch (opcaoMenu) {


				case 1://listarAlunos();
				break;

				case 2://listarProfessores();
				break;

				case 3://listarDisciplinas();
				break;

				case 4://disciplinasDoAluno();
				break;

				case 5: //disciplinasDoProfessor();
				break;

				case 6: //alunosDaDisciplina();
				break;

				case 7://professoresDaDisciplina();
				break;
                    }
                    }




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
