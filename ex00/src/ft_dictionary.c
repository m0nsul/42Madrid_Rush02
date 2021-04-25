#include <stdlib.h>
#include <stdio.h>
#include "ft_dictionary.h"
#include "ft_split.h"
#include "ft_strings_line.h"
#include "ft_file_io.h"
#include "ft_str.h"
#include "ft_enums.h"
#include "ft_others.h"

t_dict 	*ft_dictcreate(int nlines)
{
	t_dict	*dict_new;
	dict_new = (t_dict	*) malloc(sizeof(t_dict));
	if (!(dict_new))
		return (NULL);
	dict_new->size_max = nlines;
	dict_new->size = 0;
	dict_new->words = (t_dict_word **) malloc(nlines * sizeof(t_dict_word *));
	return (dict_new);
}

void	ft_destroydict(t_dict *dict)
{
	free(dict);
}

t_dict_word	*ft_dictaddword(t_dict 	*dict, char *text, int value, t_bool is_valid)
{
	t_dict_word	*word;

	word = (t_dict_word	*) malloc(sizeof(t_dict_word));
	word->size = ft_strlen(text);
	word->word = ft_strdup(text);
	word->value = value;
	word->pow = ft_numdigits(value);
	word->is_valid = is_valid;
	dict->words[dict->size++] = word;
	return (word);
}

void	ft_dictsort(t_dict 	*dict)
{
	int	i;
	int	j;
	t_dict_word *swap;
	i = 0;
	while (i < dict->size - 1)
	{
		j = 0;
		while (j < dict->size - i - 1)
		{
			if (dict->words[j]->value < dict->words[j + 1]->value)
			{
				swap = dict->words[j];
				dict->words[j] = dict->words[j + 1];
				dict->words[j + 1] = swap;
			}
			j++;
		}
		i++;
	}
}

t_dict	*ft_filldict(char **lines)
{
	t_dict	*dict;
	char	**duple;
	int		i;
	int		nlines;

	nlines = ft_getlinesnum(lines);
	dict = ft_dictcreate(nlines);
	i = 0;
	while (i < nlines)
	{
		duple = ft_split(lines[i], ": ");
		if (ft_strlen(duple[0]) <= 10)
			ft_dictaddword(dict, duple[1], ft_atoi(duple[0]), TRUE);
		else
			ft_dictaddword(dict, duple[1], ft_atoi(duple[0]), FALSE);
		ft_split_free(duple);
		i++;
	}
	return (dict);
}


void	ft_dictprint(t_dict 	*dict)
{
	int	i;
	printf("\n\n_______DICT\t");
	printf("Dict size: %d\t", dict->size);
	printf("Dict size_max: %d\n", dict->size_max);
	i = 0;
	while (i < dict->size)
	{
		printf("\n\t______WORD %d\t", i);
		printf("Word valid: %d\t", dict->words[i]->is_valid);
		printf("Word size: %d\t", dict->words[i]->size);
		printf("Word pow: %d\t", dict->words[i]->pow);
		printf("Word value: %d\t", dict->words[i]->value);
		printf("Word word: %s", dict->words[i]->word);

		i++;
	}
}
