all:	haifu.pdf kaitou.pdf

haifu.pdf: haifu.tex
	platex haifu.tex
	platex haifu.tex
	dvipdfmx haifu.dvi
#	open haifu.pdf

kaitou.pdf: kaitou.tex myrm.c mymkdir.c myrmdir.c myln.c mylns.c mymv.c mychmod.c
	platex kaitou.tex
	platex kaitou.tex
	dvipdfmx kaitou.dvi
#	open kaitou.pdf

clean:
	rm -f *~ *.dvi *.log *.aux

