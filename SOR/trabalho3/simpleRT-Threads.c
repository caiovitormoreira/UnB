#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// ============================
void *threads_trabalhadores(void *blocksize);
void process_lock();
void process_unlock();
int receive_j();
// ============================




int num_trabalhadores;
pthread_mutex_t lock; //stuff from mutex. dont ask me.

//declarando matrizes
int a [1024][1024];
int b [1024][1024];
int c [1024][1024];//resultado

//declarando variaveis de varredura da matriz
int varredor_i=0;
int varredor_j=0;
int i=0;
int j=0;

int main(int argc, char *argv[]) {
	/**
	* Verifica se o usuário colocou a quantidade de processoas a serem criados
	*/
	if (argc < 2) {
		printf("Especifique o numero de trabalhadores -> $ %s <numero de trabalhadores>\n", argv[0] );
		exit(1);
	}
	num_trabalhadores = strtol(argv[1], NULL, 10);

	//preencher as matrizes a e b
	for (int i = 0; i < 1024; ++i)
	{
		for (int j = 0; j < 1024; ++j)
		{
			a[i][j] = 1;
			b[i][j] = 2;
			//c[i][j] = 0;
		}
	}

	//--start and check of mutex--
	if (pthread_mutex_init(&lock, NULL) != 0) {
		printf("\n Mmutex init failed. Mutex sucks\n");
		return 1;
	}


	//array contendo o numero maximo de threads definido ao início do programa
	pthread_t trabalhadores[num_trabalhadores];
	// Thread que vai executar o traçado de raios
	int thread_trabalhadora;

	//isso é o for de criação de threads
	for(int b = 0; b < num_trabalhadores; b++) {
		thread_trabalhadora = pthread_create(&trabalhadores[b], NULL, threads_trabalhadores, NULL);
		if(thread_trabalhadora){
			printf("Error criacao de threads");
		}
	}

	for(int k = 0; k < num_trabalhadores; k++) {
		//desacopla as threads que estavam em execução
		pthread_join(trabalhadores[k], NULL);
	}
	
	
	pthread_mutex_destroy(&lock);
	//termina a thread pai
	pthread_exit(NULL);
	return 0;
}

void *threads_trabalhadores(void *blocksize){

	printf("hello\n");

	do{ // enquanto i <1024
		process_lock(); 	//bloqueia a funcao de receber coluna
		j = receive_j();	//recebe coluna
		process_unlock();	//desbloqueia
		
		if(j<1024){ // enquanto j<1024
			c[i][j] = 0;		//zera c(i,j)
			for(int n=0; n<1024; n++){
				c[i][j] = c[i][j] + (a[i][n])*(b[n][j]);// calcula c(i,j)
				printf("C[%d][%d] = %d\n", i, j, c[i][j]);
			}
		}
		//printf("C[%d][%d] = %d\n", i, j, c[i][j]);
    }while(i<1024);
    
    printf("thread's mission accomplished\n");
}

int receive_j(){ 
	//funcao para receber um J
	//se o retorno for =1023, incremente i (só uma thread chega aqui)
	// if(varredor_j >= 1024){
	// 	return (1024);//codigo aleatorio pra mostrar q ja acabou
	// }
	int varredor_j_atual = (varredor_j % 1025);
	//resto da divisao por 1025. varredor_j incrementa indefinidamente,
	//varredor_j_atual incrementa em loop de 0 a 1024. assim nao preciso
	//zerar o global varredor_j. pode incrementar pra sempre
	// (N mod 1025)
	varredor_j++;
	if (varredor_j_atual == 1024)
	{
		i++;
		printf("thread incrementou i. i atual = %d\n" ,i);
	}
	// printf("thread pegou a coluna %d\n", varredor_j_atual);
	return varredor_j_atual;
}

void process_lock(void) {
	int ret;
	ret = pthread_mutex_lock(&lock);
	if (ret != 0)
		exit(EXIT_FAILURE);
}

void process_unlock(void) {
	int ret;
	ret = pthread_mutex_unlock(&lock);
	if (ret != 0)
		exit(EXIT_FAILURE);
}