# make logs path if it doesn't exist
mkdir -p $PWD"/logs_raw"

# run the simulation
../cd++ -m"sirs_zhong.ma" -l"logs_raw/sirs_zhong.log" -t00:00:00:125

# generate the converted DEVS webviewer fileset
cp scenario1.val logs_converted
./convert_logs.sh

# generate a summary of simulation variables and their values
python ../tools/verify_state_vals/extract_ma_state.py $PWD"/sirs_zhong.ma" $PWD"/scenario1.val" $PWD"/state.csv" 
echo "Results generated in logs_converted folder"
echo