#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "ft_dictionary.h"
#include "ft_file.h"
#include "ft_file_io.h"
#include "ft_split.h"

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
	//char	*filestr;
	char	**lines;
	char	**duple;
	int		i;
	int		nlines;
	// t_dict		*dict;

	check_main(argc, argv);
	// dict = ft_dictcreate();
	// dict->size = 0;
	//filestr = ft_filetostr(DEFAULT_DICT);
	lines = ft_filegetlines(DEFAULT_DICT);
	nlines = ft_getlinesnum(lines);
	i = 0;
	while (i < nlines)
	{
		duple = ft_split(lines[i], ": ");
		printf ("valor numerico: %s\tPalabra: %s\n", duple[0], duple[1]);
		ft_free_split(duple);

		i++;
	}



}
