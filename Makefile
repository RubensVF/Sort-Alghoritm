CC=gcc

qsVis: qsVis.c
	$(CC) -o qsVis qsVis.c Alghortims/sort.c -lglut -lGLU -lGL -lm 

clean:
	rm -rf *o qsVis
