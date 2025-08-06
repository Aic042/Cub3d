#include "cub3d.h"

int	ft_validate_file(char	*map_path)
{
	char	*file;

	file = ft_strrchr(map_path, '.');
	if (file == NULL || ft_strcmp(file, ".cub") != 0)
	{
		ft_printf("Error with the file");
		return (0);
	}
	return (1);
}