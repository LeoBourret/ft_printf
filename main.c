#include <stdio.h>
#include <stdlib.h>
#include "inc/ft_printf.h"

int		main()
{
	float n;
	float m;
	int *l;
	int *v;

	l = malloc(sizeof(int)* 10);
	v = malloc(sizeof(int)* 10);
	n = 42.421234;
	m = 4212345.42123456789;
    printf("Printing the value of a using %%n%n\n", v);
    ft_printf("Printing the value of a using %%n%n\n", l);
    printf("Printing the value of a using %%d%d\n", *v);
    printf("Printing the value of a using %%d%d\n\n", *l);
    printf("Printing the value of a using %%f  %f\n", n);
    printf("Printing the value of a using %%e  %e\n", n);
    printf("Printing the value of a using %%g  %g\n\n", n);
    printf("Printing the value of a using %%f  %f\n", m);
    printf("Printing the value of a using %%e  %e\n", m);
    printf("Printing the value of a using %%g  %g\n\n", m);
	printf("Printing the value of a using %%f  %.2f\n", m);
    printf("Printing the value of a using %%e  %.2e\n", m);
    printf("Printing the value of a using %%g  %.2g\n\n", m);
	printf("Printing the value of a using %%f  %.3f\n", m);
    printf("Printing the value of a using %%e  %.3e\n", m);
    printf("Printing the value of a using %%g  %.3g\n\n", m);


	return (0);
}
