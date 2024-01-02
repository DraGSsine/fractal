#include <stdio.h>
int main()
{
	double z = 0.0;
	double c = -2;


	int y = 1;
	while (z < 2.01)
	{
		z = z * z + c;
		printf("%f\n",z);
		y++;
	}
}
