all :
	latexmk -interaction=nonstopmode -lualatex syspro.tex

clean :
	rm -f *.log *.aux *.dvi *.out *.toc *.vrb *.snm *.nav *~
