.SUFFIXES:
.SUFFIXES: .tex .pdf

PDFS = cdpwd.pdf

%.pdf : %.tex
	lualatex $*.tex
	open $*.pdf

all : ${PDFS}

clean :
	rm -f *.log *.aux *.dvi *~

