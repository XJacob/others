#include <stdio.h>
#include <string.h>

#define NUM 10
static int input[NUM] = {-9, 19, 1, -1, 0, -2, 100, 1, 999, 77};
static int output[NUM];

/* exchange by xor */
void swap(int *i, int *j)
{
	*i = *i^*j;
	*j = *i^*j;
	*i = *i^*j;
}

void bubble_sort(int *in, int num)
{
	int i,j, tmp;

	for(i=0; i<(num-1); i++)
		for(j=0; j<num-1-i; j++)
			if (in[j] > in[j+1]) {
				swap(&in[j], &in[j+1]);
			}

	printf("bubble sort: ");
	for(i=0; i<NUM; i++)
		printf(" %d ", in[i]);
	printf("\n");
}

void reverse(int *in, int num)
{
	int i;

	for(i=0;i<num/2;i++) {
		swap(in+i, in+num-1-i);
	}

	printf("reverse: ");
	for(i=0; i<NUM; i++)
		printf(" %d ", in[i]);
	printf("\n");
}

void binary_search(int *in, int pattern, int num)
{
	int low=0, high=num-1, mid;

	while (high >= low) {
		mid = (high + low) /2;
		if (*(in + mid) == pattern) {
			printf("found!! position:%d\n", mid);
			return;
		}
		if (*(in + mid) > pattern)
			high = mid  - 1;
		else
			low = mid + 1;

		printf("%d %d %d %d %d\n", *(in + mid) , pattern, mid, low, high);
	}

	printf("NOT found!!\n");
}

int isPowerOf2(int x)
{
	return (x & -x) == x;
}

/* x > y ? 1 : 0, can't use if */
int ternaryCondition(int x, int y)
{
	int i = 0;
	(x > y) && (i=1);
	return i;
}

void main(void)
{
	int i;

	printf("intput: ");
	for(i=0; i<NUM; i++)
		printf(" %d ", input[i]);
	printf("\n");

	memcpy(output, input, sizeof(input));
	bubble_sort(output, sizeof(output)/sizeof(int));

	binary_search(output, -1, NUM);

	memcpy(output, input, sizeof(input));
	reverse(output, sizeof(output)/sizeof(int));

	printf("ternaryCondition:%d\n", ternaryCondition(6, 9));
}
