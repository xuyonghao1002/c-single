#include <stdio.h>
#include <stdlib.h>

#define N_VALUES 5


size_t strlen(char *string)
{
	int length = 0;
	while (*string++ != '\0')
	{
		length++;
	}
	return length;
}



int main(int argc, char const *argv[])
{

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

	printf("\n");
    system("pause");
	return 0;
}
