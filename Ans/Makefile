.SUFFIXES:
.SUFFIXES: .tex .pdf

EXS = ex0 ex1 ex2 ex3 ex4 ex5 ex6 ex7 ex8 ex9 exA exB

all :
	$(foreach ex, $(EXS), latexmk -lualatex $(ex).tex; )

clean :
	rm -f *.fls *.fdb_latexmk *.log *.aux *.dvi *.out *.toc \
              *.vrb *.snm *.nav *~

