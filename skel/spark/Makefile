
default: spark.xml

doc: spark.pdf

spark.pdf: spark.tex
	lualatex spark.tex
	makeindex -s spark.ist spark.idx
	lualatex spark.tex

spark.xml: spark.fw
	fw +D +o -t spark.fw || ( cat spark.lis ; exit 1 )

spark.tex: spark.fw
	fw -o +t spark.fw

clean:
	rm -v $$( fw +D +B5 spark.fw | sed -ne 's/\.$$//' -e '/Tangle: /s/Tangle: Completed //p' )
	rm -f spark.aux spark.idx spark.lis spark.log spark.nop spark.pdf spark.tex spark.toc spark.xml spark.ilg spark.ind
	rm -f spark.lis spark.nop spark.out
