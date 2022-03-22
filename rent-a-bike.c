#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

	typedef struct cliente{ 
		int id;
		char nome[30];
		char cpf[12];
		int idade;
		char telefone[12];
		char sexo;
		float saldo;
		float comprasTotal;		
	}cliente;
	
	typedef struct veiculo{
		int cod;
		char marca[30];
		char tam[30];
		int aro;
		char status[15];
	}veiculo;
	
	typedef struct locacao{
		int rg;
		int id;
		char nome[30];
		char cpf[12];
		int idade;
		char telefone[12];
		char sexo;
		int cod;
		char marca[30];
		char tam[30];
		int aro;
		int dias;
		float valor;
		char user[12];
	} locacao;
	
	typedef struct empresa{
		float fundos;	
	}empresa;
	
	typedef struct login{
		char user[12];
		char senha[12];
	}login;
	
	int c = 0; // Define posicao inicial do vetor Cliente
	int b = 0; // Define posicao inicial do vetor Bike
	int l = 0; // Define posicao inicial do vetor Locacao
	int u = 1; // Quantidade de usuarios cadastrados
	char usuarioAtual[12];
	
void entrarUsuario(login log[10]);
void novoUsuario(login log[10]);	
void cadastrarCliente(cliente cli[100]);
void consultarCliente(cliente cli[100]);
void relatorioGeralCliente(cliente cli[100]);
void editCliente(cliente cli[100]);
void saldoCliente(cliente cli[100]);
void cadastrarVeiculo(veiculo bike[20]);
void consultarVeiculo(veiculo bike[20]);
void relatorioGeralVeiculo(veiculo bike[20]);
void editVeiculo(veiculo bike[20]);
float locarVeiculo(cliente cli[100], veiculo bike[20], locacao loc[1000], empresa emp);
void consultarLocacao(locacao loc[1000]);
void registerDevol(veiculo bike[20], locacao loc[1000]);

int main(int argc, char *argv[]) {

int opcaoMenu, menuCliente, menuVeiculo, menuLocacao, menuUsuario;
int retornar_menu, retornar_menuCliente, retornar_menuVeiculo, retornar_menuLocacao, retornar_menuUsuario;

cliente cli[100];
veiculo bike[20];
locacao loc[1000];
empresa emp;
login log[10];

cli[0].id = 0;
bike[0].cod = 1000;
loc[0].rg = 0;
emp.fundos = 0;

strcpy(log[0].user, "admin");
strcpy(log[0].senha, "123456");

entrarUsuario(log);
	
	// MENU PRINCIPAL
	
	do {
		printf("\n\t\t**************************\n");
		printf("\t\t***   MENU PRINCIPAL   ***\n");
		printf("\t\t***                    ***\n");
		printf("\t\t**************************\n\n");
		
		printf("   1 - CLIENTE\n");
		printf("   2 - VEICULO\n");
		printf("   3 - LOCACAO\n");
		printf("   4 - INFO\n");
		printf("   5 - USUARIOS\n");
		
		printf("\n   0 - SAIR\n");
		
		printf("\n   Usuario atual: %s", usuarioAtual);
		printf("\n\n   Selecione a opcao desejada: ");
				
		scanf("%d", &opcaoMenu);
			
		system("cls");
		fflush(stdin);
	
		switch(opcaoMenu){
			case 1: {
				do{ 
					printf("\n   MENU CLIENTE\n\n");
					printf("   1 - Cadastrar\n");
					printf("   2 - Consultar\n");
					printf("   3 - Relatorio geral\n");
					printf("   4 - Editar\n");
					printf("   5 - Inserir Saldo\n");
					printf("\n   9 - Voltar\n");
					
					printf("\n\n   Selecione a opcao desejada: ");
			
	        	    scanf("%d", &menuCliente);
	        	       
		    	    system("cls");
		    	    fflush(stdin);
				
					switch (menuCliente){
						case 1: {
							cadastrarCliente(cli);
							getchar();							
							break;
						}
						case 2: {
							consultarCliente(cli);
							getchar();
							break;
						}
						case 3: {
							relatorioGeralCliente(cli);
							break;
						}
						case 4: {
							editCliente(cli);
							getchar();
							break;
						}
						case 5:{
							saldoCliente(cli);
							getchar();
							break;
						}
						case 9: {
							retornar_menuCliente = 0;
							break;
						}
						default: {
							printf("\n   Opcao Invalida\n");
							getchar();
							break;
						}						
					}
					
					system("cls");
		    	    fflush(stdin);  
		    	    
		    	    if(menuCliente != 9){
		    	    	retornar_menuCliente = 1;		    	    	
					}  
				} while(retornar_menuCliente == 1);
				
				break;
			}
			case 2: {
				do{
					printf("\n   MENU VEICULO\n\n");
					printf("   1 - Cadastrar\n");
					printf("   2 - Consultar\n");
					printf("   3 - Relatorio Geral\n");
					printf("   4 - Editar\n");
					printf("\n   9 - Voltar\n");
					
					printf("\n\n   Selecione a opcao desejada: ");
					
					scanf("%d", &menuVeiculo);
				
					system("cls");
	            	fflush(stdin);
		           
		        	switch (menuVeiculo){
		        		case 1: {
		        			cadastrarVeiculo(bike);
							getchar();		            		
							break;
						}
		           		case 2: {
						   consultarVeiculo(bike);
						   getchar();
						   break;
						}
						case 3:{
							relatorioGeralVeiculo(bike);
							break;
						}
						case 4: {
							editVeiculo(bike);
							getchar();
							break;
						}
						case 9: {
							retornar_menuVeiculo = 0;
							break;
						}
						default: {
							printf("\n   Opcao Invalida\n");
							getchar();
							break;
						}
					}
				
					system("cls");
		    	    fflush(stdin); 
		    	    
		    	    if(menuVeiculo != 9){
		    	    	retornar_menuVeiculo = 1;		    	    	
					}
				} while(retornar_menuVeiculo == 1);
				
				break;	
			}
			case 3: {
				do{
					printf("\n   MENU LOCACAO\n\n");
					printf("   1 - Nova Locacao\n");
					printf("   2 - Consultar Locacao\n");
					printf("   3 - Registrar Devolucao\n");
					printf("\n   9 - Voltar\n");
					
					printf("\n\n   Selecione a opcao desejada: ");
					
					scanf("%d", &menuLocacao);
				
					system("cls");
	            	fflush(stdin);	
	            	
	            	switch(menuLocacao){
	            		case 1:{
							emp.fundos = locarVeiculo(cli, bike, loc, emp);
							getchar();
							break;
						}
	            		case 2: {
	            			consultarLocacao(loc);
	            			getchar();
							break;
						}
	            		case 3: {
	            			registerDevol(bike, loc);
	            			getchar();
							break;
						}
	            		case 9: {
	            			retornar_menuLocacao = 0;
							break;
						}
						default: {
							printf("\n   Opcao Invalida\n");
							getchar();
							break;
						}
					}
					
					system("cls");
		    	    fflush(stdin); 
		    	    
		    	    if(menuLocacao != 9){
		    	    	retornar_menuLocacao = 1;
					}
				} while(retornar_menuLocacao == 1);
				
				break;
			}
			case 4:{
				printf("\n   INFORMCACOES GERAIS\n");
				printf("\n   Total de clientes cadastrados: %d", c);
				printf("\n   Total de veiculos cadastrados: %d", b);
				printf("\n   Total de locacoes: %d", l);
				printf("\n   Total de fundos: R$ %.2f", emp.fundos);
				getch();
				break;
			}
			case 5:{
				do{
					printf("\n   USUARIOS\n\n");
					printf("   1 - Novo usuario\n");
					printf("   2 - Trocar senha\n");
					printf("   3 - Alterar usuario\n");
					printf("   4 - Registro de atividades\n");
					printf("   9 - Voltar");
					scanf("%d", &menuUsuario);
					
					system("cls");
	            	fflush(stdin);
					
					switch (menuUsuario){
						case 1: {
							novoUsuario(log);
							break;
						}
						case 2: {
							
							break;
						}
						case 3: {
							system("cls");
							entrarUsuario(log);
							break;
						}
						case 9: {
							retornar_menuUsuario = 0;
							break;
						}
						default: {
							printf("\n   Opcao Invalida\n");
							getchar();
							break;
						}
					}	
					
					system("cls");
		    	    fflush(stdin); 
		    	    
		    	    if(menuUsuario != 9){
		    	    	retornar_menuUsuario = 1;		    	    	
					}
				} while (retornar_menuUsuario == 1);
				
				break;
			}
			
			case 0: {
				retornar_menu = 0;
				break;
			}
			
			default: {
				printf("\n   Opcao Invalida\n");
				getchar();
				break;
			}
		}
		
		system("cls");
		fflush(stdin);
		
		if (opcaoMenu != 0){	
			retornar_menu = 1;
		}
	} while (retornar_menu == 1);
	
	printf ("\n   Encerrando Programa...\n\n");
	
	getchar();
	return 0;
}
	//FUNCAO LOGIN
	
void entrarUsuario(login log[10]){
	
	int i, acesso;
	char usuario[12], senha[12];
	
	do{	
		printf("\n\t\tVENHA DE BIKE E SEJA SUSTENTAVEL\n\n\n\n");  

		printf("\t___    __           ______             _________  \n");
		printf("\t__ |  / /______________  /_______ _    ______  /____  \n");
		printf("\t__ | / /_  _ \\_  __ \\_  __ \\  __ `/    _  __  /_  _ \\ \n");
		printf("\t__ |/ / /  __/  / / /  / / / /_/ /     / /_/ / /  __/ \n");
		printf("\t_____/  \\___//_/ /_//_/ /_/\\__,_/      \\__,_/  \\___/  \n");
	                                                     
		printf("\t_____________________ ___________ \n");
		printf("\t___  __ )___  _/__  //_/__  ____/ \n");
		printf("\t__  __  |__  / __  ,<  __  __/    \n");
		printf("\t_  /_/ /__/ /  _  /| | _  /___    \n");
		printf("\t/_____/ /___/  /_/ |_| /_____/    \n");
                                 
		printf("\n");	                                                                                             
		printf("\n");
		
		printf("   USUARIO: ");
		scanf("%[^\n]", &usuario);
		fflush(stdin);
		
		for (i = 0; i <= u; i++){
			if(strcmp(usuario, log[i].user) == 0){
				printf("\n   SENHA: ");
				scanf("%[^\n]", senha);
				fflush(stdin);
				
				if(strcmp(senha, log[i].senha) == 0){
					printf("\n   Login realizado com sucesso\n");
					strcpy(usuarioAtual, log[i].user);
					getchar();
					system("cls");
					acesso = 1;
					break;
				} else{
					printf("\n   Senha nao confere\n");
					getchar();
					system("cls");
					acesso = 0;
					break;
				}				
			} else if (i == u){
				printf("\n   Usuario inexistente\n");
				getchar();
				system("cls");
				acesso = 0;
				break;
			}			
		}
	} while (acesso != 1);
}	

	//FUNCAO NOVO USUARIO

void novoUsuario(login log[10]){
	
	int op;
	char senha1[12], senha2[12];
	
	fflush(stdin);
	printf("\n   CADASTRO DE USUARIO\n");
	printf("\n   Informe o login: ");
	scanf("%[^\n]", &log[u].user);
	fflush(stdin);
	
	printf("\n   Nome de usuario: %s. Confirmar?\n", log[u].user);
	printf("   1 - SIM\n");
	printf("   2 - NAO\n");
	scanf("%d", &op);
	
	if (op == 1){
		fflush(stdin);
		printf("\n   Informe a senha: ");
		scanf("%[^\n]", &senha1);
		fflush(stdin);
		printf("\n   Repita a senha: ");
		scanf("%[^\n]", &senha2);
	
		if (strcmp(senha1, senha2) == 0){
			strcpy(log[u].senha, senha1);
			printf("\n   Usuario cadastrado com sucesso");
			u++;
			getchar();	
		} else {
			printf("   Senhas nao conferem");
			printf("   Operacao cancelada");
			getchar();
		}	
	} else if (op == 2){
		printf("   Operacao cancelada");
		getchar();
	} else {
		printf("   Opcao invalida");
		printf("   Operacao cancelada");
		getchar();
	}
	getchar();
}
	
	//FUNCAO CADASTRAR CLIENTE

void cadastrarCliente(cliente cli[100]){
	
	int recadastrarCliente;
	
	do {
		printf("\n   CADASTRAR CLIENTE\n");
		
		printf("\n   Nome: ");
		scanf ("%[^\n]", cli[c].nome);
		strupr(cli[c].nome);
		fflush(stdin);
		printf("   CPF: ");
		scanf("%[^\n]", &cli[c].cpf);
		printf("   Idade: ");
		scanf("%d", &cli[c].idade);
		printf("   Sexo (M/F): ");
		scanf(" %c", &cli[c].sexo);
		fflush(stdin);
		printf("   Telefone: ");
		scanf ("%[^\n]", cli[c].telefone);
		printf ("   Saldo: ");
		scanf("%f", &cli[c].saldo);
		cli[c].id = c + 1;
		
		printf("\n   Cliente cadastrado com sucesso ID %d\n", cli[c].id);
		
		cli[c].comprasTotal = 0;
		c++;
	
		fflush(stdin);
		getchar();
		system("cls");
		
		do{
			printf("\n   Deseja cadastrar outro cliente?: \n");
			printf("   1 - Sim\n");
			printf("   2 - Nao\n\n");
			scanf(" %d", &recadastrarCliente);
			
			if (recadastrarCliente != 1 && recadastrarCliente !=2){
				printf("\n   Opcao Invalida\n");
			}
		} while (recadastrarCliente != 1 && recadastrarCliente != 2);
		
		system("cls");
		fflush(stdin);		
	} while (recadastrarCliente == 1);
}

	//FUNCAO CONSULTAR CLIENTE

void consultarCliente(cliente cli[100]){

	int i, id, op;
	char cpf[12];
	
	printf("\n   CONSULTA CLIENTE\n");
	
	printf("\n   1 - CONSULTA POR ID");
	printf("\n   2 - CONSULTA POR CPF\n");
	scanf("%d", &op);
	
	switch(op){
		case 1:{
			printf("\n   Informe o ID do cliente: ");
			scanf("%d", &id);
	
			if( id <= 0 || id > c){
				printf("\n   Cliente inexistente");
				printf("\n   Operacao cancelada");
			} else {
				printf("\n   ID: %d\n", cli[id-1].id);
				printf("   Nome: %s\n", cli[id-1].nome);
				printf("   CPF: %s\n", cli[id-1].cpf);
				printf("   Idade: %d\n", cli[id-1].idade);
				printf("   Sexo: %c\n", cli[id-1].sexo);
				printf("   Telefone: %s\n", cli[id-1].telefone);
				printf("   Saldo: R$ %.2f\n", cli[id-1].saldo);
				printf("   Total de consumo: R$ %.2f\n", cli[id-1].comprasTotal);
			}
			break;
		}
		case 2:{
			fflush(stdin);
			printf("\n   Informe o CPF do cliente: ");
			scanf("%[^\n]", &cpf);
	
			for(i = 0; i <= c; i++){
				if (strcmp(cpf,cli[i].cpf) == 0){
					printf("\n   ID: %d\n", cli[i].id);
					printf("   Nome: %s\n", cli[i].nome);
					printf("   CPF: %s\n", cli[i].cpf);
					printf("   Idade: %d\n", cli[i].idade);
					printf("   Sexo: %c\n", cli[i].sexo);
					printf("   Telefone: %s\n", cli[i].telefone);
					printf("   Saldo: R$ %.2f\n", cli[i].saldo);
					printf("   Total de consumo: R$ %.2f\n", cli[i].comprasTotal);
					break;						
				} else if (i == c){
					printf("\n   Cliente inexistente");
					printf("\n   Operacao cancelada");
				}
			}
			break;
		}
		default:{
			printf("\n   Opcao Invalida\n");
			break;
		}
	}
	getchar();
}
	
	//FUNCAO RELATORIO GERAL CLIENTE

void relatorioGeralCliente(cliente cli[100]){
	
	int i;
	
	if(c == 0){
		printf("\n   Nenhum cliente cadastrado");
	} else{
			printf("\n   RELATORIO GERAL\n");
		for(i = 0; i <= c-1; i++){
			printf("\n   ID: %d\n", cli[i].id);
			printf("   Nome: %s\n", cli[i].nome);
			printf("   CPF: %s\n", cli[i].cpf);
			printf("   Idade: %d\n", cli[i].idade);
			printf("   Sexo: %c\n", cli[i].sexo);
			printf("   Telefone: %s\n", cli[i].telefone);
			printf("   Saldo: R$ %.2f\n", cli[i].saldo);
			printf("   Total de consumo: R$ %.2f\n", cli[i].comprasTotal);		
		}	
	}
	getchar();
}	


	//FUNCAO EDITAR CLIENTE

void editCliente(cliente cli[100]){
	
	int i, cliEdit;
	
	printf("\n   EDITAR CLIENTE\n");
	
	printf("\n   Informe o ID: ");
	scanf("%d", &i);
	
	if(i <= 0 || i > c){
		printf("\n   Cliente inexistente");
		printf("\n   Operacao cancelada");
	} else{
		do{
			printf("\n   Informe o campo que deseja editar\n");
			printf("   1 - Nome\n");
			printf("   2 - CPF\n");
			printf("   3 - Idade\n");
			printf("   4 - Sexo\n");
			printf("   5 - Telefone\n");
			printf("   6 - Saldo\n");
			printf("\n\n   9 - Voltar\n");
			scanf("%d", &cliEdit);
		
			system("cls");
			fflush(stdin);
		
			switch(cliEdit){
				case 1:{
					printf("\n   Nome: ");
					scanf ("%[^\n]", cli[i-1].nome);
					strupr(cli[i-1].nome);
					break;
				}
				case 2:{
					printf("   CPF: ");
					scanf("%s", &cli[i-1].cpf);
					break;
				}
				case 3:{
					printf("   Idade: ");
					scanf("%d", &cli[i-1].idade);
					break;
				}
				case 4:{
					printf("   Sexo (M/F): ");
					scanf(" %c", &cli[i-1].sexo);
					fflush(stdin);
					break;
				}
				case 5:{
					printf("   Telefone: ");
					scanf ("%[^\n]", cli[i-1].telefone);
					break;
				}
				case 6:{
					printf ("   Saldo: ");
					scanf("%f", &cli[i-1].saldo);
					break;
				}
				case 9:{
					break;
				}
				default: {
					printf("\n   Opcao Invalida\n");
					getchar();
					break;
				}	
			}
			fflush(stdin);	
			system("cls");
		} while (cliEdit != 9);		
	}
	
	printf("\n   Registro realizado com sucesso");
	
	fflush(stdin);
	getchar();
}

	//FUNCAO INSERIR SALDO

void saldoCliente(cliente cli[100]){
	
	int i, op;
	float saldo;
	
	printf("\n   INSERIR SALDO\n");
		
	printf("\n   Informe o ID: ");
	scanf("%d", &i);
	
	if( i<= 0 || i > c){
		printf("\n   Cliente inexistente");
		printf("\n   Operacao cancelada");
	} else{
		printf("\n   Informe o valor que deseja inserir: ");
		scanf("%f", &saldo);
	
		printf("\n   Nome: %s\n", cli[i-1].nome);
		printf("   CPF: %s\n", cli[i-1].cpf);
	
		do{
			printf("\n\n   Confirmar?\n");
			printf("   1 - Sim\n");
			printf("   2 - Nao\n");
			scanf("%d", &op);
		
			if (op == 1){
				cli[i-1].saldo = cli[i-1].saldo + saldo;
				printf("   Saldo inserido com sucesso\n");
				printf("   Saldo atual: R$ %.2f", cli[i-1].saldo);
			} else if (op == 2){
				printf("   Operacao cancelada\n");
			} else{
				printf("   Erro. Digite uma opcao valida\n");
			}
		} while(op != 1 && op != 2);
	}
	
	getchar();	
}

	//FUNCAO CADASTRAR VEICULO

void cadastrarVeiculo(veiculo bike[20]){
	
	int recadastrar, op;
	
	do{
		printf("\n   CADASTRAR VEICULO\n");
		
		printf("\n   Marca: ");
		scanf ( "%[^\n]", bike[b].marca);
		strupr(bike[b].marca);
		fflush(stdin);
			do{
				printf("\n   Tamanho:\n");
				printf("   1 - INFANTIL\n");
				printf("   2 - ADULTO\n");
				scanf("%d", &op);
				
				if(op == 1){
					strcpy(bike[b].tam, "INFANTIL");
				} else if(op == 2){
					strcpy(bike[b].tam, "ADULTO");
				} else{
					printf("\n   Opcao invalida\n");
				}
			} while (op != 1 && op != 2);	
		//scanf ( "%[^\n]", bike[b].tam);
		printf("   Aro: ");
		scanf("%d", &bike[b].aro);
		fflush(stdin);
		strcpy(bike[b].status,"DISPONIVEL");
		bike[b].cod = bike[b].cod + 1;
	
		printf("\n   Veiculo cadastrado com sucesso CODIGO %d\n", bike[b].cod);
		bike[b+1].cod = bike[b].cod;
		b++;	
		fflush(stdin);
		getchar();
		system("cls");
		
		do{
			printf("\n   Deseja cadastrar outro veiculo?: \n");
			printf("   1 - Sim\n");
			printf("   2 - Nao\n\n");
			scanf(" %d", &recadastrar);
			
			if (recadastrar != 1 && recadastrar !=2){
				printf("\n   Opcao Invalida\n");
			}
		} while (recadastrar != 1 && recadastrar != 2);
		
		system("cls");
		fflush(stdin);		
	} while (recadastrar == 1);
	
}

	//FUNCAO CONSULTAR VEICULO

void consultarVeiculo(veiculo bike[20]){
	
	int i;
	
	printf("\n   CONSULTAR VEICULO\n");
	
	printf("\n   Informe o CODIGO do veiculo: ");
	scanf("%d", &i);
	
	if(i <= 1000 || i > b+1000){
		printf("\n   Veiculo inexistente");
		printf("\n   Operacao cancelada");
	} else {
		printf("\n   Codigo: %d\n", bike[i-1001].cod);
		printf("   Marca: %s\n", bike[i-1001].marca);
		printf("   Tamanho: %s\n", bike[i-1001].tam);
		printf("   Aro: %d\n", bike[i-1001].aro);
		printf("   Status: %s\n", bike[i-1001].status);
	}
	getchar();
}
	
	//FUNCAO RELATORIO GERAL VEICULO
	
void relatorioGeralVeiculo(veiculo bike[20]){
	
	int i;
	
	if(b == 0){
		printf("\n   Nenhum veiculo cadastrado");
	} else{
		printf("\n   RELATORIO GERAL\n");
		
		for(i = 0; i <= b-1; i++){
			printf("\n   Codigo: %d\n", bike[i].cod);
			printf("   Marca: %s\n", bike[i].marca);
			printf("   Tamanho: %s\n", bike[i].tam);
			printf("   Aro: %d\n", bike[i].aro);
			printf("   Status: %s\n", bike[i].status);	
		}	
	}	
	getch();
}	
	
	//FUNCAO EDITAR VEICULO

void editVeiculo(veiculo bike[20]){
	
	int i, bikeEdit;
	
	printf("\n   EDITAR VEICULO\n");
	
	printf("\n   Informe o CODIGO do veiculo: ");
	scanf("%i", &i);
	
	do{
		printf("\n   Informe o campo que deseja editar\n");
		printf("   1 - Marca\n");
		printf("   2 - Tamanho\n");
		printf("   3 - Aro\n");
		printf("   4 - Status\n");
		printf("   9 - Voltar\n");
		scanf("%d", &bikeEdit);
		
		system("cls");
		fflush(stdin);
		
		switch(bikeEdit){
			case 1:{
				printf("\n   Marca: ");
				scanf ( "%[^\n]", bike[i-1001].marca);
				strupr(bike[i-1001].marca);
				fflush(stdin);
				break;
			}
			case 2:{
				printf("\n   Tamanho: ");
				scanf ( "%[^\n]", bike[i-1001].tam);
				break;
			}
			case 3:{
				printf("\n   Aro: ");
				scanf("%d", &bike[i-1001].aro);
				fflush(stdin);
				break;
			}
			case 4:{
				printf("\n   Status: ");
				scanf ( "%[^\n]", bike[i-1001].status);
				break;
			}
			case 9:{
				break;
			}
			default:{
				printf("\n   Opcao Invalida\n");
				getchar();
				break;
			}
		
			fflush(stdin);
			getchar();	
		}		
	} while(bikeEdit != 9);
	
	printf("\n   Registro realizado com sucesso");
		
	fflush(stdin);
	getchar();
}

	//FUNCAO REGISTRAR LOCACAO

float locarVeiculo(cliente cli[100], veiculo bike[20], locacao loc[1000], empresa emp){
	
	int i, j, opCli, opBike, dias, opDias;
	float valorLocacao;
	
	printf("\n   REALIZAR LOCACAO\n");
	
	printf("\n   Informe o ID do locador: ");
	scanf("%d", &i);
	
	if( i <= 0 || i > c){
		printf("\n   Cliente inexistente");
		printf("\n   Operacao cancelada");
	} else {
		
		printf("\n\n   Nome: %s\n", cli[i-1].nome);
		printf("   CPF: %s\n", cli[i-1].cpf);
		printf("   Saldo: R$ %.2f\n", cli[i-1].saldo);
		
		printf("\n   Confirma?\n");
		printf("   1 - Sim\n");
		printf("   2 - Nao\n");
		scanf("%d", &opCli);
		
		system("cls");
		
		if(opCli == 2){
			
			printf("\n   Operacao cancelada");	
		} else if(opCli != 1 && opCli != 2){
			
			printf("\n   Opcao invalida, tente novamente");	
		} else{
			
			printf("\n   Informe o CODIGO do veiculo: ");
			scanf("%d", &j);
			
			if(j <= 1000 || j > b+1000){
				printf("\n   Veiculo inexistente");
				printf("\n   Operacao cancelada");
			} else {
				printf("\n\n   Marca: %s\n", bike[j-1001].marca);
				printf("   Tamanho: %s\n", bike[j-1001].tam);
				printf("   Aro: %d\n", bike[j-1001].aro);
				printf("   Status: %s\n", bike[j-1001].status);
	
				if(strcmp(bike[j-1001].status ,"LOCADO") == 0){
				printf("\n   Veiculo indisponivel para locacao");
				} else {
					printf("\n   Confirma?\n");
					printf("   1 - Sim\n");
					printf("   2 - Nao\n");
					scanf("%d", &opBike);
				
					system("cls");	
				}
	
				if (opBike == 2){
					printf("\n   Operacao cancelada");
				} else if(opBike != 1 && opBike != 2){
					printf("\n   Opcao invalida, tente novamente");
				} else {
					printf("\n   Informe a quantidade de dias para locacao: ");
					scanf("%d", &dias);
					
					valorLocacao = dias * 10;
					
					printf("\n   Locar por %d dias. Valor R$ %.2f. Confirma?\n", dias, valorLocacao);
					printf("   1 - SIM\n");
					printf("   2 - NAO\n");
					scanf("%d", &opDias);
					
					system("cls");
					
					if (opDias == 2){
					printf("\n   Operacao cancelada");
					} else if(opDias != 1 && opDias != 2){
					printf("\n   Opcao invalida, tente novamente");
					} else {
						
		
						if (cli[i-1].saldo >= valorLocacao){
		
							cli[i-1].saldo = cli[i-1].saldo - valorLocacao; //Ajuste de saldo do cliente
				
							emp.fundos += valorLocacao;
							cli[i-1].comprasTotal += valorLocacao;
				
							strcpy(bike[j-1001].status, "LOCADO"); //Alteracao do status do veiculo
			
							loc[l].rg = l + 1; 
							loc[l].id = cli[i-1].id;
							strcpy(loc[l].nome, cli[i-1].nome);   
							strcpy(loc[l].cpf, cli[i-1].cpf);     
							loc[l].idade = cli[i-1].idade;
							strcpy(loc[l].telefone, cli[i-1].telefone);
							loc[l].sexo = cli[i-1].sexo;
							loc[l].cod = bike[j-1001].cod;
							strcpy(loc[l].marca, bike[j-1001].marca);
							strcpy(loc[l].tam, bike[j-1001].tam);
							loc[l].aro = bike[j-1001].aro;
							loc[l].dias = dias;
							loc[l].valor = valorLocacao;
							strcpy(loc[l].user, usuarioAtual);				
			
							printf("\n Locacao realizada com sucesso REGISTRO: %d\n", loc[l].rg);
			
							l++;	
						} else {
							printf("\n   Cliente nao possui saldo suficiente");
						}
					}
				}
			}
		}
	}
	
	getch();
	return emp.fundos;
}

	//FUNCAO CONSULTAR LOCACAO
	
void consultarLocacao(locacao loc[1000]){
	
	int i;
	
	printf("\n   CONSULTAR LOCACAO\n");
	
	printf("\n   Informe o REGISTRO de locacao: ");
	scanf("%d", &i);
	
	if (i <= 0 || i > l){
		printf("\n   Registro nao localizado");
		printf("   Operacao cancelada");
	} else{
		printf("\n   CLIENTE\n\n");
		printf("   ID: %d\n", loc[i-1].id);
		printf("   Cliente: %s\n", loc[l-1].nome);
		printf("   CPF: %s\n", loc[l-1].cpf);
		printf("   Idade: %d\n", loc[l-1].idade);
		printf("   Sexo: %c\n", loc[l-1].sexo);
		printf("   Telefone: %s\n", loc[l-1].telefone);
	
		printf("\n   VEICULO\n\n");
		printf("   Codigo: %d\n", loc[l-1].cod);
		printf("   Marca: %s\n", loc[l-1].marca);
		printf("   Tamanho: %s\n", loc[l-1].tam);
		printf("   Aro: %d\n", loc[l-1].aro);
		
		printf("\n   Dias locados: %d\n", loc[l-1].dias);
		printf("   Valor da locacao: %.2f\n", loc[l-1].valor);
		printf("   Usuario responsavel: %s", usuarioAtual);		
	}
	getchar();
}	

	//FUNCAO REGISTRAR DEVOLUCAO

void registerDevol(veiculo bike[20], locacao loc[1000]){
	
	int i, op;
	
	printf("\n   REGISTRAR DEVOLUCAO\n");
	
	printf("\n   Informe o REGISTRO de locacao: ");
	scanf("%d", &i);
	
	do{
		printf("\n\n   CLIENTE\n\n");
		printf("   ID: %d\n", loc[i-1].id);
		printf("   Cliente: %s\n", loc[l-1].nome);
		printf("   CPF: %s\n", loc[l-1].cpf);
	
		printf("\n   VEICULO\n\n");
		printf("   Codigo: %d\n", loc[l-1].cod);
		printf("   Marca: %s\n", loc[l-1].marca);
		printf("   Tamanho: %s\n", loc[l-1].tam);
		printf("   Aro: %d\n", loc[l-1].aro);
	
		printf("\n   Confirmar devolucao?\n");
		printf("   1 - SIM\n");
		printf("   2 - NAO\n");
	
		scanf("%d", &op);
	
		if (op == 1 ){
		
			strcpy(bike[loc[i-1].cod-1001].status, "DISPONIVEL");
	
			printf("\n   Registro efetuado com sucesso\n\n");
			printf("   Status do veiculo CODIGO: %d alterado para ""Disponivel""", bike[loc[i-1].cod-1001].cod);
		} else if(op == 2){
			printf("\n   Operacao cancelada");	
		} else {
			printf("\n   Opcao invalida\n");
		}
	} while(op != 1 && op != 2);
	getchar();
}

