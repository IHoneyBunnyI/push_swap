# push_swap
A project on creating an efficient sorting algorithm using 2 stacks
## Rules
There are two stacks `a` and `b`

The goal of the program is to sort in ascending order numbers into stack ```a```. To do so you have the
following operations at your disposal:

`sa` (swap a): Swap the first 2 elements at the top of stack `a`.

`sb` (swap b): Swap the first 2 elements at the top of stack `b`.

`ss` (swap a, swap b): `sa` and `sb` at the same time.

`pa` (push a): Take the first element at the top of `b` and put it at the top of `a`.

`pb` (push b): Take the first element at the top of `a` and put it at the top of `b`.

`ra` (rotate a): Shift up all elements of stack `a` by 1.

`rb` (rotate b): Shift up all elements of stack `b` by 1. The first element becomes the last one.

`rr` (rotate a, rotate b): `ra` and `rb` at the same time.

`rra` (reverse rotate a): Shift down all elements of stack `a` by 1.

`rrb` (reverse rotate b): Shift down all elements of stack `b` by 1. The last element becomes the first one.

`rrr` (reverse rotate a, reverse rotate b): `rra` and `rrb` at the same time.

The program should print operations in right order to sort stack `a`
## Usage
### push_swap

To compile the programm you should do `make` then `./push_swap <numbers for sorting>`

### checker

To compile the programm you should do `make` then `./checker <numbers for sorting>`. 
The program will ask you to print an operations for sorting stack a.
If after executing these operations stack `a` will be sorted, checker will print `OK`, else `KO`
