#include "checker.h"

void fill_rules(rule *rules)
{
	rules[0] = sa;
	rules[1] = sb;
	rules[2] = ss;
	rules[3] = pa;
	rules[4] = pb;
	rules[5] = ra;
	rules[6] = rb;
	rules[7] = rr;
	rules[8] = rra;
	rules[9] = rrb;
	rules[10] = rrr;
}

void execute_commands(t_stacks *stacks, int *indx_cmd, int len)
{
	rule	rules[11];
	int		i;

	i = -1;
	fill_rules(rules);
	while (++i < len)
		rules[indx_cmd[i]](stacks, 0);
}
