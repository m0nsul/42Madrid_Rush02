#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_file.h"
#include "ft_strxcpy.h"

int	ft_readline(int fd)
{
	char			buffer[SIZE_1BYTE];
	char			*line;
	char			*line_more;
	unsigned int	u_total;
	unsigned int	u_read;

	u_total = 0;
	u_read = 1;
	while (u_read)
	{
		u_read = read(fd, buffer, SIZE_1BYTE);
		if (u_read == (unsigned int) -1 || u_read == (unsigned int) 0)
			break ;
		line_more = (char *) malloc((u_total + u_read + 1) * sizeof(char));
		if (!(line_more))
		{
			u_read = (unsigned int) -3 ;
			break ;
		}
		if (line_more != NULL)
			ft_strncpy(line_more, line, u_total);
		ft_strncpy(line_more + u_total, buffer, (unsigned int) u_read);
		//printf("\nPointer: %p \t line_more: \t %s", line_more, line_more);
		
		//free (line);
		line = line_more;
		
		u_total += u_read;
		
		if (buffer[0] == '\n')
		{
			// *error = ft_process_line(entry, line, total);
			u_read = (unsigned int) -2;
			break ;
		}
	}
	printf("Pointer: %p \t line: \t %s\n", line, line);
	return (u_read);
	// if (u_read == 0)
	// 	*error = reached_eof;
}
