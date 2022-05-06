#include <stdio.h>
#define RED		"\x1B[31m"
#define GRN		"\x1B[32m"
#define YEL		"\x1B[33m"
#define BLU		"\x1B[34m"
#define MAG		"\x1B[35m"
#define CYN		"\x1B[36m"
#define WHT		"\x1B[37m"
#define RESET	"\x1B[0m"
#define CLE "\e[1;1H\e[2J"

int num(int upper)
{
	int lower = 0;
	int numb = (rand() % (upper - lower + 1)) + lower;
	return(numb);
}

void rd_color(void)
{
	int tem = num(5);
	if (tem == 0)
		write(1, &RED, 6);
	if (tem == 1)
		write(1, &GRN, 6);
	if (tem == 2)
		write(1, &YEL, 6);
	if (tem == 3)
		write(1, &BLU, 6);
	if (tem == 4)
		write(1, &MAG, 6);
	if (tem == 5)
		write(1, &CYN, 6);
}

void noise(int loop, int size)
{
	int i = 0;
	int j = 0;
	int temp;

	while(i < loop)
	{
		while(j < size)
		{
			temp = num(105) + 21;
			rd_color();
			write(1, &temp, 1);
			//write(1, "#", 1);
			write(1, &RESET,5);
			j++;
		}
		write(1, "\n", 1);
		i++;
		j = 0;
	}
}

int main(void)
{
	noise(3000,30);
}