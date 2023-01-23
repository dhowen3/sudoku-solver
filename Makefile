run: SolverProgram.o
	./SolverProgram.o

SolverProgram.o : solver.c
	gcc -o SolverProgram.o solver.c #compile [[solver.c]] into file named [[SolverProgram.o]]

clean : 
	rm *.o
