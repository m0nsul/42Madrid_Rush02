#ifndef FT_DICTIONARY_H
# define	FT_DICTIONARY_H
# define	DEFAULT_DICT "numbers.dict.unsorted"
# include	"ft_enums.h"

typedef struct s_dict_word
{
	unsigned int	value;
	unsigned int	size;
	unsigned int	pow;
	t_bool			is_valid;
	char			*word;

}	t_dict_word;

typedef struct s_dict
{
	char 			*path;
	int				size;
	int				size_max;
	t_dict_word		**words;
}	t_dict;

t_dict 		*ft_dictcreate(int nlines);
t_dict_word	*ft_dictaddword(t_dict 	*dict, char *word, int value, t_bool is_valid);
t_dict	*ft_filldict(char **lines);
void	ft_dictprint(t_dict 	*dict);
void	ft_dictsort(t_dict 	*dict);

#endif