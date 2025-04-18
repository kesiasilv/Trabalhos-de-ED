#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	int pid;
	
	printf("eu sou o pai %d e vou criar um filho \n", getpid());
	
	pid=fork(); /*criacao do filho*/
	
	if(pid==-1){/*erro*/
	perror("impossivel de criar um filho\n");
	}
	
	else if(pid==0){/*acoes do filho*/
	printf("\tOi, eu sou o processo %d, o filho\n", getpid());
	printf("\tO dia esta otimo hoje não acha?");
	printf("bom desse jeito vou acabar me instalando para sempre\n");
	printf("\tou melhor, assim espero!\n");
	
	for(;;);/*o filho se bloqueia em um loop infinito*/	
	}
	
	else{/*acoes do pai*/
	sleep(1);/*para separar bem as saidas do pai e do filho*/
	printf("As luzes comecaram a se apagar para mim, %d\n", getpid());
	printf("Minha hora chegou : adeus, %d, meu filho\n", pid);
	/*e o pai morre de causas naturais*/
	}
	exit(0);
}
