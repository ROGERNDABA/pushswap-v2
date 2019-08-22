#include <global.h>



void algo_1(t_checker *t_c)
{
	test(&(*t_c));
}


int main(int ac, char **av)
{
	t_checker	t_c;

	if (ac > 1)
	{
		normalize_argv(&ac, &av);
		t_c.size_a = ac;
		t_c.size_b = 0;
		build_stacks(&t_c, &av, ac);
		// algo_1(&t_c);
		for (size_t i = 0; i < t_c.size_a; i++)
		{
			printf("%d\n", t_c.s_a[i]);
		}
		
		free_double_arr((void ***)&av);
		free(t_c.s_a);
		free(t_c.s_b);
	}
	return 0;
}
