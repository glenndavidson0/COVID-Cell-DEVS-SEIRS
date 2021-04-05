# In[]: 
# this file creates a space delimted csv of a model's state variables, default values, and initialization values
import argparse
import csv
import re
from io import StringIO

# In[]: make command line parser
debug = False

if(not debug):
    parser = argparse.ArgumentParser()
    parser.add_argument("input_ma", help= "input ma file to extract from")
    parser.add_argument("input_var", help= "var file to read initial conditions from")
    parser.add_argument("output_file", help= "output file to write the result to")
    args = parser.parse_args()

    MA_FILE = args.input_ma
    VAR_FILE = args.input_var
    CSV_FILE = args.output_file

else:
    MA_FILE = "sirs_zhong.ma"
    VAR_FILE = "scenario1.val"
    CSV_FILE = "state.csv"


# In[]: re search expressions for state variables and values

re_statevars = "statevariables:.+"
re_statevals = "statevalues:.+"

with open(MA_FILE, "r") as ma_file:
    for line in ma_file:
        if (line == " " or line == "\n"):
            continue
        vars_match = re.search(re_statevars,line)
        vals_match = re.search(re_statevals,line)
        if(vars_match):
            state_vars = vars_match.group()
        if(vals_match):
            state_vals = vals_match.group()

# In[]: convering .var to to a list of properly formatted space delimited string

x = list()    
with open(VAR_FILE, "r") as var_file:
    
    for line in var_file:
        if (line == " " or line == "\n"):
            continue
        csv_string = StringIO(line)
        reader = csv.reader(csv_string,delimiter=' ')
        vals = list(reader)[0]
        vals.pop(1)
        vals[0] += '='
        s = ''
        for item in vals:
            s += (item + ' ')
        
        x.append(s)
    
# In[]: write results to single space delimited csv

with open(CSV_FILE,"w") as out_file:
    out_file.write(state_vars + '\n')
    out_file.write(state_vals + '\n')
    for item in x:
        out_file.write(item + '\n')
