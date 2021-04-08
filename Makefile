all :
	latexmk -lualatex syspro.tex

clean :
	rm -f *.log *.aux *.dvi *.out *.toc *.vrb *.snm *.nav *~
