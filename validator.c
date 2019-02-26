int	valid_input(char *buf, int size)//проверка ввода
{
	while (size > 0)
	{
		size--;
		if ((buf[size] != '.') && (buf[size] != '#') && (buf[size] != '\n'))
			return (0);
	}
	return (1);
}

int	valid_input_size(char *buf, int size)//проверяем размер ввода
{
	int	x;
	int	y;

	while (size >= 0)
	{
		size--;
		y = 0;
		while (y < 4)
		{
			x = 0;
			if (buf[size] != '\n')
				return (0);
			while (x < 4)
			{
				size--;
				if (size < 0 || buf[size] == '\n')
					return (0);
				x++;
			}
			y++;
			size--;
		}
	}
	return (1);
}

int	size_figure(char **tetra)
{
	int	x;
	int	y;
	int	size;

	x = 0;
	size = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tetra[x][y] == '#')
				size++;
			y++;
		}
		x++;
	}
	if (size == 4)
		return (1);
	return (0);
}

int	valid_figure(char **tetra)//проверяем, чтобы блоки составляли правильную фигуру и не превышали нужное количество
{
	int	x;
	int	y;
	int	valid;

	x = 0;
	valid = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tetra[x][y] == '#')
			{
				if (y < 3 && tetra[x][y + 1] == '#')
					valid++;
				if (x < 3 && tetra[x + 1][y] == '#')
					valid++;
			}
			y++;
		}
		x++;
	}
	if ((valid = valid + check_element_numb(tetra)) < 5)
		return (0);
	return (1);
}

int	check_element_numb(char **tetra)//возвращает количество элементов, если есть цельная фигура
{
	int	x;
	int	y;
	int	valid;

	x = 3;
	valid = 0;
	while (x >= 0)
	{
		y = 3;
		while (y >= 0)
		{
			if (tetra[x][y] == '#')
			{
				if (y > 0 && tetra[x][y - 1] == '#')
					valid++;
				if (x > 0 && tetra[x - 1][y] == '#')
					valid++;
			}
			y--;
		}
		x--;
	}
	return (valid);
}
