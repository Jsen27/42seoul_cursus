#include "../cub3d.h"

void character_check(char **map)
{
	int i = -1;
	int ch_flag = 0;
	while(map[++i])
	{
		int j = -1;
		while(map[i][++j])
		{
			if(map[i][j] == '0' || map[i][j] == '1' || map[i][j] == ' ')
				continue;
			else if(map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == 'S' || map[i][j] == 'N')
			{
				if(ch_flag)
					my_error();
				ch_flag = 1;
			}
			else
				my_error();
		}
	}
	if(!ch_flag)
		my_error();
}

void surround_travel(char **map, int y, int x)
{
	int i = x;
	while(i >= 0)
	{
		if(map[y][i] == '1')
			break;
		if(map[y][i] == ' ' || i == 0)
			my_error();
		i --;
	}
	i = x;
	while(map[y][i])
	{
		if(map[y][i] == '1')
			break;
		if(map[y][i] == ' ' || !map[y][i+1])
			my_error();
		i ++;
	}
	i = y;
	while(i >= 0)
	{
		if(map[i][x] == '1')
			break;
		if(map[i][x] == ' ' || i == 0 || (int)ft_strlen(map[i-1]) <= i)
			my_error();
		i --;
	}
	i = y;
	while(map[i])
	{
		if(map[i][x] == '1')
			break;
		if(map[i][x] == ' ' || !map[i+1] || (int)ft_strlen(map[i+1]) <= i)
			my_error();
		i ++;
	}
}

void surrounded_check(char **map)
{
	int j = -1;
	while(map[++j])
	{
		int i = -1;
		while(map[j][++i])
		{
			if(map[j][i] == 'E' || map[j][i] == 'W' || map[j][i] == 'S' || map[j][i] == 'N' || map[j][i] == '0')
				surround_travel(map, j, i);
		}
	}
}

void check_world_map(char **map)
{
	character_check(map);
	surrounded_check(map);
}

void map_newline_check(char *str)
{
	int first_flag = 1;
	int i = -1;
	while(str[++i])
	{
		if(str[i] == '\n' && str[i + 1] == '\n')
		{
			if(first_flag)
				continue;
			else
				my_error();
		}
		else if(str[i] == '\n')
			continue;
		else
			first_flag = 0;
	}
}

void get_map(int fd, t_info *info)
{
	char *all_str = "";
	while(1)
	{
		char *str = get_next_line(fd);
		if(!str)
			break ;
		all_str = ft_strjoin(all_str, str);
	}
	map_newline_check(all_str);
	info->map.map = ft_split(all_str, '\n');
	check_world_map(info->map.map);
}