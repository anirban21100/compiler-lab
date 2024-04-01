%option noyywrap
%{
#include<stdio.h>
#include "q10.tab.h"
%}
%%
[0-9]+ {yylval.dval=atof(yytext);
return DIGIT;
}
\n|. return yytext[0];
%%