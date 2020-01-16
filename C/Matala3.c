/*
מגישים:
חן צלח 208730812
קוסטיה לסניצי 327274841
 */
 //////////////////////////////////////

typedef char* verylong;

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include <string.h>



verylong input_long(void);
verylong add_verylong(verylong vl1, verylong vl2);
verylong multiply_verylong(verylong vl1, verylong vl2);


void main()
{
	verylong a, b, c;
	do {
		printf("enter the first long integer: ");
		a = input_long();
	} while (!a);
	do {
		printf("enter the second long integer: ");
		b = input_long();
	} while (!b);
	c = add_verylong(a, b);
	printf("%s + %s = %s\n", a, b, c);
	free(c);
	c = multiply_verylong(a, b);
	printf("%s * %s = %s\n", a, b, c);
	free(c);
	free(a);
	free(b);
}

verylong input_long() // סעיף ב'
{
	int i;
	char tempstr[80];
	gets(tempstr, 80);
	verylong longnumstr = (verylong)malloc((strlen(tempstr) + 1));
	strcpy(longnumstr, tempstr);
	for (i = 1; i < strlen(longnumstr); i++) {
		if (longnumstr[i] > '9' || longnumstr[i] < '0') {
			printf("You need to enter only digits, try again.\n");
			return NULL;
		}
	}
	return longnumstr;
}

verylong add_verylong(const verylong vl1, const verylong vl2) // סעיף ג'
{

	int carry = 0;
	int sizemax = 0;
	int sizemin = 0;
	int j = 0;
	int i = 0, z = 0;


	if (strlen(vl1) >= strlen(vl2))
	{
		sizemax = strlen(vl1);
		sizemin = strlen(vl2);
	}
	else
	{
		sizemax = strlen(vl2);
		sizemin = strlen(vl1);
	}

	verylong sum = (verylong)malloc(sizemax + 2);

	j = strlen(vl1) - 1;
	i = strlen(vl2) - 1;
	z = sizemax;
	for (int c = 0; c < sizemin; c++)
	{
		int temp = (vl1[j] - 48 + vl2[i] - 48 + carry) % 10;
		sum[z] = temp + 48;
		carry = (vl1[j] - 48 + vl2[i] - 48 + carry) / 10;
		j--;
		i--;
		z--;
	}
	if (i == -1)
	{
		while (j >= 0)
		{
			int temp = (vl1[j] - 48 + carry) % 10;
			sum[z] = temp + 48;
			carry = (vl1[j] - 48 + carry) / 10;
			j--;
			z--;

		}
	}
	else
	{
		while (i >= 0)
		{
			int temp = (vl2[i] - 48 + carry) % 10;
			sum[z] = temp + 48;
			carry = (vl2[i] - 48 + carry) / 10;
			i--;
			z--;
		}
	}
	sum[0] = carry + '0';
	sum[sizemax + 1] = 0;
	return sum;
}

verylong multiply_verylong(const verylong vl1, const verylong vl2) // סעיף ד'
{
	int i = 0;
	int j = 0;
	int carry = 0;
	int z = 0;
	int counter = 0;
	const verylong big = malloc(80);
	const verylong small = malloc(80);

	if (strlen(vl1) >= strlen(vl2))
	{
		strcpy(big, vl1);
		strcpy(small, vl2);
	}
	else
	{
		strcpy(big, vl2);
		strcpy(small, vl1);
	}


	int multy_size = strlen(small) + strlen(big) + 1;
	verylong multy = (verylong)malloc(multy_size);

	for (i = 0; i < multy_size; i++)
	{
		multy[i] = '0';
	}
	multy[multy_size - 1] = '\0';

	z = multy_size - 2;

	for (j = strlen(small) - 1; j >= 0; j--)
	{
		counter++;
		for (i = strlen(big) - 1; i >= 0; i--)
		{
			int temp = ((big[i] - 48) * (small[j] - 48));
			int tmp2 = multy[z] - 48 + temp;
			multy[z] = tmp2 % 10 + 48;
			carry = tmp2 / 10;
			if (carry != 0)
			{
				multy[z - 1] = (multy[z - 1] - 48 + carry) + 48;
				carry = 0;
			}
			z--;
		}
		z = strlen(small) + strlen(big) - 1 - counter;
	}
	return multy;
}