/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:17:06 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/11/21 15:43:00 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameoflife.h"

void	clear(void)
{
	printf("\033[2J");
	printf("\033[%d;%dH", 0, 0);
}

void	dsp(int row[CELL][CELL])
{
	int		i;
	int		j;

    i = -1;
    while (++i < CELL)
    {
        j = -1;
        while (++j < CELL)
        {
            if(j == 0)
                printf("\x1b[34m|\x1b[0m");
            if (row[i][j] == 1)
                printf("\x1b[31mX\x1b[0m");
            else
                printf(" ");
            printf("\x1b[34m|\x1b[0m");
        }
        printf("\n");
    }
}

int		alive_or_dead(int x, int y, int grid[CELL][CELL])
{
	int alv;

	alv = 0;
    if (y > 0)
        if (grid[x][y - 1] == 1)
            alv++;
    if (x > 0)
    {
        if (grid[x - 1][y] == 1)
            alv++;
		if (y + 1 < CELL)
        {
			if (grid[x - 1][y + 1] == 1)
				alv++;
        }
        if (y > 0)
        {
            if (grid[x - 1][y - 1] == 1)
                alv++;
        }
    }
    if (x + 1 < CELL)
    {
        if (grid[x + 1][y] == 1)
            alv++;
        if (y + 1 < CELL)
        {
            if (grid[x + 1][y + 1] == 1)
                alv++;
        }
        if (y > 0)
        {
            if (grid[x + 1][y - 1] == 1)
                alv++;
        }
    }
    if (y + 1 < CELL)
        if (grid[x][y + 1] == 1)
            alv++;
    return alv;
}

int		solve(int grid[CELL][CELL])
{
	int		r;
	int		or[CELL][CELL];
    //copy
    for (int i = 0; i < CELL; i++)
    {
        for (int j = 0; j < CELL; j++)
            or[i][j] = grid[i][j];
    }
    //end of copy
    for (int i = 0; i < CELL; i++)
    {
        for (int j = 0; j < CELL; j++)
        {
            r = alive_or_dead(i, j, or);
            if (or[i][j] == 1)
            {
                if (r < 2 || r > 3)
                    grid[i][j] = 0;
            }
            if (or[i][j] == 0)
            {
                if (r == 3)
                    grid[i][j] = 1;
            }
        }
    }
    return (0);
}

int		reader(int grid[CELL][CELL], char *file)
{
	int		fd;
    char	*line;
    int		i;
    int		j;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
    i = 0;
    while (get_next_line(fd, &line) && i < CELL)
    {
        j = 0;
        while (line[j] && j < CELL)
        {
            grid[i][j] = line[j] - 48;
            j++;
        }
        i++;
    }
    return (1);
}

int		main(int c, char **v)
{
    int grid[CELL][CELL];

    if (c != 2)
    {
        for (int i = 0; i < CELL; i++)
        {
            for (int j = 0; j < CELL; j++)
            {
                srand((unsigned)time(0) * (i * j));
                grid[i][j] = rand() % 2;
            }
        }
    }
    else
    {
        if (reader(grid, v[1]) == 0)
            return (1);
    }
    while (42)
    {
        clear();
        dsp(grid);
        if (solve(grid))
            break ;
        usleep(20000);
    }
    return (0);
}
