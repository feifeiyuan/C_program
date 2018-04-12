#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/time.h>
#include <errno.h>


static inline int bad_filename(const char *filename){
	const char *ptr;
	ptr=filename;
	
	//printf("filename is %s\n",ptr );
	if(*ptr == '-'){
		// 单个字符需要带*
		printf("filename is ERROR %c\n", *ptr);
		
		//写入到标准输出里面去，可以视为写入到一个文件里面去
		fprintf(stderr,"bad_filename is %c\n", *ptr);
		return EINVAL;
	}
	
	// 遍历字符串更加优良的方法
	for(; *ptr; ptr++) {
		printf("%c", *ptr);
		if(*ptr<32||*ptr=='>'||*ptr=='<'){
			fprintf(stderr, isprint(*ptr)?"bad character a":"bad character b",*ptr);
			return EINVAL;
		}
	}

	return 0;
}


int main(void){
	char str[] = "idelstate--trace -f mytrace -t 60 -p -c -w -o idle-report";
	//bad_filename(str);
	char ch='u';
	//isprint()判断字符是否可打印,因为asic表里面很多都是无法打印的
	printf("char is %c\n", isprint('j') ?ch:'n');
	return 0;
}