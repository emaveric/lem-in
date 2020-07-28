#include "../includes/lem-in.h"
/*
 * сюда получаем муравья, который был в первой комнате в пути и голову этого пути
 */
void move_all_in_path(t_lem_in *lem_in, t_room *room, int *is_start)
{
	t_room *temp;
	int ant_temp;

	temp = room;
	if (temp->level == MAX_INT)
		return ;
	if (temp->next->level == MAX_INT && temp->ant_name != -1)
	{
		lem_in->ant_end++;
		if (*is_start != 1)
			ft_printf(" ");
		else
			*is_start = -1;
		ft_printf("L%d-%s", temp->ant_name, temp->next->name);
		if (lem_in->ant_end == lem_in->ant_num)
			return ;
	}
	while (temp->prev)
	{
//		ft_printf("now in room %s\n", temp->name);
		temp->ant_name = temp->prev->ant_name;
		if (temp->ant_name != -1)
		{
			if (*is_start != 1)
				ft_printf(" ");
			else
				*is_start = -1;
			ft_printf("L%d-%s", temp->ant_name, temp->name);
		}
		temp->prev->ant_name = -1;
		temp = temp->prev;
	}
}

t_room *find_last_room(t_room *head)
{
	t_room *temp;

	temp = head;
	if (!temp->next)
		return (temp);
	if (!temp->next->next)
		return (temp);
	while (temp->next->next)
		temp = temp->next;
	return (temp);
}

void move_ants(t_lem_in *lem_in)
{
	int i;
	int is_start;
	t_room *tail;

	while (lem_in->ant_end != lem_in->ant_num)
	{
		i = 0;
		is_start = 1;
		while (i < lem_in->path_num)
		{
			if (lem_in->ant_end == lem_in->ant_num)
				break;
//			для каждого пути смотрим стоит ли из него сейчас двигать муравья и двигаем если надо, запоминаем какой был муравей в голове пути
			tail = find_last_room(lem_in->paths[i]->head);
			move_all_in_path(lem_in, tail, &is_start);
			if (lem_in->ant_start > lem_in->paths[i]->comp)
			{
				lem_in->paths[i]->head->ant_name = lem_in->ant_num - lem_in->ant_start + 1;
				lem_in->ant_start--;
				if (is_start != 1)
					ft_printf(" ");
				else
					is_start = -1;
				ft_printf("L%d-%s", lem_in->paths[i]->head->ant_name, lem_in->paths[i]->head->name);
				if (lem_in->paths[i]->head->level == MAX_INT)
					lem_in->ant_end++;
			}
			i++;
		}
		ft_printf("\n");
	}

}