.SUFFIXES:
.SUFFIXES: .tex .pdf

PDFS = chap1s_Sld.pdf chap2s_Sld.pdf chap3s_Sld.pdf chap4s_Sld.pdf \
       chap5s_Sld.pdf chap6s_Sld.pdf chap7s_Sld.pdf chap8s_Sld.pdf \
       chap9s_Sld.pdf chapAs_Sld.pdf

%.pdf : %.tex *.sty
	lualatex $*.tex
#	lualatex $*.tex
#	dvipdfmx $*.dvi
	open $*.pdf

all : ${PDFS}

clean :
	rm -f *.log *.aux *.dvi *.out *.toc *.vrb *.snm *.nav *~

