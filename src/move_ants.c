#include "../includes/lem-in.h"
/*
 * сюда получаем муравья, который был в первой комнате в пути и голову этого пути
 */
void move_all_in_path(t_lem_in *lem_in, int ant_name, t_room *room)
{
	t_room *temp;
	int ant_temp;

	temp = room;
//	ft_printf("in move all ant_name: %d\n", ant_name);
	if (temp->level == MAX_INT)
	{
		if (ant_name != -1)
			lem_in->ant_end++;
		return ;
	}
//	ft_printf("not end yet\n");
	temp = temp->next;
	while (temp)
	{
		if (temp->level == MAX_INT)
		{
			ft_printf("last room\n");
			if (ant_name != -1)
			{
				lem_in->ant_end++;
				ft_printf("ant %d moved to room %d\n", ant_name, temp->num);
			}
			return ;
		}
//		ft_printf("should remember ant_name %d in room %d\n", temp->ant_name, temp->num);
		ant_temp = temp->ant_name;
		temp->ant_name = ant_name;
		ant_name = ant_temp;
		if (temp->ant_name != -1)
			ft_printf("ant %d moved to room %d\n", temp->ant_name, temp->num);
//		ft_printf("remembered ant_name %d\n", ant_name);
		temp = temp->next;
	}
}

void move_ants(t_lem_in *lem_in)
{
	int i;
	int ant_name;
	int k;

	k = 0;

	while (lem_in->ant_end != lem_in->ant_num)
	{
		i = 0;
		while (i < lem_in->path_num)
		{
			ant_name = lem_in->paths[i]->head->ant_name;
//			для каждого пути смотрим стоит ли из него сейчас двигать муравья и двигаем если надо, запоминаем какой был муравей в голове пути

//			ft_printf("ant start: %d, comp: %d\n", lem_in->ant_start, lem_in->paths[i]->comp);
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
//			теперь двигаем всех муравьев на этом пути
//			ft_printf("before move all\n");
//			ft_printf("starting in room %d\n", lem_in->paths[i]->head->num);
			move_all_in_path(lem_in, ant_name, lem_in->paths[i]->head);
//			ft_printf("after move all\n");
			i++;
		}
//		print_rooms(lem_in->rooms, lem_in->room_num);
		ft_printf("\t\t\tANTS IN END: %d\n", lem_in->ant_end);

	}

}