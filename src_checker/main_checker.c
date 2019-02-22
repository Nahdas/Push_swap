
#include "includes/checker.h"

int		main(int argc, char **argv)
{
	t_pile *lst;
	t_pile *lst_b;
	int opt;
	char *line;

	line = "";
	if (argc < 2)
		return (0);
	opt = ft_prealable(argv);
	if (opt < 0)
		return (0);
	if (!(lst = ft_to_list(argv, &lst, opt)) && lst == NULL)
		return (0);
	if (!ft_check_list(lst))
		return (0);
	opt = ft_resolve(&lst, &lst_b, opt, &line);
	if (ft_is_sort(&lst, &lst_b) && opt == 1)
		ft_putstr("OK\n");
	else if (opt == 1)
		ft_putstr("K0\n");
	return (0);
}