TEXS = cdpwd.tex

all :
	$(foreach tex, ${TEXS}, latexmk -lualatex $(tex);)

clean :
	rm -f *.log *.aux *.dvi *.out *.toc *.vrb *.snm *.nav *~

