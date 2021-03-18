moor: main.o savingFiles/output.o world/generations.o world/mat.o world/neighbourhood.o savingFiles/saveMat.o savingFiles/savePbmFile.o world/gameOfLife.o
	gcc -o moor main.o mat.o output.o generations.o neighbourhood.o saveMat.o savePbmFile.o gameOfLife.o

neumann: main.o savingFiles/output.o world/generations.o world/mat.o world/neighbourhood.o
	gcc -o neumann main.o mat.o output.o generations.o neighbourhood.o -DNEUMANN 

savingFiles/output.o: world/generations.c savingFiles/savePbmFile.c savingFiles/saveMat.c
	$(CC) -c world/generations.c savingFiles/savePbmFile.c savingFiles/saveMat.c
world/generations.o:
	$(CC) -c world/mat.c world/neighbourhood.c savingFiles/output.c world/gameOfLife.c


clean:
	rm *.o moor neumann outputs/*.pbm
