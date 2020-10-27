int		main()
{
	int i;

	i = 42;
	ft_printf("\t\tCONVERTION OF 'c'\n\n");
	ft_printf("char %c char\n", 'l');
	printf("char %c char\n\n", 'l');
	ft_printf("char%2c char\n", 'l');
	printf("char%2c char\n\n", 'l');
	ft_printf("char %-2cchar\n", 'l');
	printf("char %-2cchar\n\n", 'l');
	ft_printf("char%*c char\n", 2, 'l');
	printf("char%*c char\n\n", 2, 'l');
	ft_printf("char %-*cchar\n", 2, 'l');
	printf("char %-*cchar\n", 2, 'l');

	ft_printf("\t\tCONVERTION OF 's'\n\n");
	ft_printf("ft_printf is %s !\n", "awesome");
	printf("ft_printf is %s !\n\n", "awesome");
	ft_printf("ft_printf is %.2s !\n", "awesome");
	printf("ft_printf is %.2s !\n\n", "awesome");
	ft_printf("ft_printf is%8s !\n", "awesome");
	printf("ft_printf is%8s !\n\n", "awesome");
	ft_printf("ft_printf is %-8s!\n", "awesome");
	printf("ft_printf is %-8s!\n\n", "awesome");
	ft_printf("ft_printf is%8.5s !\n", "awesome");
	printf("ft_printf is%8.5s !\n\n", "awesome");
	ft_printf("ft_printf is %-8.5s!\n", "awesome");
	printf("ft_printf is %-8.5s!\n\n", "awesome");
	ft_printf("ft_printf is %-8.*s!\n", 6, "awesome");
	printf("ft_printf is %-8.*s!\n\n", 6, "awesome");

	ft_printf("\t\tCONVERTION OF 'p'\n\n");
	ft_printf("address of i = %p\n", &i);
	printf("address of i = %p\n\n", &i);
	ft_printf("address of i =%16p\n", &i);
	printf("address of i =%16p\n\n", &i);
	ft_printf("address of i =%*p\n", 16, &i);
	printf("address of i =%*p\n\n", 16, &i);

	ft_printf("\t\tCONVERTION 'd' 'i' 'u'\n\n");
	ft_printf
	return (0);
}

