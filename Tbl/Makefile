.SUFFIXES:
.SUFFIXES: .tex .pdf

PDFS = stdio.pdf printfVsFprintf.pdf chmodOptions.pdf killOptions.pdf \
        psOut.pdf psOptions.pdf psStat.pdf signal.pdf

%.pdf : %.tex
	lualatex $*.tex
	open $*.pdf

all : ${PDFS}

clean :
	rm -f *.log *.aux *.dvi *~

