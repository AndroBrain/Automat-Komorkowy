moor: mat.o saveMat.o savePbmFile.o output.o gameOfLife.o neighbourhood.o generations.o gifenc.o
	gcc mat.o saveMat.o savePbmFile.o output.o gameOfLife.o neighbourhood.o generations.o gifenc.o -o moor main.c

neumann: mat.o saveMat.o savePbmFile.o output.o gameOfLife.o neighbourhood.o neumannGenerations.o gifenc.o
	gcc mat.o saveMat.o savePbmFile.o output.o gameOfLife.o neighbourhood.o neumannGenerations.o gifenc.o -o neumann main.c

generations.o: mat.o neighbourhood.o output.o gifenc.o
	$(CC) -c world/generations.c
	
neumannGenerations.o: mat.o neighbourhood.o output.o gifenc.o
	$(CC) -o neumannGenerations.o -c world/generations.c -DNEUMANN

neighbourhood.o: mat.o gameOfLife.o world/neighbourhood.h
	$(CC) -c world/neighbourhood.c

gameOfLife.o: mat.o world/games.h
	$(CC) -c world/gameOfLife.c

output.o: mat.o saveMat.o savePbmFile.o gifenc.o savingFiles/output.h
	$(CC) -c savingFiles/output.c

savePbmFile.o: mat.o saveMat.o savingFiles/savePbmFile.h
	$(CC) -c savingFiles/savePbmFile.c

saveMat.o: mat.o savingFiles/saveMat.h
	$(CC) -c savingFiles/saveMat.c

mat.o: world/mat.h
	$(CC) -c world/mat.c

gifenc.o: gifMaker/gifenc.c
	$(CC) -c gifMaker/gifenc.c
clean:
	rm *.o moor neumann outputs/*.pbm
