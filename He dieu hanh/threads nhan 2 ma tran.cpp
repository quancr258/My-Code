#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
struct matrix
{
	char link[100];
	int n; //so hang
	int m; //so cot
	int **A;
};
int num_thrd = 20;
struct matrix fileA;
struct matrix fileB;
struct matrix fileC;
void *readFile(void *arg);
void *multi(void *arg);
int main()
{
	int i,j;
	pthread_t readFileA, readFileB;
	strcpy(fileA.link,"matranA.txt");
	strcpy(fileB.link,"matranB.txt");
	//thread thu 1 doc ma tran A
	pthread_create(&readFileA,NULL,readFile,(void*)&fileA);
	//thread thu 2 doc ma tran B
	pthread_create(&readFileB,NULL,readFile,(void*)&fileB);
	//Doi den khi 2 thread doc xong file
	pthread_join(readFileA,NULL);
	pthread_join(readFileB,NULL);
	//Kiem tra ma tran X co the nhan voi ma tran B khong
	if(fileA.m != fileB.n)
	{
		//Ma tran A khong the nhan voi ma tran B
		printf("Hai ma tran nay khong the nhan voi nhau\n");
		return 0;
	}
	//ma tran A co the nhan voi ma tran B
	fileC.n = fileA.n;
	fileC.m = fileB.m;
	fileC.A = (int**)malloc((fileC.n + 100)*sizeof(int*));
	for(i=0;i<fileC.n;i++)
		fileC.A[i] = (int*)malloc(fileC.m * sizeof(int*));
	pthread_t *thread;
	thread = (pthread_t*)malloc(num_thrd * sizeof(pthread_t));
	for(i=0;i<num_thrd;i++)
	{
		if(pthread_create(&thread[i],NULL,multi,(void*)i) != 0)
		{
			perror("Khong the tao thread");
			free(thread);
			exit(-1);
		}
	}
	for(i=0;i<num_thrd;i++)
		pthread_join(thread[i],NULL);
	//ghi ket qua vao file ketqua.txt
	FILE *file;
	file = fopen("ketqua.txt","wt");
	fprintf(file,"%d%d\n",fileC.n,fileC.m);
	fflush(file);
	for(i=0;i<fileC.n;i++)
	{
		for (j=0;j<fileC.m;j++)
			fprintf(file,"%d",fileC.A[i][j]);
			fprintf(file,"\n");
	}
	fclose(file);
	printf("Ket qua da duoc luu vao file ketqua.txt\n+");
	printf("Hoan tat!\n");
	return 0;
}
void *readFile(void *arg)
{
	struct matrix *temp = (struct matrix*) arg;
	FILE *file;
	file = fopen(temp->link,"rt");
	if(file == NULL)
	{
		printf("Khong the doc file! Vui long kiem tra file\n");
	}
	else
	{
		int i,j;
		fflush(file);
		fscanf(file,"%d",&temp->n);
		fscanf(file,"%d",&temp->m);
		temp->A = (int**)malloc(temp->n * sizeof(int*));
		for(i=0;i<temp->n;i++)
			temp->A[i] = (int*)malloc(temp->m * sizeof(int));
		for(i=0;i<temp->n;i++)
			for(j=0;j<temp->m;j++)
				fscanf(file,"%d",&temp->A[i][j]);
	}
}
void *multi(void *arg)
{
	int s = *((int*)arg);
	int from = (s *fileA.n)/num_thrd;
	int to = ((s+1) *fileA.n)/num_thrd;
	int i,j,k;
	int temp = 0;
	for(i=from;i<to;i++)
	{
		for(j=0;j<fileB.m;j++)
		{
			fileC.A[i][j] = 0;
			for(k=0;k<fileA.m;k++)
				fileC.A[i][j] += fileA.A[i][k] * fileB.A[k][j];
		}
	}
	pthread_exit(NULL);
}
