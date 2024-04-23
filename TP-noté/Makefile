
#
# Ce Makefile contient les cibles suivantes :
#
# all   : compile le programme
# tests : lance les tests

.PHONY: all revrot

CFLAGS = -g -Wall -Wextra -Werror -Wvla # obligatoires

all: revrot

revrot:
	$(CC) $(CFLAGS) revrot.c -o revrot

clean:
	rm -rf tests
	rm -f revrot
