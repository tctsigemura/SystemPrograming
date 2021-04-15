.SUFFIXES:
.SUFFIXES: .tex .pdf

PDFS = ex0.pdf ex1.pdf ex2.pdf ex3.pdf ex4.pdf ex5.pdf ex6.pdf ex7.pdf ex8.pdf \
       ex9.pdf exA.pdf exB.pdf

%.pdf : %.tex *.sty
	latexmk -lualatex $*.tex
#	lualatex $*.tex
#	dvipdfmx $*.dvi
#	open $*.pdf

all : ${PDFS}

clean :
	rm -f *.log *.aux *.dvi *.out *.toc *.vrb *.snm *.nav *~

