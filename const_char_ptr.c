#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/time.h>

// 实际上保证了，传入的值不会被改变
void get_ptr(const char *ptr){
	ptr[2]='j';//报错向只读位置赋值
	printf("ptr is %s\n",ptr);
}

int main(void){
	char str[] = "feifei_yuan";
	const char *ptr;
	ptr=str;
	printf("one str is %s\n",str);
	printf("one ptr is %s\n", ptr);
	str[2]='h';
	printf("one str is %s\n",str);
	printf("one ptr is %s\n", ptr);
	
	// ptr是指向char *类型的常量, 不能用ptr来修改指向的内容
	// 但是并不是意味着str就是常量，只是他对于ptr而言是常量
	// 还是可以通过str来修改指向的内容的
	get_ptr(ptr);
	return 0;
}