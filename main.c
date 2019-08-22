#include <global.h>

void simple_print(t_checker *t_c){
	printf("\033[31mstack a : ");
	for (size_t i = 0; i < t_c->size_a; i++)
		printf(" %d", t_c->s_a[i]);
	printf("\033[32m\nstack b : ");
	for (size_t i = 0; i < t_c->size_b; i++)
		printf(" %d", t_c->s_b[i]);
	printf("\033[0m\n\n");
}

// void test(t_checker *t_c)
// {
// 	pb(&(*t_c), 1);
// }


void algo_1(t_checker *t_c)
{
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
		simple_print(&t_c);
		
		free_double_arr((void ***)&av);
		free(t_c.s_a);
		free(t_c.s_b);
	}
	return 0;
}
