lex q4.l
yacc q4.y -d
gcc lex.yy.c q4.tab.c -w
.\a.exe

