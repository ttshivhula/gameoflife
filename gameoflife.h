#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# define BUFF_SIZE 500
# define CELL 50

int				get_next_line(const int fd, char **line);

#endif