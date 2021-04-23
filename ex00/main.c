#include <unistd.h>
#include <stdio.h>
#include <errno.h>

//https://github.com/Caceresenzo/My-School-42-Piscine-Experience/blob/master/rush02:%20C%20Piscine%20Rush%2002/ex00/srcs/ft_number_dictionary_io.c

#define DEFAULT_DICT "numbers.dict"

int	ft_open_file(char *path);

typedef struct s_dict_entry
{
	unsigned int	value;
	char			*str;

}	t_dict_entry;

typedef struct s_dict
{
	char			*path;
	int				size;
	t_dict_entry	*entries;
}	t_dict;

int	check_main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf ("\nHay que leer el diccionario: %s", argv[1]);
		printf ("\nHay que convertir el valor: %s", argv[2]);
	}
	else if (argc == 2)
	{
		printf ("\nHay que leer el diccionario: %s", DEFAULT_DICT);
		printf ("\nHay que convertir el valor: %s", argv[1]);
	}
	else
		printf ("\nNúmero de argumentos inválido");
	return (0);
}

int	main(int argc, char **argv)
{
	int	fd;

	check_main(argc, argv);
	fd = ft_open_file(DEFAULT_DICT);
	if (fd == -1)
	{
		printf("\nError Number % d", errno);
		perror("\nProgram");
		return (1);
	}
	printf("\nopened the fd = % d", fd);
	if (close(fd) < 0)
	{
		perror("\nProgram");
		return (1);
	}
	printf("\nclosed the fd.");
}
