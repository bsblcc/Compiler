compiler.o : ./bin/parser.tab.o ./bin/lex.yy.o ./bin/frontEnd.o  ./bin/AST.o ./bin/scope.o ./bin/symbolTable.o ./bin/symbol.o ./bin/type.o ./bin/function.o ./bin/symbolExtractor.o ./bin/functionManager.o ./bin/quadTranslator.o ./bin/basicBlock.o ./bin/CFG.o ./bin/ASMTranslator.o ./bin/location.o
	clang++ -std=c++14 -o compiler.o ./bin/parser.tab.o ./bin/lex.yy.o ./bin/frontEnd.o ./bin/AST.o ./bin/scope.o ./bin/symbolTable.o ./bin/symbol.o ./bin/type.o ./bin/function.o ./bin/symbolExtractor.o ./bin/functionManager.o ./bin/quadTranslator.o ./bin/basicBlock.o ./bin/CFG.o ./bin/ASMTranslator.o ./bin/location.o

parser.tab.cpp : parser.ypp
	bison -d parser.ypp

./bin/parser.tab.o : parser.tab.cpp
	clang -std=c++14 -c parser.tab.cpp -o ./bin/parser.tab.o

lex.yy.c : lexer.l
	flex lexer.l

./bin/lex.yy.o : lex.yy.c
	clang++ -std=c++14 -c lex.yy.c -o ./bin/lex.yy.o

./bin/frontEnd.o : frontEnd.h frontEnd.cpp
	clang++ -std=c++14 -c frontEnd.cpp -o ./bin/frontEnd.o

./bin/AST.o : AST.h AST.cpp
	clang++ -std=c++14 -c AST.cpp -o  ./bin/AST.o

./bin/scope.o : scope.h scope.cpp
	clang++ -std=c++14 -c scope.cpp -o  ./bin/scope.o

./bin/symbolTable.o : symbolTable.h symbolTable.cpp
	clang++ -std=c++14 -c symbolTable.cpp  -o ./bin/symbolTable.o

./bin/symbol.o : symbol.h symbol.cpp
	clang++ -std=c++14 -c symbol.cpp -o  ./bin/symbol.o

./bin/type.o : type.h type.cpp
	clang++ -std=c++14 -c type.cpp -o  ./bin/type.o

./bin/function.o : function.h function.cpp
	clang++ -std=c++14 -c function.cpp -o  ./bin/function.o

./bin/symbolExtractor.o : symbolExtractor.h symbolExtractor.cpp
	clang++ -std=c++14 -c symbolExtractor.cpp -o  ./bin/symbolExtractor.o

./bin/functionManager.o : functionManager.h functionManager.cpp
	clang++ -std=c++14 -c functionManager.cpp -o  ./bin/functionManager.o

./bin/quadTranslator.o : quadTranslator.h quadTranslator.cpp
	clang++ -std=c++14 -c quadTranslator.cpp -o  ./bin/quadTranslator.o

./bin/basicBlock.o : basicBlock.h basicBlock.cpp
	clang++ -std=c++14 -c basicBlock.cpp -o  ./bin/basicBlock.o

./bin/CFG.o : CFG.h CFG.cpp
	clang++ -std=c++14 -c CFG.cpp -o  ./bin/CFG.o


./bin/ASMTranslator.o : ASMTranslator.h ASMTranslator.cpp
	clang++ -std=c++14 -c ASMTranslator.cpp -o  ./bin/ASMTranslator.o

./bin/location.o : location.h location.cpp
	clang++ -std=c++14 -c location.cpp -o  ./bin/location.o