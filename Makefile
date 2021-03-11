cell: main.o savingFiles/output.o world/generations.o world/mat.o world/neighbourhood.o
	$(CC) -o cell main.o mat.o output.o generations.o neighbourhood.o
savingFiles/output.o:
	$(CC) -c world/generations.c
world/generations.o:
	$(CC) -c world/mat.c world/neighbourhood.c savingFiles/output.c
world/neighbourhood.o:
	$(CC) -c world/mat.c
world/mat.o:
	$(CC) -c world/mat.c
