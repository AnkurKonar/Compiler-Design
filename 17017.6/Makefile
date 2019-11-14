myParser.out: lex.yy.c 170XX.tab.c++
	g++ 170XX.tab.c++ lex.yy.c -o myParser.out

lex.yy.c: 170XX.l
	flex 170XX.l

170XX.tab.c++: 170XX.y++
	bison -d -v 170XX.y++

clean:
	rm lex.yy.c 170XX.tab.c++ 170XX.tab.h++ 170XX.output myParser.out
