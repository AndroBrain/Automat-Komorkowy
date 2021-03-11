cell: main.o savingFiles/output.o world/generations.o world/mat.o world/neighbourhood.o
	$(CC) -o cell main.o world/mat.o savingFiles/output.o world/generations.o world/neighbourhood.o
savingFiles/output.o:
	$(CC) -c world/generations.c
world/generations.o:
	$(CC) -c world/mat.c world/neighbourhood.c savingFiles/output.c
world/neighbourhood.o:
	$(CC) -c world/mat.c
