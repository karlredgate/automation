
# Should add validation

workbook.xlsx:
	zip -r $@  "[Content_Types].xml"  _rels  xl

#
# Should make the workbook xml depend on the sheet xmls, and
# recreate the workbook based on their contents.
# Perhaps make csv to sheet xml dependencies also?
#

clean:
	rm -f workbook.xlsx
