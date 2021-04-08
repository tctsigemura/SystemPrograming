.SUFFIXES:
.SUFFIXES: .tex .pdf

HNDS = chap1s_Hnd.pdf chap2s_Hnd.pdf chap3s_Hnd.pdf chap4s_Hnd.pdf \
       chap5s_Hnd.pdf chap6s_Hnd.pdf chap7s_Hnd.pdf chap8s_Hnd.pdf \
       chap9s_Hnd.pdf chapAs_Hnd.pdf

SLDS = chap1s_Sld.pdf chap2s_Sld.pdf chap3s_Sld.pdf chap4s_Sld.pdf \
       chap5s_Sld.pdf chap6s_Sld.pdf chap7s_Sld.pdf chap8s_Sld.pdf \
       chap9s_Sld.pdf chapAs_Sld.pdf

%_Hnd.pdf : %_Hnd.tex %_Sld.pdf
	latexmk -lualatex $*_Hnd.tex

%_Sld.pdf : %_Sld.tex *.sty
	latexmk -lualatex $*_Sld.tex

all : ${SLDS} ${HNDS} # 中間ファイル *_Sld.pdf を消さないように

clean:
	rm -f *.log *.aux *.dvi *.out *.toc *.vrb *.snm *.nav *~
