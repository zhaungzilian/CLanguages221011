#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<stdarg.h>

/*
author:zzy
time:2022.10.03
�����⣺stdio.h  �����ֱ������ͣ����������꣬���� ����File�ļ���IO����

*/

int fileIoFuction() {
	//����������
	//#define char TEXT = "�ı���������";
	//const int NUMBER = 22;
	char buff[1024]; //�������
	char c[] = "���Ƕ�ȡfread��������";
	int bufflen;
	char filename[] = "E://Users//ׯ����//Desktop//togos.txt";
	int del;
	int re;
	char newfilename[] = "E://Users//ׯ����//Desktop//chello.txt";

	//ָ�붨����
	FILE *fls; //�ļ�ָ��
	errno_t err; //��fopen_s���ʹ��
	fpos_t posttion; //��fsetpos���ʹ��

	
	//�߼���
	if (err = fopen_s(&fls,filename, "w+") != 0) {
		printf("�޷��򿪴��ļ�\n");
		exit(0);
	}
	

	fwrite(c,strlen(c)+1,1,fls); // д������
	fseek(fls, 0, SEEK_SET);//�鿴�ļ���ͷ fseek(file����ƫ������ƫ��λ�ã�seek_set�ļ���ͷ��seek_cur�ļ�ָ�뵱ǰλ�ã�seek_end�ļ���ĩβ��)
	fread(buff, strlen(c) + 1, 1, fls);//��ȡ����ʾ���� fread(�ڴ��ָ�룬Ԫ�ش�С��Ԫ�ظ�����file��)
	printf("%s\n", buff);

	fsetpos(fls, &posttion);//��ȡfile�ĳ�ʼλ��
	fputs("������ȫ�̸�", fls);
	bufflen = ftell(fls);
	printf("��ǰfile�ļ��ܴ�С = %d ", bufflen);

	//setbuf(stdout,buff);  ���建��
	//puts("this is puts txt");

	fflush(stdout);


	//�ر��ļ���
	//fclose(fls);

	//�޸��ļ���
	re = rename(filename, newfilename);
	if (re == 0) {
		printf("�޸����ֳɹ�");
	}
	else {
		printf("�޸�ʧ�ܣ�");
	}


	//ɾ��file��
	/*
	del = remove(filename);
	if (del == 0) {
		printf("ɾ���ɹ���");
	}
	else {
		printf("ɾ��ʧ�ܣ�");
	}
	
	*/
	

	//fputs("hellopostion",fls);//����������
	//��ӡ��ָ���ļ���
	//fprintf(fls, "%s", "hellow");




	return(1);

};

int fileBuffFunction() {
	char buff[1024];
	memset(buff,'\0',sizeof(buff));

	fprintf(stdout, "����ȫ����\n");
	setvbuf(stdout,buff,_IOFBF,1024);
	fprintf(stdout, "aaaaaaaaaaa\n");
	fprintf(stdout, "�������������buff�� buff\n");

	fflush(stdout);//ˢ����������

	fprintf(stdout, "bbbbbbbbbbb\n");
	fprintf(stdout, "��ʼ��Ϣ5��\n");

	Sleep(5);

	return(0);
		

};

int fileIOFunction2() {
	errno_t err;
	FILE* file;
	char buffer[L_tmpnam]; //tmmpnamһ��
	if(err = tmpfile_s(&file)) { //������ʱ�ļ�
		printf("��ʱ�ļ�\n");
	};//��ʱ�ļ���
	
	fclose(file);
	return(0);
}

int printfTest() {
	//FILE* fl;
	char test[] = "ceshi";
	int tests;
	//1��ͨ��ӡ
	//printf("test���ڴ�ָ���ַΪ�� %c \n", &test);
	//2 ���뵽file steam�в���ӡ
	//fprintf();
	//3 
	//vfprintf();

	

	return(0);
}

//sdarg 
int stdargDemo(int, ...);
int stdargDemo(int numb, ...) {

	int val = 0;
	va_list ap;
	int i;

	va_start(ap, numb);
	for (i = 0; i < numb; i++) {
		val += va_arg(ap, int);
	}
	va_end(ap);

	return val;
}

//������
int fileOutputStreamFunction() {
	FILE *file;
	errno_t err;
	char filename[] = "E://Users//ׯ����//Desktop//scan.txt";
	char txt[] = "zhuang, join , helloc++";
	char str1[10];
	char str2[10];
	char str3[10];
	//int year;

	//�����ļ���
	if(err = fopen_s(&file, filename, "w+") != 0) {
		printf("�ļ�����ʧ�ܣ�");
		exit(0);
	}
	//��������
	fputs(txt,file);
	rewind(file);

	fscanf_s(file, "%s %s %s", str1,10, str2,10, str2,10);
	

	printf("Read String1 |%s|\n", str1);
	printf("��ȡ�ַ���2 |%s|\n", str2);
	printf("Read String3 |%s|\n", str3);
	fclose(file);
	printf("�˳�������");
	return 0;
}


int main() {
	
	fileOutputStreamFunction();
	// printf(" ����֮��Ϊ�� %d \n", stdargDemo(3, 3, 4, 3));
	//printfTest();
	//fileIOFunction2();
	//fileBuffFunction();
	//fileIoFuction();
	printf("%s\n","��ӡ�ɹ�");

};