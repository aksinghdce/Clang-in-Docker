program=priorityQ
$(program): $(program).cpp
	clang++ -std=c++17 -stdlib=libc++ -Wall -pedantic $(program).cpp -o $(program)
run:
	./$(program) $(ARG1)
clean:
	rm $(program)