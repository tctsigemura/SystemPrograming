.SUFFIXES:
.SUFFIXES: .tex .pdf

PDFS = syspro.pdf

%.pdf : %.tex *.sty
	lualatex $*.tex
#	lualatex $*.tex
#	dvipdfmx $*.dvi
	open $*.pdf

all : syspro.pdf


syspro.pdf : syspro.tex chap?s.tex

clean :
	rm -f *.log *.aux *.dvi *.out *.toc *.vrb *.snm *.nav *~
