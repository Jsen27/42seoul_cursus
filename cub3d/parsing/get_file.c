#include "../cub3d.h"
//파싱시 지켜야 할 것들
//.cub형식
//0 1 N S E W만 맵에 들어올 수 있음
//맵은 1로 둘러써여야 함
//맵은 마지막에 와야 함
//요소의 각 타입은 순서가 상관없음
//요소에서 스페이스 하나 혹은 여러개로 요소 구분되어있음
//맵에서 space는 유효한 부분
//요소들의 첫번재는 식별자임
//NO SO WE EA F C (RGB 0~255)
//에러 있을 시 Error\n출력후 종료

void cub_check(char *map_path)
{
	if(!map_path)
		my_error();
	if(ft_strlen(map_path) < 4)
		my_error();
	if(ft_strncmp(".cub", map_path + ft_strlen(map_path) - 4 , 4))
		my_error();
}

void set_pos(t_info *info)
{
	int j = -1;
	while(info->map.map[++j])
	{
		int i = -1;
		while(info->map.map[j][++i])
		{
			if(info->map.map[j][i] == 'E' || info->map.map[j][i] == 'W' || info->map.map[j][i] == 'S' || info->map.map[j][i] == 'N')
			{
				info->pos_x = j+0.5;
				info->pos_y = i+0.5; //i와 j헷갈림
				info->map.start_direction = info->map.map[j][i];
			}
		}
	}
}

void get_file(char *map_path, t_info *info)
{
	cub_check(map_path);
	int fd = open(map_path, O_RDONLY);
	if(fd == -1)
		my_error();
	get_element(fd, info);
	get_map(fd, info);
	close(fd);
	set_pos(info);
}
