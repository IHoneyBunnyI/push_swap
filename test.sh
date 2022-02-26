#!/bin/zsh

if [[ "$2" = 'lldb' || "$1" = 'lldb' ]]
then
	ARG="$(./numbers)";
	echo $ARG
	lldb -- ./push_swap $ARG
	return ;
fi

while (( 1 ))
do
	ARG="$(./numbers $1)";
	RES="$(./push_swap $ARG 2>/dev/null | wc -l)";
	echo "\033[32m$RES\033[0m"
	sleep 1
done
