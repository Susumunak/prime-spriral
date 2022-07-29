#include<stdio.h>
#include<stdlib.h>

int     ft_is_prime(int nb)
{
        if(nb <= 1)
                return(0);
        int i = 2;
        return(ft_is_prime2(nb,i));

}

int     ft_is_prime2(int nb, int i)
{
        if(i <= nb/i)
        {
                if ((nb % i) == 0)
                        return (0);
        }
        else
                return (1);

        return (ft_is_prime2(nb, i + 1));
}

char    *ft_word(int index, int len)
{
        int             i;
        char    *word;

        i = 0;
        word = (char *)malloc(sizeof(char) * (len + 1));
        while (i < len)
        {
                if(ft_is_prime(index))
			word[i] = '*';
		else
			word[i] = ' ';
                i++;
		index++;
        }
        word[i] = '\0';
        return (word);
}
void	ft_draw(char **arr, int len)
{
	int y=0;
	int x=0;
	while (y < len)
	{
		x = 0;
		while (x < len)
		{
			printf("%c",arr[y][x]);
			x++;
		}
		printf("\n");
		y++;
        }
}

int main(int ac, char **av)
{
	char **arr;
	char **arr2;
	int len = atoi(av[1]);
	int x=0;
	int y=0;
	int posx;
	int posy;
	int direc_x = 1;
	int direc_y = -1;
	int step = 1;
	int stepi = 1;
	int round = 1;
	int index = 1;

	arr = (char **) malloc(sizeof(char*) * len);
	arr2 = (char **) malloc(sizeof(char*) * len);
	
	while (y < len)
	{
		arr[y]= ft_word(index,len);
		arr2[y]= ft_word(index,len);
		index += len;
		y++;
	}
	posx = len/2;
	posy = len/2;
	y = 0;

	while(y <len)
	{
		x = 0;
		while(x < len)
		{
			arr2[posy][posx] = arr[y][x];
			x++;
			if(round == 1 && stepi <= step)
			{
				if(direc_x > 0)
				{
					posx++;
					stepi++;
				}
				else
				{
					posx--;
					stepi++;
				}

				if(stepi == step + 1)
				{
					round = 2;
					stepi = 1;
				}
			}

			else if (round == 2 && stepi <= step)
			{
				if(direc_y > 0)
				{
					posy++;
					stepi++;
				}
				else
				{
					posy--;
					stepi++;
				}
				if(stepi == step + 1)
				{
					round = 1;
					stepi = 1;
					step++;
					direc_x *= -1;
					direc_y *= -1;
				}
			}
		}
		y++;
	}

	ft_draw(arr2,len);
	return(0);
}
