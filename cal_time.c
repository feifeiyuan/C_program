#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/time.h>

int main(void){
	float timeuse_start=0.0;
	float timeuse_end=0.0;
	float timeuse_space=0.0;
	struct timeval start;
	struct timeval end;
	gettimeofday(&end, NULL);
	gettimeofday(&start, NULL);

	
	timeuse_start=start.tv_usec;
	printf("start timeuse_start is %f\n", timeuse_start);
	timeuse_end=end.tv_usec;
	printf("start timeuse_end is %f\n", timeuse_end);
	
	timeuse_space=(1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec - start.tv_usec);
	printf("start timeuse_space is %f\n", timeuse_space);
	return 0;
}