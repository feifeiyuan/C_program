#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <sys/time.h>
#define TRACE_STAT_FILE "/per_cpu/cpu0/stats"
#define BUFFER_SIZE	256

static int get_trace_ts(const char *ts){
	FILE *fp;
	char buffer[BUFFER_SIZE];
	
	fp=fopen("trace","r");
	if(!fp){
		// 后面不一定需要加上最后一个参数
		fprintf(stderr,"fail open"TRACE_STAT_FILE);
	}
	
	// 循环读取按照指定的大小读取buffer的内容，比以前我按行读取要好一些，从程序的角度
	while(fgets(buffer,BUFFER_SIZE,fp)){
		//buffer的内容不等于now is
		//printf("%s\n",buffer);
		
		// 还有做了这个判断之后不就是什么都没有了吗？
		if(!strstr(buffer,"now ts")){
			continue;
		}
		//为什么要在这里关闭文件呢？
		printf("%s\n",buffer);
		fclose(fp);
		
		// buffer是输入的字符串，第二次是指定的字符串格式，ts为格式化之后的结果
		// 失败返回-1
		if(sscanf(buffer,"%*[^:]:%lf",ts) == 1){
			return 0;
		}
	}
	
	// 如果文件为空，则关闭,所以就是为什么走了两次close
	fclose(fp);
	return -1;
	
}
int main(void){
	char ts[BUFFER_SIZE];
	char str[]="yuan";
	if(strstr(str,"yuan")){// C语言判断两个字符串是否相等
		printf("yes equal");
	}
	get_trace_ts(ts);
	return 0;
}