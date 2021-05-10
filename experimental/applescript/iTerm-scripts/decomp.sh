
for f in *.scpt
do
    osadecompile "$f" > "${f%.scpt}.applescript"
done
