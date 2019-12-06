
cd data/
rm periods.txt

for file in $(ls *.p)
do
    echo ${file:0:2} >> periods.txt
    echo ${file:3:8} >> periods.txt
    cat ${file} >> periods.txt
done

cat periods.txt | python3 ../draw_period_picture.py
