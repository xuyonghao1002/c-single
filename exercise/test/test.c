#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N_VALUES 5


// size_t strlen(char *string)
// {
// 	int length = 0;
// 	while (*string++ != '\0')
// 	{
// 		length++;
// 	}
// 	return length;
// }

// 给数组赋值以及便利数组
void test1(){
	float values[N_VALUES];
	float *vp;
	for ( vp = &values[0]; vp < &values[N_VALUES]; )
	{
		*vp++ = 0;
	}

	for (size_t i = 0; i < N_VALUES; i++)
	{
		printf("%f\t", values[i]);
	}
}

void test2(){
	int harbor = 1;
	unsigned int result = (unsigned int)harbor << 24;
	printf("result: %x\n", result);
	printf("result: %d\n", result);
}

void test3(){
	const char* cmdline = "snlua bootstrap";
	int size = strlen(cmdline);
	char name[size+1];
	char args[size+1];
	int arg_pos;

	sscanf(cmdline, "%s", name);
	printf("%s, %d\n", name, strlen(name));
	arg_pos = strlen(name);
	if(arg_pos < size){
		while(cmdline[arg_pos] == ' '){
			arg_pos++;
		}
		strncpy(args, cmdline+arg_pos, size);
	} else {
		args[0] = '\0';
	}
	printf("%s, %d\n", args, strlen(args));
	
	const char* test = "";
	printf("%s, %d\n", test, strlen(test));
}

void test_clock_gettime(){
	struct timespec ts_realtime, ts_monotonic;

    clock_gettime(CLOCK_REALTIME, &ts_realtime);
    clock_gettime(CLOCK_MONOTONIC, &ts_monotonic);

    printf("Realtime seconds: %ld, nanoseconds: %ld\n", ts_realtime.tv_sec, ts_realtime.tv_nsec);
    printf("Monotonic seconds: %ld, nanoseconds: %ld\n", ts_monotonic.tv_sec, ts_monotonic.tv_nsec);
}

void test_bit(){
	// int res = (sizeof(size_t)-1)*8;
	// size_t test = (size_t)1 << res;
	// printf("result is %d, %d\n", sizeof(int), sizeof(size_t));
	// printf("test is %lx\n", test);
	int mask = (1 << 8) - 1;
	printf("result is %d\n", sizeof(unsigned int));

	float time = (4294967296 * 2.5 *4) / (1000*3600*24);
	printf("time is %f\n", time);
}

int main(int argc, char const *argv[])
{
	// test_clock_gettime();
	test_bit();
	return 0;
}