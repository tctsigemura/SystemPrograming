all:	haifu.pdf kaitou.pdf

haifu.pdf: haifu.tex Makefile ascii.pdf jisx0201.pdf jisx0208.pdf jisx0213.pdf unicode.pdf
#	ptex2pdf -u -l -od "-f uptex-kozuka-pr6n-04.map -f otf-up-kozuka-pr6n.map" haifu.tex
#	ptex2pdf -u -l -od "-f uptex-noEmbed-04.map -f otf-up-noEmbed.map" haifu.tex 
#	ptex2pdf -u -l -od "-f uptex-noEmbed-04.map -f otf-up-noEmbed.map" haifu.tex 
	platex haifu.tex
	platex haifu.tex
	dvipdfmx haifu.dvi
#	open haifu.pdf

kaitou.pdf: kaitou.tex
	platex kaitou.tex
	platex kaitou.tex
	dvipdfmx kaitou.dvi
#	open kaitou.pdf

test.pdf: test.tex
	platex test.tex
	platex test.tex
	dvipdfmx test.dvi
#	open test.pdf

clean:
	rm -f *.dvi *.log *.aux *~
