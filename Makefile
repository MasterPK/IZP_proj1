MF = -std=c99 -Wall -Wextra -Werror
proj1: proj1.c
	gcc -std=c99 -Wall -Wextra -Werror proj1.c -o proj1
	./proj1 Br
clean:
	-rm proj1