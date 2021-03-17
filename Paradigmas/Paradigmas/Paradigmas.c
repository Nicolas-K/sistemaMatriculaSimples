//*********************************
//
// Nícolas Leonardo Külzer Kupka
// RA: 16104325
//
// Rafaela Medina
// RA: 
// 
//**********************************

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

#define TAMANHO_MAX_NOMES 30

#define QUANTIDADE_MAX_ALUNOS_NA_ESCOLA 500
#define QUANTIDADE_MAX_PROFESSORES_NA_ESCOLA 250
#define QUANTIDADE_MAX_DISCIPLINAS_NA_ESCOLA 100

#define QUANTIDADE_MAX_ALUNOS_MATRICULADOS 50
#define QUANTIDADE_MAX_PROFESSORES_MATRICULADOS 6

typedef struct {
	char Nome[TAMANHO_MAX_NOMES];
	int RA;
} Aluno;
typedef struct {
	char Nome[TAMANHO_MAX_NOMES];
	int RP;
} Professor;
typedef struct {
	char Nome[TAMANHO_MAX_NOMES];
	int ID;
	Aluno alunosMatriculados[QUANTIDADE_MAX_ALUNOS_MATRICULADOS];
	int ponteiroAlunosMatriculados;
	Professor professoresMatriculados[QUANTIDADE_MAX_PROFESSORES_MATRICULADOS];
	int ponteiroProfessoresMatriculados;
} Disciplina;

void myfflush() {
	while (getchar() != '\n');
}

int retornaIndexAlunoNaDisciplina(Aluno aluno, Disciplina disciplina) {
	int index;

	for (index = 0; index <= disciplina.ponteiroAlunosMatriculados; index++) {
		if (strcmp(aluno.Nome, disciplina.alunosMatriculados[index].Nome) == 0) {
			return index;
		}
	}
	return (-1);
}
int retornaIndexProfessorNaDisciplina(Professor professor, Disciplina disciplina) {
	int index;

	for (index = 0; index <= disciplina.ponteiroProfessoresMatriculados; index++) {
		if (strcmp(professor.Nome, disciplina.professoresMatriculados[index].Nome) == 0) {
			return index;
		}
	}
	return (-1);
}

Aluno cadastrarAluno(int contadorAlunos) {
	Aluno alunoDummy;

	char nome[32];
	int tamanhoNome = TAMANHO_MAX_NOMES;

	printf("------------------------------------- \n");
	printf("|             Ficha A%.3d            | \n", contadorAlunos);
	printf("|                                   | \n");

	do {
		printf("| | Nome | - ");
		fgets(nome, sizeof(nome), stdin);
		_strupr_s(nome, sizeof(nome));
		tamanhoNome = strlen(nome);

		if (tamanhoNome > TAMANHO_MAX_NOMES-1) {
			printf("| [ERRO] O 'Nome' pode ter até %d caracteres! Por favor, digite novamente.\n", TAMANHO_MAX_NOMES-1);
			myfflush();
		}
		else {
			strcpy_s(alunoDummy.Nome, sizeof(alunoDummy.Nome), nome);
		}
	} while (tamanhoNome > TAMANHO_MAX_NOMES-1);

	if (strcmp(alunoDummy.Nome, "0\n") != 0) {

		alunoDummy.RA = contadorAlunos;

		printf("|                                   | \n");
		printf("| |  RA  | - %.3d                    | \n", alunoDummy.RA);
				
	}
	else {
		printf("------------------------------------- \n\n");
	}

	return alunoDummy;
}
Professor cadastrarProfessor(int contadorProfessores) {
	Professor professorDummy;

	char nome[32];
	int tamanhoNome = TAMANHO_MAX_NOMES;

	printf("------------------------------------- \n");
	printf("|             Ficha P%.3d            | \n", contadorProfessores);
	printf("|                                   | \n");

	do {
		printf("| | Nome | - ");
		fgets(nome, sizeof(nome), stdin);
		_strupr_s(nome, sizeof(nome));
		tamanhoNome = strlen(nome);

		if (tamanhoNome > TAMANHO_MAX_NOMES-1) {
			printf("| [ERRO] O 'Nome' pode ter até %d caracteres! Por favor, digite novamente.\n", TAMANHO_MAX_NOMES-1);
			myfflush();
		}
		else {
			strcpy_s(professorDummy.Nome, sizeof(professorDummy.Nome), nome);
		}
	} while (tamanhoNome > TAMANHO_MAX_NOMES);

	if (strcmp(professorDummy.Nome, "0\n") != 0) {

		professorDummy.RP = contadorProfessores;

		printf("|                                   | \n");
		printf("| |  RP  | - %.3d                    | \n", professorDummy.RP);

	}
	else {
		printf("------------------------------------- \n\n");
	}

	return professorDummy;
}
Disciplina cadastrarDisciplina(int contadorDisciplinas) {
	Disciplina disciplinaDummy;

	char nome[32];
	int tamanhoNome = TAMANHO_MAX_NOMES;

	printf("------------------------------------- \n");
	printf("|             Ficha D%.3d            | \n", contadorDisciplinas);
	printf("|                                   | \n");

	do {
		printf("| | Nome | - ");
		fgets(nome, sizeof(nome), stdin);
		_strupr_s(nome, sizeof(nome));
		tamanhoNome = strlen(nome);

		if (tamanhoNome > TAMANHO_MAX_NOMES-1) {
			printf("| [ERRO] O 'Nome' pode ter até %d caracteres! Por favor, digite novamente.\n", TAMANHO_MAX_NOMES-1);
			myfflush();
		}
		else {
			strcpy_s(disciplinaDummy.Nome, sizeof(disciplinaDummy.Nome), nome);
		}
	} while (tamanhoNome > TAMANHO_MAX_NOMES-1);

	if (strcmp(disciplinaDummy.Nome, "0\n") != 0) {

		disciplinaDummy.ID = contadorDisciplinas;

		printf("|                                   | \n");
		printf("| |  ID  | - %.3d                    | \n", disciplinaDummy.ID);

		disciplinaDummy.ponteiroAlunosMatriculados = -1;
		disciplinaDummy.ponteiroProfessoresMatriculados = -1;
	}
	else {
		printf("------------------------------------- \n\n");
	}

	return disciplinaDummy;
}

Disciplina matricularAluno(int indexAluno, int indexDisciplina, Aluno vetorAlunos[], Disciplina vetorDisciplinas[]) {
	Aluno alunoDummy;
	Disciplina disciplinaDummy;
	int index;

	alunoDummy = vetorAlunos[indexAluno];
	disciplinaDummy = vetorDisciplinas[indexDisciplina];

	disciplinaDummy.ponteiroAlunosMatriculados++;
	if (disciplinaDummy.ponteiroAlunosMatriculados > QUANTIDADE_MAX_ALUNOS_MATRICULADOS-1) {
		printf("[ERRO] Sala cheia! A sala já possuí %d Alunos. Favor, criar outra sala para a disciplina.\n", QUANTIDADE_MAX_ALUNOS_MATRICULADOS);
	}
	else {
		disciplinaDummy.alunosMatriculados[disciplinaDummy.ponteiroAlunosMatriculados] = alunoDummy;
	}	
	return disciplinaDummy;
}
Disciplina matricularProfessor(int indexProfessor, int indexDisciplina, Professor vetorProfessores[], Disciplina vetorDisciplinas[]) {
	Professor professorDummy;
	Disciplina disciplinaDummy;
	int index;

	professorDummy = vetorProfessores[indexProfessor];
	disciplinaDummy = vetorDisciplinas[indexDisciplina];

	disciplinaDummy.ponteiroProfessoresMatriculados++;
	if (disciplinaDummy.ponteiroProfessoresMatriculados > QUANTIDADE_MAX_PROFESSORES_MATRICULADOS-1) {
		printf("[ERRO] Sala cheia! %d professores já estão ministrando. Favor, criar outra sala para a disciplina.\n", QUANTIDADE_MAX_PROFESSORES_MATRICULADOS);
	}
	else {
		disciplinaDummy.professoresMatriculados[disciplinaDummy.ponteiroProfessoresMatriculados] = professorDummy;
	}
	return disciplinaDummy;
}

Disciplina desmatricularAluno(int indexAluno, int indexDisciplina, Aluno vetorAlunos[], Disciplina vetorDisciplinas[], bool showError) {
	Aluno alunoDummy;
	Disciplina disciplinaDummy;
	int index;
	int indexAlunoEncontrado;

	alunoDummy = vetorAlunos[indexAluno];
	disciplinaDummy = vetorDisciplinas[indexDisciplina];

	indexAlunoEncontrado = retornaIndexAlunoNaDisciplina(alunoDummy, disciplinaDummy);

	if (indexAlunoEncontrado == -1) {
		if (showError == true) printf("| [ERRO] Aluno não matriculado na Disciplina!\n");
	} else {
		for (index = indexAlunoEncontrado; index <= disciplinaDummy.ponteiroAlunosMatriculados; index++) {
			disciplinaDummy.alunosMatriculados[index] = disciplinaDummy.alunosMatriculados[index + 1];
		}
		disciplinaDummy.ponteiroAlunosMatriculados--;
	}

	return disciplinaDummy;
}
Disciplina desmatricularProfessor(int indexProfessor, int indexDisciplina, Professor vetorProfessores[], Disciplina vetorDisciplinas[], bool showError) {
	Professor professorDummy;
	Disciplina disciplinaDummy;
	int index;
	int indexProfessorEncontrado;

	professorDummy = vetorProfessores[indexProfessor];
	disciplinaDummy = vetorDisciplinas[indexDisciplina];

	indexProfessorEncontrado = retornaIndexProfessorNaDisciplina(professorDummy, disciplinaDummy);

	if (indexProfessorEncontrado == -1) {
		if (showError == true) printf("| [ERRO] Professor não matriculado na Disciplina!\n");
	}
	else {
		for (index = indexProfessorEncontrado; index <= disciplinaDummy.ponteiroProfessoresMatriculados; index++) {
			disciplinaDummy.professoresMatriculados[index] = disciplinaDummy.professoresMatriculados[index + 1];
		}
		disciplinaDummy.ponteiroProfessoresMatriculados--;
	}

	return disciplinaDummy;
}

void listarAlunos(Aluno vetorAlunos[], int ponteiroAlunos){
	int index;
	for (index = 0; index <= ponteiroAlunos; index++) {

		printf("------------------------------------- \n");
		printf("|             Ficha A%.3d            | \n", vetorAlunos[index].RA);
		printf("|                                   | \n");
		printf("| | Nome | - %s", vetorAlunos[index].Nome);
		printf("|                                   | \n");
		printf("| |  RA  | - %.3d                    | \n", vetorAlunos[index].RA);

	}
	printf("------------------------------------- \n\n");
}
void listarProfessores(Professor vetorProfessores[], int ponteiroProfessores) {
	int index;
	for (index = 0; index <= ponteiroProfessores; index++) {

		printf("------------------------------------- \n");
		printf("|             Ficha P%.3d            | \n", vetorProfessores[index].RP);
		printf("|                                   | \n");
		printf("| | Nome | - %s", vetorProfessores[index].Nome);
		printf("|                                   | \n");
		printf("| |  RP  | - %.3d                    | \n", vetorProfessores[index].RP);

	}
	printf("------------------------------------- \n\n");
}
void listarDisciplinas(Disciplina vetorDisciplinas[], int ponteiroDisciplinas) {
	int index;
	for (index = 0; index <= ponteiroDisciplinas; index++) {

		printf("------------------------------------- \n");
		printf("|             Ficha D%.3d            | \n", vetorDisciplinas[index].ID);
		printf("|                                   | \n");
		printf("| | Nome | - %s", vetorDisciplinas[index].Nome);
		printf("|                                   | \n");
		printf("| |  RP  | - %.3d                    | \n", vetorDisciplinas[index].ID);

	}
	printf("------------------------------------- \n\n");
}

void listarDisciplinasDoAluno(Aluno aluno, Disciplina vetorDisciplinas[], int ponteiroDisciplinas) {
	int index;
	int indexAlunoEncontrado;

	printf("|                                   | \n");

	for (index = 0; index <= ponteiroDisciplinas; index++) {
		indexAlunoEncontrado = retornaIndexAlunoNaDisciplina(aluno, vetorDisciplinas[index]);
		if (indexAlunoEncontrado != -1) {
			printf("|                                   | \n");
			printf("| |  Disciplina   | - %s", vetorDisciplinas[index].Nome);
		}
	}	
}
void listarDisciplinasDoProfessor(Professor professor, Disciplina vetorDisciplinas[], int ponteiroDisciplinas) {
	int index;
	int indexProfessorEncontrado;

	printf("|                                   | \n");

	for (index = 0; index <= ponteiroDisciplinas; index++) {
		indexProfessorEncontrado = retornaIndexProfessorNaDisciplina(professor, vetorDisciplinas[index]);
		if (indexProfessorEncontrado != -1) {
			printf("|                                   | \n");
			printf("| |  Disciplina   | - %s", vetorDisciplinas[index].Nome);
		}
	}
}

void listarAlunosDaDisciplina(int indexDisciplina, Disciplina vetorDisciplinas[]) {
	Disciplina disciplinaDummy;
	int index;

	disciplinaDummy = vetorDisciplinas[indexDisciplina];
	
	printf("|                                   | \n");

	for (index = 0; index <= disciplinaDummy.ponteiroAlunosMatriculados; index++) {
		printf("|                                   | \n");
		printf("| | Aluno | - %s", disciplinaDummy.alunosMatriculados[index].Nome);
	}
}
void listarProfessoresDaDisciplina(int indexDisciplina, Disciplina vetorDisciplinas[]) {
	Disciplina disciplinaDummy;
	int index;

	disciplinaDummy = vetorDisciplinas[indexDisciplina];

	printf("|                                   | \n");

	for (index = 0; index <= disciplinaDummy.ponteiroProfessoresMatriculados; index++) {
		printf("|                                   | \n");
		printf("| | Professor | - %s", disciplinaDummy.professoresMatriculados[index].Nome);
	}
}

int retornaIndexAluno(char nomeAluno[], Aluno vetorAlunos[], int ponteiroAlunos) {
	Aluno alunoDummy;
	int index;

	for (index = 0; index <= ponteiroAlunos; index++) {
		alunoDummy = vetorAlunos[index];
		if (strcmp(nomeAluno, alunoDummy.Nome) == 0) {
			return index;
		}
	}
	return (-1);
}
int retornaIndexProfessor(char nomeProfessor[], Professor vetorProfessores[], int ponteiroProfessores) {
	Professor professorDummy;
	int index;

	for (index = 0; index <= ponteiroProfessores; index++) {
		professorDummy = vetorProfessores[index];
		if (strcmp(nomeProfessor, professorDummy.Nome) == 0) {
			return index;
		}
	}
	return (-1);
}
int retornaIndexDisciplina(char nomeDisciplina[], Disciplina vetorDisciplinas[], int ponteiroDisciplinas) {
	Disciplina disciplinaDummy;
	int index;

	for (index = 0; index <= ponteiroDisciplinas; index++) {
		disciplinaDummy = vetorDisciplinas[index];
		if (strcmp(nomeDisciplina, disciplinaDummy.Nome) == 0) {
			return index;
		}
	}
	return (-1);
}

void printMenu() {

	printf("------------------------------------- \n");
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
	printf("| | 6 | - Desmatricular ou Remover  | \n");
	printf("|                                   | \n");
	printf("| | 7 | - Imprimir                  | \n");
	printf("|                                   | \n");
	printf("|                                   | \n");
	printf("| | 0 | - Sair                      | \n");
	printf("|                                   | \n");
	printf("------------------------------------- \n");
}
void printSubMenuDesmatriculaRemocao() {

	printf("--------------------------------------\n");
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
	printf("|                                    |\n");
	printf("|                                    |\n");
	printf("| | 0 | - Voltar                     |\n");
	printf("|                                    |\n");
	printf("--------------------------------------\n");

}
void printSubMenuImpressoes() {

	printf("--------------------------------------------\n");
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
	printf("|                                          |\n");
	printf("|                                          |\n");
	printf("| | 0 | - Voltar                           |\n");
	printf("|                                          |\n");
	printf("--------------------------------------------\n");

}


int main() {
	setlocale(LC_ALL, "Portuguese");

	int index;

	int opcaoMenu = -1;
	int opcaoSubMenu = -1;

	Aluno vetorAlunos[QUANTIDADE_MAX_ALUNOS_NA_ESCOLA];
	Aluno alunoDummy;
	int ponteiroAlunos = -1;
	int contadorAlunos = 1;
	int indexAlunoDummy = -1;

	Professor vetorProfessores[QUANTIDADE_MAX_PROFESSORES_NA_ESCOLA];
	Professor professorDummy;
	int ponteiroProfessores = -1;
	int contadorProfessores = 1;
	int indexProfessorDummy = -1;

	Disciplina vetorDisciplinas[QUANTIDADE_MAX_DISCIPLINAS_NA_ESCOLA];
	Disciplina disciplinaDummy;
	int ponteiroDisciplinas = -1;
	int contadorDisciplinas = 1;
	int indexDisciplinaDummy = -1;

	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("                                                                                                              88 \n");
	printf("ooooooooo                                                                                  o888               88 \n");
	printf("888    888   oooooooo   oooo oooooo                    oooo   oooo ooooo   ooooooo     ooooo888   ooooooo     88 \n");
	printf("888oooo88   888oooooo8   888 888 888    ooooooooo       888   888   888   888   888  888    888 888     888   88 \n");
	printf("888    888  888          888 888 888                     888 888    888   888   888  888    888 888     888      \n");
	printf("o888ooo88    88oooo888   888 888 888                       888     o888o  888   888   88ooo888o   88ooo88     88 \n");
	printf("                                                                                                                 \n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");

	while (opcaoMenu != 0) {

		printf("\n\t\t\t\tSistema de Matrículas Puc Campinas\n\n");

		printMenu();
		printf("\n> ");
		scanf_s("%d", &opcaoMenu);
		myfflush();
		system("cls");

		switch (opcaoMenu) {
			case 0:
				printf("\n\n\t\t\t\tGostaria mesmo de Sair?\n\n");
				printf("----------------------\n");
				printf("|                    |\n");
				printf("|   | 1 |  -  Sim    |\n");
				printf("|                    |\n");
				printf("|   | 0 |  -  Não    |\n");
				printf("|                    |\n");
				printf("----------------------\n");

				printf("\n> ");
				scanf_s("%d", &opcaoMenu);
				myfflush();
				system("cls");

				if (opcaoMenu == 1) {
					opcaoMenu = 0;

					printf("----------------------------------------------------------------------------------------------\n");
					printf("                            o8                                                          88    \n");
					printf("    ooooo       oo        8o               88                                           88    \n");
					printf("   888 888    oo88oo   oooooooo            88    ooooooo      ooooooo      ooooooo      88    \n");
					printf("  888   888     88    888oooooo8           88  888     888  888     888  888     888    88    \n");
					printf(" 88888888888    88    888                  88  888     888  888     888  888     888          \n");
					printf("888       888   o8oo   88oooo888           88    88ooo88      88ooo888o    88ooo88      88    \n");
					printf("                                                                     88                       \n");
					printf("                                                              8ooooo8o                        \n");
					printf("----------------------------------------------------------------------------------------------\n");

				} else opcaoMenu = 1;
			break;

			case 1:				
				printf("\n\t\t\t\tCadastro de Alunos\n\n");
				printf("Em 'Nome', digite '0' para Sair.\n\n");
				do {
					alunoDummy = cadastrarAluno(contadorAlunos);
					if (strcmp(alunoDummy.Nome, "0\n") != 0) {
						ponteiroAlunos++;
						contadorAlunos++;
						vetorAlunos[ponteiroAlunos] = alunoDummy;
					}

				} while (strcmp(alunoDummy.Nome, "0\n") != 0);


				printf("Operação efetuada com sucesso.\n\n");

				system("PAUSE");
				system("cls");
			break;

			case 2:
				printf("\n\t\t\t\tCadastro de Professores\n\n");
				printf("Em 'Nome', digite '0' para Sair.\n\n");
				do {
					professorDummy = cadastrarProfessor(contadorProfessores);
					if (strcmp(professorDummy.Nome, "0\n") != 0) {
						ponteiroProfessores++;
						contadorProfessores++;
						vetorProfessores[ponteiroProfessores] = professorDummy;
					}

				} while (strcmp(professorDummy.Nome, "0\n") != 0);


				printf("Operação efetuada com sucesso.\n\n");

				system("PAUSE");
				system("cls");
			break;

			case 3:
				printf("\n\t\t\t\tCadastro de Disciplinas\n\n");
				printf("Em 'Nome', digite '0' para Sair.\n\n");
				do {
					disciplinaDummy = cadastrarDisciplina(contadorDisciplinas);
					if (strcmp(disciplinaDummy.Nome, "0\n") != 0) {
						ponteiroDisciplinas++;
						contadorDisciplinas++;
						vetorDisciplinas[ponteiroDisciplinas] = disciplinaDummy;
					}

				} while (strcmp(disciplinaDummy.Nome, "0\n") != 0);


				printf("Operação efetuada com sucesso.\n\n");

				system("PAUSE");
				system("cls");
			break;

			case 4:
				printf("\n\t\t\t\tMatricular Alunos\n\n");
				printf("Em 'Nome do Aluno', digite '0' para Sair.\n\n");
				printf("Em 'Nome da Disciplina', digite '0' para começar o Próximo Aluno.\n\n");

				do {
					printf("------------------------------------- \n");
					do {
						
						printf("| |   Nome do Aluno    | - ");
						fgets(alunoDummy.Nome, sizeof(alunoDummy.Nome), stdin);
						_strupr_s(alunoDummy.Nome, sizeof(alunoDummy.Nome));

						indexAlunoDummy = retornaIndexAluno(alunoDummy.Nome, vetorAlunos, ponteiroAlunos);
						if (indexAlunoDummy == -1) {
							if (strcmp(alunoDummy.Nome, "0\n") == 0) {
								indexAlunoDummy = 9999;
							}
							else {
								printf("| [ERRO] Aluno não encontrado! Digite um nome válido.\n");
							}
							
						}
					} while (indexAlunoDummy == -1);
					
					if (strcmp(alunoDummy.Nome, "0\n") != 0) {
						printf("|\n");
						do {
							do {
								
								printf("| | Nome da Disciplina | - ");
								fgets(disciplinaDummy.Nome, sizeof(disciplinaDummy.Nome), stdin);
								_strupr_s(disciplinaDummy.Nome, sizeof(disciplinaDummy.Nome));

								indexDisciplinaDummy = retornaIndexDisciplina(disciplinaDummy.Nome, vetorDisciplinas, ponteiroDisciplinas);
								if (indexDisciplinaDummy == -1) {
									if (strcmp(disciplinaDummy.Nome, "0\n") == 0) {
										indexDisciplinaDummy = 9999;
									}
									else {
										printf("| [ERRO] Disciplina não encontrada! Digite um nome válido.\n");
									}
								}
							} while (indexDisciplinaDummy == -1);

							if (strcmp(disciplinaDummy.Nome, "0\n") != 0) {
								disciplinaDummy = matricularAluno(indexAlunoDummy, indexDisciplinaDummy, vetorAlunos, vetorDisciplinas);
								vetorDisciplinas[indexDisciplinaDummy] = disciplinaDummy;
							}

						} while (strcmp(disciplinaDummy.Nome, "0\n") != 0);
					}

				} while (strcmp(alunoDummy.Nome, "0\n") != 0);

				printf("------------------------------------- \n");
				printf("\nOperação efetuada com sucesso.\n\n");

				system("PAUSE");
				system("cls");
			break;

			case 5:
				printf("\n\t\t\t\tMatricular Professores\n\n");
				printf("Em 'Nome do Professor', digite '0' para Sair.\n\n");
				printf("Em 'Nome da Disciplina', digite '0' para começar o Próximo Professor.\n\n");

				do {
					printf("------------------------------------- \n");
					do {
						printf("| | Nome do Professor  | - ");
						fgets(professorDummy.Nome, sizeof(professorDummy.Nome), stdin);
						_strupr_s(professorDummy.Nome, sizeof(professorDummy.Nome));

						indexProfessorDummy = retornaIndexProfessor(professorDummy.Nome, vetorProfessores, ponteiroProfessores);
						if (indexProfessorDummy == -1) {
							if (strcmp(professorDummy.Nome, "0\n") == 0) {
								indexProfessorDummy = 9999;
							}
							else {
								printf("| [ERRO] Professor não encontrado! Digite um nome válido.\n");
							}

						}
					} while (indexProfessorDummy == -1);

					if (strcmp(professorDummy.Nome, "0\n") != 0) {
						printf("|\n");
						do {
							do {

								printf("| | Nome da Disciplina | - ");
								fgets(disciplinaDummy.Nome, sizeof(disciplinaDummy.Nome), stdin);
								_strupr_s(disciplinaDummy.Nome, sizeof(disciplinaDummy.Nome));

								indexDisciplinaDummy = retornaIndexDisciplina(disciplinaDummy.Nome, vetorDisciplinas, ponteiroDisciplinas);
								if (indexDisciplinaDummy == -1) {
									if (strcmp(disciplinaDummy.Nome, "0\n") == 0) {
										indexDisciplinaDummy = 9999;
									}
									else {
										printf("| [ERRO] Disciplina não encontrada! Digite um nome válido.\n");
									}
								}
							} while (indexDisciplinaDummy == -1);

							if (strcmp(disciplinaDummy.Nome, "0\n") != 0) {
								disciplinaDummy = matricularProfessor(indexProfessorDummy, indexDisciplinaDummy, vetorProfessores, vetorDisciplinas);
								vetorDisciplinas[indexDisciplinaDummy] = disciplinaDummy;
							}

						} while (strcmp(disciplinaDummy.Nome, "0\n") != 0);
					}

				} while (strcmp(professorDummy.Nome, "0\n") != 0);

				printf("------------------------------------- \n");
				printf("\nOperação efetuada com sucesso.\n\n");

				system("PAUSE");
				system("cls");
			break;

			case 6:
				opcaoSubMenu = -1;

				while (opcaoSubMenu != 0) {
					printf("\n\t\t\t\tDesmatricular ou Remover\n\n");
					printSubMenuDesmatriculaRemocao();
					printf("\n> ");
					scanf_s("%d", &opcaoSubMenu);
					myfflush();
					system("cls");

					switch (opcaoSubMenu) {
						case 0:
							system("cls");
							break;

						case 1:
							printf("\n\t\t\t\tDesmatricular Alunos\n\n");
							printf("Em 'Nome do Aluno', digite '0' para Sair.\n\n");
							printf("Em 'Nome da Disciplina', digite '0' para começar o Próximo Aluno.\n\n");

							do {
								printf("------------------------------------- \n");
								do {

									printf("| |   Nome do Aluno    | - ");
									fgets(alunoDummy.Nome, sizeof(alunoDummy.Nome), stdin);
									_strupr_s(alunoDummy.Nome, sizeof(alunoDummy.Nome));

									indexAlunoDummy = retornaIndexAluno(alunoDummy.Nome, vetorAlunos, ponteiroAlunos);
									if (indexAlunoDummy == -1) {
										if (strcmp(alunoDummy.Nome, "0\n") == 0) {
											indexAlunoDummy = 9999;
										}
										else {
											printf("| [ERRO] Aluno não encontrado! Digite um nome válido.\n");
										}

									}
								} while (indexAlunoDummy == -1);

								if (strcmp(alunoDummy.Nome, "0\n") != 0) {
									printf("|\n");
									do {
										do {

											printf("| | Nome da Disciplina | - ");
											fgets(disciplinaDummy.Nome, sizeof(disciplinaDummy.Nome), stdin);
											_strupr_s(disciplinaDummy.Nome, sizeof(disciplinaDummy.Nome));

											indexDisciplinaDummy = retornaIndexDisciplina(disciplinaDummy.Nome, vetorDisciplinas, ponteiroDisciplinas);
											if (indexDisciplinaDummy == -1) {
												if (strcmp(disciplinaDummy.Nome, "0\n") == 0) {
													indexDisciplinaDummy = 9999;
												}
												else {
													printf("| [ERRO] Disciplina não encontrada! Digite um nome válido.\n");
												}
											}
										} while (indexDisciplinaDummy == -1);

										if (strcmp(disciplinaDummy.Nome, "0\n") != 0) {
											disciplinaDummy = desmatricularAluno(indexAlunoDummy, indexDisciplinaDummy, vetorAlunos, vetorDisciplinas, true);
											vetorDisciplinas[indexDisciplinaDummy] = disciplinaDummy;
										}

									} while (strcmp(disciplinaDummy.Nome, "0\n") != 0);
								}
							} while (strcmp(alunoDummy.Nome, "0\n") != 0);

							printf("------------------------------------- \n");
							printf("\nOperação efetuada com sucesso.\n\n");

							system("PAUSE");
							system("cls");
						break;

						case 2:
							printf("\n\t\t\t\tDesmatricular Professores\n\n");
							printf("Em 'Nome do Professor', digite '0' para Sair.\n\n");
							printf("Em 'Nome da Disciplina', digite '0' para começar o Próximo Professor.\n\n");

							do {
								printf("------------------------------------- \n");
								do {
									printf("| | Nome do Professor  | - ");
									fgets(professorDummy.Nome, sizeof(professorDummy.Nome), stdin);
									_strupr_s(professorDummy.Nome, sizeof(professorDummy.Nome));

									indexProfessorDummy = retornaIndexAluno(professorDummy.Nome, vetorProfessores, ponteiroProfessores);
									if (indexProfessorDummy == -1) {
										if (strcmp(professorDummy.Nome, "0\n") == 0) {
											indexProfessorDummy = 9999;
										}
										else {
											printf("| [ERRO] Professor não encontrado! Digite um nome válido.\n");
										}

									}
								} while (indexProfessorDummy == -1);

								if (strcmp(professorDummy.Nome, "0\n") != 0) {
									printf("|\n");
									do {
										do {

											printf("| | Nome da Disciplina | - ");
											fgets(disciplinaDummy.Nome, sizeof(disciplinaDummy.Nome), stdin);
											_strupr_s(disciplinaDummy.Nome, sizeof(disciplinaDummy.Nome));

											indexDisciplinaDummy = retornaIndexDisciplina(disciplinaDummy.Nome, vetorDisciplinas, ponteiroDisciplinas);
											if (indexDisciplinaDummy == -1) {
												if (strcmp(disciplinaDummy.Nome, "0\n") == 0) {
													indexDisciplinaDummy = 9999;
												}
												else {
													printf("| [ERRO] Disciplina não encontrada! Digite um nome válido.\n");
												}
											}
										} while (indexDisciplinaDummy == -1);

										if (strcmp(disciplinaDummy.Nome, "0\n") != 0) {
											disciplinaDummy = desmatricularProfessor(indexProfessorDummy, indexDisciplinaDummy, vetorProfessores, vetorDisciplinas, true);
											vetorDisciplinas[indexDisciplinaDummy] = disciplinaDummy;
										}

									} while (strcmp(disciplinaDummy.Nome, "0\n") != 0);
								}
							} while (strcmp(professorDummy.Nome, "0\n") != 0);

							printf("------------------------------------- \n");
							printf("\nOperação efetuada com sucesso.\n\n");

							system("PAUSE");
							system("cls");
						break;

						case 3:
							printf("\n\t\t\t\tRemover Alunos\n\n");
							printf("Em 'Nome do Aluno', digite '0' para Sair.\n\n");

							do {
								printf("------------------------------------- \n");
								do {

									printf("| |   Nome do Aluno    | - ");
									fgets(alunoDummy.Nome, sizeof(alunoDummy.Nome), stdin);
									_strupr_s(alunoDummy.Nome, sizeof(alunoDummy.Nome));

									indexAlunoDummy = retornaIndexAluno(alunoDummy.Nome, vetorAlunos, ponteiroAlunos);
									if (indexAlunoDummy == -1) {
										if (strcmp(alunoDummy.Nome, "0\n") == 0) {
											indexAlunoDummy = 9999;
										}
										else {
											printf("| [ERRO] Aluno não encontrado! Digite um nome válido.\n");
										}

									}
								} while (indexAlunoDummy == -1);

								if (strcmp(alunoDummy.Nome, "0\n") != 0) {
									printf("|\n");

									for (indexDisciplinaDummy = 0; indexDisciplinaDummy <= ponteiroDisciplinas; indexDisciplinaDummy++) {
										vetorDisciplinas[indexDisciplinaDummy] = desmatricularAluno(indexAlunoDummy, indexDisciplinaDummy, vetorAlunos, vetorDisciplinas, false);
									}

									for (index = indexAlunoDummy; index <= ponteiroAlunos; index++) {
										vetorAlunos[index] = vetorAlunos[index + 1];
									}
									ponteiroAlunos--;
								}
							} while (strcmp(alunoDummy.Nome, "0\n") != 0);

							printf("------------------------------------- \n");
							printf("\nOperação efetuada com sucesso.\n\n");

							system("PAUSE");
							system("cls");
						break;

						case 4:
							printf("\n\t\t\t\tRemover Professores\n\n");
							printf("Em 'Nome do Professor', digite '0' para Sair.\n\n");

							do {
								printf("------------------------------------- \n");
								do {

									printf("| | Nome do Professor  | - ");
									fgets(professorDummy.Nome, sizeof(professorDummy.Nome), stdin);
									_strupr_s(professorDummy.Nome, sizeof(professorDummy.Nome));

									indexProfessorDummy = retornaIndexProfessor(professorDummy.Nome, vetorProfessores, ponteiroProfessores);
									if (indexProfessorDummy == -1) {
										if (strcmp(professorDummy.Nome, "0\n") == 0) {
											indexProfessorDummy = 9999;
										}
										else {
											printf("| [ERRO] Professor não encontrado! Digite um nome válido.\n");
										}
									}
								} while (indexProfessorDummy == -1);

								if (strcmp(professorDummy.Nome, "0\n") != 0) {
									printf("|\n");

									for (indexDisciplinaDummy = 0; indexDisciplinaDummy <= ponteiroDisciplinas; indexDisciplinaDummy++) {
										vetorDisciplinas[indexDisciplinaDummy] = desmatricularProfessor(indexProfessorDummy, indexDisciplinaDummy, vetorProfessores, vetorDisciplinas, false);
									}

									for (index = indexProfessorDummy; index <= ponteiroProfessores; index++) {
										vetorProfessores[index] = vetorProfessores[index + 1];
									}
									ponteiroProfessores--;
								}
							} while (strcmp(professorDummy.Nome, "0\n") != 0);

							printf("------------------------------------- \n");
							printf("\nOperação efetuada com sucesso.\n\n");

							system("PAUSE");
							system("cls");
						break;

						case 5:
							printf("\n\t\t\t\tRemover Disciplinas\n\n");
							printf("Em 'Nome da Disciplina', digite '0' para Sair.\n\n");

							do {
								printf("------------------------------------- \n");
								do {

									printf("| | Nome da Disciplina | - ");
									fgets(disciplinaDummy.Nome, sizeof(disciplinaDummy.Nome), stdin);
									_strupr_s(disciplinaDummy.Nome, sizeof(disciplinaDummy.Nome));

									indexDisciplinaDummy = retornaIndexDisciplina(disciplinaDummy.Nome, vetorDisciplinas, ponteiroDisciplinas);
									if (indexDisciplinaDummy == -1) {
										if (strcmp(disciplinaDummy.Nome, "0\n") == 0) {
											indexDisciplinaDummy = 9999;
										}
										else {
											printf("| [ERRO] Disciplina não encontrada! Digite um nome válido.\n");
										}
									}
								} while (indexDisciplinaDummy == -1);

								if (strcmp(disciplinaDummy.Nome, "0\n") != 0) {
									printf("|\n");

									for (index = indexDisciplinaDummy; index <= ponteiroDisciplinas; index++) {
										vetorDisciplinas[index] = vetorDisciplinas[index + 1];
									}
									ponteiroDisciplinas--;
								}
							} while (strcmp(disciplinaDummy.Nome, "0\n") != 0);

							printf("------------------------------------- \n");
							printf("\nOperação efetuada com sucesso.\n\n");

							system("PAUSE");
							system("cls");
						break;

						default:
							printf("\n[ERRO] Opção Inválida!\n\nPor favor, escolha novamente.\n\n> ");
							system("PAUSE");
							system("cls");
							break;
					}
				}
			break;

			case 7:
				opcaoSubMenu = -1;

				while (opcaoSubMenu != 0) {

					printf("\n\t\t\t\tImprimir\n\n");

					printSubMenuImpressoes();
					printf("\n> ");
					scanf_s("%d", &opcaoSubMenu);
					myfflush();
					system("cls");

					switch (opcaoSubMenu) {
					case 0:
						system("cls");
					break;

					case 1:
						printf("\n\t\t\t\tLista de Alunos Cadastrados\n\n");
						listarAlunos(vetorAlunos, ponteiroAlunos);
						system("PAUSE");
						system("cls");
					break;

					case 2:
						printf("\n\t\t\t\tLista de Professores Cadastrados\n\n");
						listarProfessores(vetorProfessores, ponteiroProfessores);
						system("PAUSE");
						system("cls");
					break;

					case 3:
						printf("\n\t\t\t\tLista de Disciplinas Cadastradas\n\n");
						listarDisciplinas(vetorDisciplinas, ponteiroDisciplinas);
						system("PAUSE");
						system("cls");
					break;

					case 4:
						printf("\n\t\t\t\tListar Disciplinas do Aluno\n\n");
						printf("Em 'Nome do Aluno', digite '0' para Sair.\n\n");
						do {
							printf("------------------------------------- \n");
							do {
								printf("| | Nome do Aluno | - ");
								fgets(alunoDummy.Nome, sizeof(alunoDummy.Nome), stdin);
								_strupr_s(alunoDummy.Nome, sizeof(alunoDummy.Nome));

								indexAlunoDummy = retornaIndexAluno(alunoDummy.Nome, vetorAlunos, ponteiroAlunos);
								if (indexAlunoDummy == -1) {
									if (strcmp(alunoDummy.Nome, "0\n") == 0) {
										indexAlunoDummy = 9999;
									}
									else {
										printf("| [ERRO] Aluno não encontrado! Digite um nome válido.\n");
									}
								}
							} while (indexAlunoDummy == -1);

							if (strcmp(alunoDummy.Nome, "0\n") != 0) {
								listarDisciplinasDoAluno(alunoDummy, vetorDisciplinas, ponteiroDisciplinas);
							}

						} while (strcmp(alunoDummy.Nome, "0\n") != 0);

						printf("------------------------------------- \n\n");

						system("PAUSE");
						system("cls");
					break;

					case 5:
						printf("\n\t\t\t\tListar Disciplinas do Professor\n\n");
						printf("Em 'Nome do Professor', digite '0' para Sair.\n\n");
						do {
							printf("------------------------------------- \n");
							do {
								printf("| | Nome do Professor | - ");
								fgets(professorDummy.Nome, sizeof(professorDummy.Nome), stdin);
								_strupr_s(professorDummy.Nome, sizeof(professorDummy.Nome));

								indexProfessorDummy = retornaIndexProfessor(professorDummy.Nome, vetorProfessores, ponteiroProfessores);
								if (indexProfessorDummy == -1) {
									if (strcmp(professorDummy.Nome, "0\n") == 0) {
										indexProfessorDummy = 9999;
									}
									else {
										printf("| [ERRO] Professor não encontrado! Digite um nome válido.\n");
									}
								}
							} while (indexProfessorDummy == -1);

							if (strcmp(professorDummy.Nome, "0\n") != 0) {
								listarDisciplinasDoProfessor(professorDummy, vetorDisciplinas, ponteiroDisciplinas);
							}

						} while (strcmp(professorDummy.Nome, "0\n") != 0);

						printf("------------------------------------- \n\n");

						system("PAUSE");
						system("cls");
						break;

					case 6:
						printf("\n\t\t\t\tListar Alunos da Disciplina\n\n");
						printf("Em 'Nome da Disciplina', digite '0' para Sair.\n\n");
						do {
							printf("------------------------------------- \n");
							do {
								printf("| | Nome da Disciplina | - ");
								fgets(disciplinaDummy.Nome, sizeof(disciplinaDummy.Nome), stdin);
								_strupr_s(disciplinaDummy.Nome, sizeof(disciplinaDummy.Nome));

								indexDisciplinaDummy = retornaIndexDisciplina(disciplinaDummy.Nome, vetorDisciplinas, ponteiroDisciplinas);
								if (indexDisciplinaDummy == -1) {
									if (strcmp(disciplinaDummy.Nome, "0\n") == 0) {
										indexDisciplinaDummy = 9999;
									}
									else {
										printf("| [ERRO] Disciplina não encontrada! Digite um nome válido.\n");
									}
								}
							} while (indexDisciplinaDummy == -1);

							if (strcmp(disciplinaDummy.Nome, "0\n") != 0) {
								listarAlunosDaDisciplina(indexDisciplinaDummy, vetorDisciplinas);
							}

						} while (strcmp(disciplinaDummy.Nome, "0\n") != 0);

						printf("------------------------------------- \n\n");

						system("PAUSE");
						system("cls");
					break;
					
					case 7:
						printf("\n\t\t\t\tListar Professores da Disciplina\n\n");
						printf("Em 'Nome da Disciplina', digite '0' para Sair.\n\n");
						do {
							printf("------------------------------------- \n");
							do {
								printf("| | Nome da Disciplina | - ");
								fgets(disciplinaDummy.Nome, sizeof(disciplinaDummy.Nome), stdin);
								_strupr_s(disciplinaDummy.Nome, sizeof(disciplinaDummy.Nome));

								indexDisciplinaDummy = retornaIndexDisciplina(disciplinaDummy.Nome, vetorDisciplinas, ponteiroDisciplinas);
								if (indexDisciplinaDummy == -1) {
									if (strcmp(disciplinaDummy.Nome, "0\n") == 0) {
										indexDisciplinaDummy = 9999;
									}
									else {
										printf("| [ERRO] Disciplina não encontrada! Digite um nome válido.\n");
									}
								}
							} while (indexDisciplinaDummy == -1);

							if (strcmp(disciplinaDummy.Nome, "0\n") != 0) {
								listarProfessoresDaDisciplina(indexDisciplinaDummy, vetorDisciplinas);
							}

						} while (strcmp(disciplinaDummy.Nome, "0\n") != 0);

						printf("------------------------------------- \n\n");

						system("PAUSE");
						system("cls");
					break;

					default:
						printf("\n[ERRO] Opção Inválida!\n\nPor favor, escolha novamente.\n\n> ");
						system("PAUSE");
						system("cls");
						break;
					}
				}
				break;

			default:
				printf("\n[ERRO] Opção Inválida!\n\nPor favor, escolha novamente.\n\n> ");
				system("PAUSE");
				system("cls");
				break;
		}
	}


	printf("\n\n\n");
	system("PAUSE");
	printf("\n\n");
	return(0);
}