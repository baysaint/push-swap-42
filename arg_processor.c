int	token_processor(char *tok, t_rec *specs, t_list **a)
{
	int	number;

	if(tok[0] == '-' && tok[1] == '-')
		return(parse_flag(tok, specs));
	if(!parse_number(tok, &number, a))
		return(0);
	return(append_node(a, number));
}

int	arg_processor(char *arg, t_rec *specs, t_list **a)
{
	char **tokens;
	int i;

	i = 0;
	tokens = ft_split_ps(arg);
	if(!tokens || !tokens[0])
	{
		ft_free_result(tokens);
		return (0);
	}
	while(tokens[i])
	{
		if(!token_processor(tokens[i], specs, a))
		{
			ft_free_result(tokens);
			return (0);
		}
		i++;
	}
	ft_free_result(tokens);
	return (1);
}