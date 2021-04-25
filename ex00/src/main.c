#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "ft_dictionary.h"
#include "ft_file_io.h"
#include "ft_num2words.h"
#include "ft_strings_line.h"
#include "ft_others.h"

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
	char	**lines;
	t_dict	*dict;
	char	*str;

	str = (char *) malloc(300);
	check_main(argc, argv);
	lines = ft_filegetlines(DEFAULT_DICT);
	dict = ft_filldict(lines);
	// ft_dictprint(dict);
	ft_dictsort(dict);
	// ft_dictprint(dict);
	ft_num2words(ft_atoi(argv[1]), dict, str, ft_numdigits(ft_atoi(argv[1])));
	printf ("\n\n%u is said:\t%s\n",ft_atoi(argv[1]), str);
}
