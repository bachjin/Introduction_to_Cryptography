bash clear.sh
echo 'clear'
python3 create_input.py
echo 'input'
bash make_output.sh
echo 'output'
python3 draw_bit_picture.py
echo 'draw'
bash analyze_out.sh
echo 'test'
bash compute_period.sh
echo 'compute'
bash compute_pass.sh
echo 'pass finished'