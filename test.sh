#!/bin/zsh

if [[ "$2" = 'lldb' || "$1" = 'lldb' ]]
then
	ARG="$(./numbers)";
	echo $ARG
	lldb -- ./push_swap $ARG
	return ;
fi

if [[ "$1" = 'one' ]]
then
	ARG="$(./numbers 100)";
	echo $ARG
	./push_swap $ARG
	return;
fi

while (( 1 ))
do
	ARG="$(./numbers $1)";
	echo $ARG
	./push_swap $ARG
	RES="$(./push_swap $ARG 2>/dev/null | wc -l)";
	if  echo $RES | grep "700"  # тут в греп пишем число которое не хотим увидеть
	then
		echo "\033[31m$RES\033[0m"; return;
	else
		echo "\033[32m$RES\033[0m"
	fi
	sleep 1
done
