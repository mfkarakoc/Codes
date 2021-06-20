/* Reverse polish notation calculator. */

%{

#define YYSTYPE double

#include <stdio.h>
#include <math.h>
#include <ctype.h>

int yylex (void);
void yyerror (char const *);

%}

%token NUM
%left '-' '+'//TOPLAM VE FARK İŞLEMLERİNDE SOLDAN BAŞLANIR
%left '*' '/'//ÇARPMA VE BÖLME İŞLEMLERİNDE DE ÖNCE SOLDAN BAŞLANIR
%left NEG//EKSİ İŞARETİ NEGATİF SAYILARDA SOLA GELİR
%right '^'//KUVVET ALMA İŞLEMİNDE İSE SAĞ ÖNCELİKLİDİR

%% /* Grammar rules and actions follow. */

input:
	/* empty */
	| input line
	;

line:
	'\n'
	| exp '\n' { printf ("\t%.10g\n", $1); }	
	;
//
exp: NUM { $$ = $1; }
| exp '+' exp { $$ = $1 + $3; } //TOPLAMA
| exp '-' exp { $$ = $1 - $3; } //ÇIKARMA
| exp '*' exp { $$ = $1 * $3; } //ÇARPMA
| exp '/' exp { $$ = $1 / $3; } //BÖLME
| '-' exp %prec NEG { $$ = -$2;} //KUVVET
| exp '^' exp { $$ = pow ($1, $3); } //PARANTEZ
| '(' exp ')' { $$ = $2;}
;

%%

/* The lexical analyzer returns a double floating point
number on the stack and the token NUM, or the numeric code
of the character read if not a number. It skips all blanks
and tabs, and returns 0 for end-of-input. */

int
yylex (void)
{
int c;
/* Skip white space. */
while ((c = getchar ()) == ' ' || c == '\t')
;
/* Process numbers. */
if (c == '.' || isdigit (c))
{
ungetc (c, stdin);
scanf ("%lf", &yylval);
return NUM;
}
/* Return end-of-input. */
if (c == EOF)
return 0;
/* Return a single char. */
return c;
}

/* Called by yyparse on error. */
void
yyerror (char const *s)
{
fprintf (stderr, "%s\n", s);
}

int
main (void)
{
return yyparse ();
}
