program=addtwo
$(program): $(program).cpp
	clang++ -std=c++17 -stdlib=libc++ -Wall -pedantic $(program).cpp -o $(program)
run:
	./$(program)
clean:
	rm $(program)