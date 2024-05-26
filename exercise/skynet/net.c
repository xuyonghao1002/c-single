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
	
	return 0;
}
