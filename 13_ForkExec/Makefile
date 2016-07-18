all:	haifu.pdf kaitou.pdf

haifu.pdf: haifu.tex exectest1.c exectest2.c exectest3.c exectest4.c \
           exectest5.c forktest.c forkexec1.c forkexec2.c forkexec3.c \
           exec-crop.pdf fork-crop.pdf fork-exec-crop.pdf
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
