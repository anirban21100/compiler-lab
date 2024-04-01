lex q10.l
yacc q10.y -d
gcc lex.yy.c q10.tab.c -w
.\a.exe
4+5
9
