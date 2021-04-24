#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "ft_dictionary.h"
#include "ft_file.h"
#include "ft_file_io.h"

int	check_main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf ("Hay que leer el diccionario: %s\n", argv[1]);
		printf ("Hay que convertir el valor: %s\n", argv[2]);
	}
	else if (argc == 2)
	{
		printf ("Hay que leer el diccionario: %s\n", DEFAULT_DICT);
		printf ("Hay que convertir el valor: %s\n", argv[1]);
	}
	else
		printf ("Número de argumentos inválido\n");
	return (0);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	line_res;

	check_main(argc, argv);
	fd = ft_open_file(DEFAULT_DICT);
	if (fd == -1)
	{
		printf("Error Number % d\n", errno);
		perror("Program\n");
		return (1);
	}
	printf("Opened the fd = % d\n", fd);
	line_res = -2;
	while (line_res <= -2)
	{
		line_res = ft_readline(fd);
		printf("Read line return: %d\n", line_res);
	}
	
	if (ft_close_file(fd) < 0)
	{
		perror("Program");
		return (1);
	}
	printf("Closed the fd: %d\n", fd);
}
