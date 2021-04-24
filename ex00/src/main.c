#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "ft_dictionary.h"
#include "ft_file.h"
#include "ft_file_io.h"
#include "ft_split.h"
#include "ft_strings_line.h"

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

t_dict	*ft_crete_dict(char **lines)
{
	t_dict	*dict;
	char	**duple;
	int		i;
	int		nlines;

	nlines = ft_getlinesnum(lines);
	dict = ft_dictcreate(nlines);
	i = 0;
	printf ("valo");
	while (i < nlines)
	{
		//printf ("Linea: %s\t Valid: %d\n",lines[i],  ft_checkline(lines[i]));
		duple = ft_split(lines[i], ": ");
		printf ("valor numerico: %s\tPalabra: %s\n", duple[0], duple[1]);
		ft_dictaddword(dict, duple[1], ft_atoi(duple[0]));
		ft_free_split(duple);
		i++;
	}
	printf ("Dict size: %d\n", dict->size);
	return (dict);
}

int	main(int argc, char **argv)
{
	char	**lines;
	int		nlines;
	t_dict	*dict;
	
	nlines = 0;
	check_main(argc, argv);
	
	lines = ft_filegetlines(DEFAULT_DICT);
	nlines = ft_getlinesnum(lines);
	dict = ft_crete_dict(lines);
	ft_dictprint(dict);
	ft_dictsort(dict);
	ft_dictprint(dict);
	
}
