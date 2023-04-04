.SUFFIXES:
.SUFFIXES: .tex .pdf

EXS = ex0 ex1 ex2 ex3 ex4 ex5 ex6 ex7 ex8 ex9 exA exB exC

all :
	$(foreach ex, $(EXS), latexmk -interaction=nonstopmode -lualatex $(ex).tex; )

clean :
	rm -f *.fls *.fdb_latexmk *.log *.aux *.dvi *.out *.toc \
              *.vrb *.snm *.nav *~

