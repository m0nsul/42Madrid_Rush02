#ifndef FT_DICTIONARY_H
# define	FT_DICTIONARY_H

# define	DEFAULT_DICT "numbers.dict"

typedef struct s_dict_word
{
	unsigned int	value;
	char			*str;

}	t_dict_word;

typedef struct s_dict
{
	char			*path;
	int				size;
	t_dict_word		*entries;
}	t_dict;

#endif