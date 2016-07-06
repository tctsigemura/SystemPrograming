all:	haifu.pdf # kaitou.pdf test.pdf

haifu.pdf: haifu.tex mycat.c
	platex haifu.tex
	platex haifu.tex
	dvipdfmx haifu.dvi
	open haifu.pdf

kaitou.pdf: kaitou.tex mycp1.c mycp2.c mydiff2.c mydiff.c
	platex kaitou.tex
	platex kaitou.tex
	dvipdfmx kaitou.dvi
	open kaitou.pdf

clean:
	rm -f *~ *.dvi *.log *.aux

