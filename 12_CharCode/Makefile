all:	haifu.pdf kaitou.pdf

haifu.pdf: haifu.tex
	platex haifu.tex
	platex haifu.tex
	dvipdfmx haifu.dvi
#	open haifu.pdf

kaitou.pdf: kaitou.tex myprintenv.c
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
