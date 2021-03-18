moor: main.o savingFiles/output.o world/generations.o world/mat.o world/neighbourhood.o
	gcc -o moor main.o mat.o output.o generations.o neighbourhood.o

neumann: main.o savingFiles/output.o world/generations.o world/mat.o world/neighbourhood.o
	gcc -o neumann main.o mat.o output.o generations.o neighbourhood.o -DNEUMANN 

savingFiles/output.o:
	$(CC) -c world/generations.c
world/generations.o:
	$(CC) -c world/mat.c world/neighbourhood.c savingFiles/output.c
world/mat.o:
	$(CC) -c world/mat.c
clean:
	rm *.o moor neumann outputs/*.pbm
