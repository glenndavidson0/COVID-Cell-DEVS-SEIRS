# Susceptible-Infected-Recovered-Susceptible Disease Spread Model
An extension of the Cell-DEVS model: https://github.com/SimulationEverywhere-Models/COVID-Cell-DEVS-ACRI2020

Additions include:
- an exposed state
- reinfection rate and permanent immunity
- the aggregation of multi-phase states total E, total I, total R into visualization

## Overview the scenarios in this project
- base: 5 days exposed, 8 days of infected contagious, 8 days of isolated infected, 3% reinfection rate
- immediate_infection: 1 day exposed followed by base scenario parameters
- high_reinfection: base scenario parameters with 75% reinfection rate
- isolated_after_3d : base scenario with only 3 days of infected contagious
- border : a zero mobility border dividing the cell space into two, with a single cell cap in the center. The val file was generated with the tool in tools/var_generators/gen

## How to run the model:
- run simulate.sh individually in each scenario's folder
- `simulate.sh` will run `convert_logs.sh` and produce DEVS Web Viewer results in the logs_converted folder
- To visualize simulation, upload messages.log, structure.json, scenario1.val, and visualization.json to Web Viewer: http://206.12.94.204:8080/arslab-web/1.4/app-simple/index.html
- state.csv generated after running `simulate.sh` will show the state variables used, their default values, and the values given in the val file
