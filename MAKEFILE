# Convert all .c files in directory into .o object files
OBJ := $(patsubst %.c, %.o, $(wildcard *.c))
# Final executable target
calc.exe: $(OBJ)
# Link all object files into executable
	gcc -o $@ $^
# Clean rule to remove generated files
clean:
	rm *.o *.exe