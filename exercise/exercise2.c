#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct netpack {
	int id;
	int size;
	void * buffer;
};

struct uncomplete {
	struct netpack pack;
	struct uncomplete * next;
	int read;
	int header;
	int new_header;
};

typedef char* Strings[10];
typedef struct node
{
	int data;
	struct node *next;
}ANode;

typedef union chi
{
	int i;
	char a[sizeof(int)];
} CHI;




int main(int argc, char const *argv[])
{

	// struct uncomplete* uc = malloc(sizeof(struct uncomplete));
	// memset(uc, 0, sizeof(*uc));
	// printf("uc read is %d, header is %d, new_header is %d", uc->read, uc->header, uc->new_header);


	int buffer[3];
	int len = 0x000012;
	buffer[0] = (len >> 16) & 0xff;
	buffer[1] = (len >> 8) & 0xff;
	buffer[2] = len & 0xff;

	for (int i = 0; i < 3; i++)
	{
		printf("buffer index %d is %X \n", i, buffer[i]);
	}

	int r = (int)buffer[0] << 16 | (int)buffer[1] << 8 | (int)buffer[2];
	printf("res is %X", r);


	return 0;
}
