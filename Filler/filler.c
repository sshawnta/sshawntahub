#include "filler.h"


void init(t_filler *filler)
{
	t_point p;

	p.y = 0;
	while (p.y < filler->board.height)
	{
		p.x = 0;
		while (p.x < filler->board.width)
		{
			if (filler->board.data[p.y][p.x] == filler->player.id)
				filler->player.start = p;
			else if (filler->board.data[p.y][p.x])
				filler->enemy.start = p;
			p.x++;
		}
		p.y++;
	}
	filler->target.x = (filler->enemy.start.x - filler->player.start.x < 0 ?
			0 : filler->board.width - 1);
	filler->target.y = (filler->enemy.start.y - filler->player.start.y < 0 ?
			0 : filler->board.height - 1);
	filler->inited = 1;
}

void filler_loop(t_filler filler)
{
	char *line;
	int res;

	while ((res = get_next_line(0, &line)) > -1)
	{
		if (!line)
			continue;
		if (!ft_strncmp(line, "Plateau", 8))
		{
				read_token(line, 4, &filler.board);
				if (!filler.inited)
					init(&filler);
		}
		else if (!ft_strncmp(line, "Piece", 6))
		{
			read_token(line, 0, &filler.token);		
			place(filler);
		}
		ft_strdel(&line);
	}

}
int main()
{
    t_filler filler;
    char *line;
    
    ft_bzero(&filler, sizeof(t_filler));
    line = NULL;
    filler.inited = 0;
    if (get_next_line(0, &line) && line && ft_strlen(line) > 10 && !ft_strncmp(line, "$$$ exec p", 9)
        && (line[10] == '1' || line[10] == '2'))
    {
        filler.player.id = (line[10] == '1' ? 'O' : 'X');
        filler.enemy.id = (line[10] == '1' ? 'X' : 'O');
        ft_strdel(&line);
        filler_loop(filler);
    }
    else 
        return(1);
    return (0);
}