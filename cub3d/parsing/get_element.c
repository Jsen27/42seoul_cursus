#include "../cub3d.h"

int all_flag_check(int *flag)
{
	for(int i = 0; i < 6; i ++)
	{
		if(!flag[i])
			return 0;
	}
	return 1;
}


void check_valid_color(char *str)
{
	if(!str || !*str || ft_strlen(str) > 4)
		my_error();
	if(*str == '+' || *str == '-')
		str ++;
	int i = -1;
	while(str[++i])
	{
		if(str[i] < '0' || str[i] > '9')
			my_error();
	}
}

void parse_rgb(char *str, int *color_store)
{
	int i = -1;
	int count = 0;
	while(str[++i])
	{
		if(str[i] == ',')
			count ++;
	}
	if(count != 2)
		my_error();
	char **p_str = ft_split(str, ',');
	i = 0;
	while(p_str[i])
		i++;
	if(i != 3)
		my_error();
	for(int k = 0; k < 3; k ++)
	{
		//check_valid_color(p_str[k]);
		color_store[k] = ft_atoi(p_str[k]);
		if(color_store[k] < 0 || color_store[k] > 255)
			my_error();
	}
}

void get_texture_path(struct s_element *e, char *str, int *flag)
{
	if(!str)
		my_error();
	char **p_element = ft_split(str, ' ');
	int i = 0;
	while(p_element[i])
		i ++;
	if(i != 2)
		my_error();
	if(!ft_strncmp(p_element[0], "EA", 2) && ft_strlen(p_element[0]) == 2 && !flag[0])
	{
		flag[0] = 1;
		e->east_path = p_element[1];
	}
	else if(!ft_strncmp(p_element[0], "WE", 2) && ft_strlen(p_element[0]) == 2 && !flag[1])
	{
		flag[1] = 1;
		e->west_path = p_element[1];
	}
	else if(!ft_strncmp(p_element[0], "SO", 2) && ft_strlen(p_element[0]) == 2 && !flag[2])
	{
		flag[2] = 1;
		e->south_path = p_element[1];
	}
	else if(!ft_strncmp(p_element[0], "NO", 2) && ft_strlen(p_element[0]) == 2 && !flag[3])
	{
		flag[3] = 1;
		e->north_path = p_element[1];
	}
	else if(!ft_strncmp(p_element[0], "F", 1) && ft_strlen(p_element[0]) == 1 && !flag[4])
	{
		flag[4] = 1;
		parse_rgb(p_element[1], e->floor_color);
	}
	else if(!ft_strncmp(p_element[0], "C", 1) && ft_strlen(p_element[0]) == 1 && !flag[5])
	{
		flag[5] = 1;
		parse_rgb(p_element[1], e->ceil_color);
	}
	else
		my_error();
}

void get_element(int fd, t_info *info)
{
	char *str = NULL;
	int flag[6];
	for(int i = 0; i < 6; i ++)
		flag[i] = 0;
	while(1)
	{
		if(all_flag_check(flag))
			break;
		str = get_next_line(fd);
		if(!str || str[ft_strlen(str) - 1] != '\n') //""인 부분 세그폴트 날수도
			my_error();
		if(str[0] == '\n' && ft_strlen(str) == 1)
			continue;
		str = ft_substr(str, 0, ft_strlen(str)-1);
		get_texture_path(&info->element, str, flag);
	}
}