HNDS = chap1s_Hnd.tex chap2s_Hnd.tex chap3s_Hnd.tex chap4s_Hnd.tex \
       chap5s_Hnd.tex chap6s_Hnd.tex chap7s_Hnd.tex chap8s_Hnd.tex \
       chap9s_Hnd.tex chapAs_Hnd.tex

SLDS = chap1s_Sld.tex chap2s_Sld.tex chap3s_Sld.tex chap4s_Sld.tex \
       chap5s_Sld.tex chap6s_Sld.tex chap7s_Sld.tex chap8s_Sld.tex \
       chap9s_Sld.tex chapAs_Sld.tex

all :
	$(foreach tex, ${SLDS}, latexmk -lualatex $(tex);)
	$(foreach tex, ${HNDS}, latexmk -lualatex $(tex);)

clean:
	rm -f *.log *.aux *.dvi *.out *.toc *.vrb *.snm *.nav *~
