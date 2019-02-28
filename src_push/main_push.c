#include "includes/ft_push_swap.h"

int			main(int argc, char **argv)
{
	t_pile	*lst;
	t_pile	*lst_b;
	t_list	*inst;
	int		opt;

	if (argc < 2)
		return (0);
	opt = ft_prealable(argv);
	if (opt < 0)
		return (0);
	if (!(lst = ft_to_list(argv, &lst, opt)) && lst == NULL)
		return (0);
	if (!ft_check_list(lst))
		return (0);
	if (ft_sort_that(&lst, &lst_b, &inst) == 0)
	{
		ft_quick_sort_a(&lst, &lst_b, ft_get_size(lst), &inst);
		ft_quick_sort_b(&lst, &lst_b, ft_get_size(lst_b), &inst);
		ft_assemble(&lst, &lst_b, &inst);
	}
	if (!inst)
		return (1);
	ft_double(&inst);
	ft_print_inst(inst);
	while (1);
	return (1);
}