#include "../includes/lem-in.h"
/*
 * сюда получаем муравья, который был в первой комнате в пути и голову этого пути
 */
void move_all_in_path(t_lem_in *lem_in, int ant_name, t_room *room, int head_num)
{
	t_room *temp;
	int ant_temp;

	temp = room;
	if (temp->next->level == MAX_INT && temp->ant_name != -1)
	{
		lem_in->ant_end++;
		ft_printf("ant %d moved to room %s\n", temp->ant_name, temp->next->name);

	}
	while (temp->prev)
	{
		temp->ant_name = temp->prev->ant_name;
		if (temp->ant_name != -1)
			ft_printf("ant %d moved to room %s\n", temp->ant_name, temp->name);
		temp->prev->ant_name = -1;
		temp = temp->prev;
	}
}

void move_ants(t_lem_in *lem_in)
{
	int i;
	int ant_name;
	int k;
	t_room *tail;

	k = 0;

	while (lem_in->ant_end != lem_in->ant_num)
	{
		i = 0;
		while (i < lem_in->path_num)
		{
			ant_name = lem_in->paths[i]->head->ant_name;
//			для каждого пути смотрим стоит ли из него сейчас двигать муравья и двигаем если надо, запоминаем какой был муравей в голове пути

//			ft_printf("ant start: %d, comp: %d\n", lem_in->ant_start, lem_in->paths[i]->comp);
			tail = lem_in->paths[i]->head;
			while (tail->next->next)
				tail = tail->next;
			move_all_in_path(lem_in, ant_name, tail, lem_in->paths[i]->head->num);
			if (lem_in->ant_start > lem_in->paths[i]->comp)
			{
//				запоминаем муравья, который был в голове в пути. Муравья в голове пути называем "следующим".
				ant_name = lem_in->paths[i]->head->ant_name;
				lem_in->paths[i]->head->ant_name = lem_in->ant_num - lem_in->ant_start + 1;
				lem_in->ant_start--;
				ft_printf("ant %d moved to room %d\n", lem_in->paths[i]->head->ant_name, lem_in->paths[i]->head->num);
				if (lem_in->paths[i]->head->level == MAX_INT)
					lem_in->ant_end++;
			}

			i++;
		}
//		print_rooms(lem_in->rooms, lem_in->room_num);
		ft_printf("\t\t\tANTS IN END: %d\n", lem_in->ant_end);

	}

}