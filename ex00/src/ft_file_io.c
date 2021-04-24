#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_file.h"
#include "ft_strxcpy.h"

int	ft_readline(int fd, char *line)
{
	char			buffer[SIZE_1BYTE];
	char			*line_more;
	unsigned int	u_total;
	unsigned int	u_read;

	u_total = 0;
	u_read = 1;
	while (u_read)
	{
		u_read = read(fd, buffer, SIZE_1BYTE);
		if (u_read == (unsigned int) -1  || (unsigned int) u_read == 0)
			break ;
		line_more = (char *) malloc((u_total + u_read + 1) * sizeof(char));
		if (!(line_more))
		{
			u_read = (unsigned int) -3;
			break ;
		}
		if (line_more != NULL)
			ft_strncpy(line_more, line, u_total);
		ft_strncpy(line_more + u_total, buffer, (unsigned int) u_read);
		
		
		//free (line);
		line = line_more;
		// printf("\nPointer: %p \t line: \t %s", line, line);
		
		u_total += u_read;
		
		if (buffer[0] == '\n')
		{
			u_read = (unsigned int) -2;
			break ;
		}
	}
	printf("Pointer: %p \t line: \t %s\n", line, line);
	return (u_read);

}
