#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<stdarg.h>

/*
author:zzy
time:2022.10.03
基础库：stdio.h  共三种变量类型：库变量，库宏，函数 用于File文件的IO操作

*/

int fileIoFuction() {
	//常量定义区
	//#define char TEXT = "文本常量内容";
	//const int NUMBER = 22;
	char buff[1024]; //缓存变量
	char c[] = "这是读取fread函数测试";
	int bufflen;
	char filename[] = "E://Users//庄泽钦//Desktop//togos.txt";
	int del;
	int re;
	char newfilename[] = "E://Users//庄泽钦//Desktop//chello.txt";

	//指针定义区
	FILE *fls; //文件指针
	errno_t err; //与fopen_s配合使用
	fpos_t posttion; //与fsetpos配合使用

	
	//逻辑区
	if (err = fopen_s(&fls,filename, "w+") != 0) {
		printf("无法打开此文件\n");
		exit(0);
	}
	

	fwrite(c,strlen(c)+1,1,fls); // 写数数据
	fseek(fls, 0, SEEK_SET);//查看文件开头 fseek(file流，偏移量，偏移位置（seek_set文件开头，seek_cur文件指针当前位置，seek_end文件的末尾）)
	fread(buff, strlen(c) + 1, 1, fls);//读取并显示数据 fread(内存块指针，元素大小，元素个数，file流)
	printf("%s\n", buff);

	fsetpos(fls, &posttion);//获取file的初始位置
	fputs("内容完全铺盖", fls);
	bufflen = ftell(fls);
	printf("当前file文件总大小 = %d ", bufflen);

	//setbuf(stdout,buff);  定义缓冲
	//puts("this is puts txt");

	fflush(stdout);


	//关闭文件流
	//fclose(fls);

	//修改文件名
	re = rename(filename, newfilename);
	if (re == 0) {
		printf("修改名字成功");
	}
	else {
		printf("修改失败！");
	}


	//删除file流
	/*
	del = remove(filename);
	if (del == 0) {
		printf("删除成功！");
	}
	else {
		printf("删除失败！");
	}
	
	*/
	

	//fputs("hellopostion",fls);//输入数据流
	//打印到指定文件中
	//fprintf(fls, "%s", "hellow");




	return(1);

};

int fileBuffFunction() {
	char buff[1024];
	memset(buff,'\0',sizeof(buff));

	fprintf(stdout, "启用全缓冲\n");
	setvbuf(stdout,buff,_IOFBF,1024);
	fprintf(stdout, "aaaaaaaaaaa\n");
	fprintf(stdout, "将输出流保持在buff中 buff\n");

	fflush(stdout);//刷新流缓冲区

	fprintf(stdout, "bbbbbbbbbbb\n");
	fprintf(stdout, "开始休息5秒\n");

	Sleep(5);

	return(0);
		

};

int fileIOFunction2() {
	errno_t err;
	FILE* file;
	char buffer[L_tmpnam]; //tmmpnam一个
	if(err = tmpfile_s(&file)) { //创建临时文件
		printf("临时文件\n");
	};//临时文件流
	
	fclose(file);
	return(0);
}

int printfTest() {
	//FILE* fl;
	char test[] = "ceshi";
	int tests;
	//1普通打印
	//printf("test的内存指针地址为： %c \n", &test);
	//2 输入到file steam中并打印
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

//输入流
int fileOutputStreamFunction() {
	FILE *file;
	errno_t err;
	char filename[] = "E://Users//庄泽钦//Desktop//scan.txt";
	char txt[] = "zhuang, join , helloc++";
	char str1[10];
	char str2[10];
	char str3[10];
	//int year;

	//创建文件流
	if(err = fopen_s(&file, filename, "w+") != 0) {
		printf("文件创建失败！");
		exit(0);
	}
	//输入数据
	fputs(txt,file);
	rewind(file);

	fscanf_s(file, "%s %s %s", str1,10, str2,10, str2,10);
	

	printf("Read String1 |%s|\n", str1);
	printf("读取字符串2 |%s|\n", str2);
	printf("Read String3 |%s|\n", str3);
	fclose(file);
	printf("退出。。。");
	return 0;
}


int main() {
	
	fileOutputStreamFunction();
	// printf(" 两数之和为： %d \n", stdargDemo(3, 3, 4, 3));
	//printfTest();
	//fileIOFunction2();
	//fileBuffFunction();
	//fileIoFuction();
	printf("%s\n","打印成功");

};