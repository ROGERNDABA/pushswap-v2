#include <global.h>

int main(int ac, char **av)
{
	t_checker	t_c;

	normalize_argv(&ac, &av);
	t_c.size_a = ac;
	t_c.size_b = 0;
	build_stacks(&t_c, &av, ac);
	free_double_arr((void ***)&av);
	free(t_c.s_a);
	free(t_c.s_b);
	return 0;
}
