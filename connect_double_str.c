#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/time.h>
#define TRACE_STAT_FILE "/per_cpu/cpu0/stats"

int main(void){
	printf("%s\n","feifei_yuan""liu");
	printf("%s\n","feifei_yuan"TRACE_STAT_FILE);
	return 0;
}