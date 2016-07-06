all:	haifu.pdf kaitou.pdf

haifu.pdf: haifu.tex mycat.c
	platex haifu.tex
	platex haifu.tex
	dvipdfmx haifu.dvi
#	open haifu.pdf

kaitou.pdf: kaitou.tex mycp2.c
	platex kaitou.tex
	platex kaitou.tex
	dvipdfmx kaitou.dvi
#	open kaitou.pdf

clean:
	rm -f *~ *.dvi *.log *.aux

