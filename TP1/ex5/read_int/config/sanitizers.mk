CC = clang 
CFLAGS = -Wall -g -fsanitize=address -fno-omit-frame-pointer
EXEC = main 
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=obj/%.o)
DEPS = $(wildcard header/*.h)
HEADER_POS = -Iheader

#Compile le programme en fonction de EXEC, OBJETS, CC, LDFLAGS
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(HEADER_POS) -o $@ $^ -lncurses

#Génère les fichiers .o dans un répertoire "temporaire" obj qui est créer juste avant la création des fichiers .o
obj/%.o: src/%.c $(DEPS)
	mkdir -p obj
	$(CC) $(CFLAGS) $(HEADER_POS) -o $@ -c $<
