#ifndef FT_STRINGS_LINE_H
# define FT_STRINGS_LINE_H

int		ft_checkline (char *str);
void	ft_getlinevalues (char *str, int *value, char *phrase);

// Comprobar linea
// 	int	ft_checkline (char *str);
// 	Te pasan un string y tiene que devolver 1 si el formato es correcto, 0 en caso contrario
// Obtener cifra y texto de linea
// 	void ft_getlinevalues (char *str, int *value, char *phrase)
// 	Recibe como argumeto un string (str) con una linea (ya validada) y debe guardar en un int * el valor y en un char * la palabra

#endif