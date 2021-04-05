#include(sirs_zhong_macros.inc)
[top]
components : area

[area]
type : cell
width : 50
height : 50
delay : transport
defaultDelayTime : 1
border : wrapped
neighbors : 			area(-1,0)
neighbors : area(0,-1)  area(0,0)  area(0,1)
neighbors : 			area(1,0)
initialvalue : -1

localtransition : sirs-zhong-rule

statevariables: population connection movement cured_rate i_sus i_expos_1 i_expos_2 i_expos_3 i_expos_4 i_expos_5 i_inf_1 i_inf_2 i_inf_3 i_inf_4 i_inf_5 i_inf_6 i_inf_7 i_inf_8 i_inf_9 i_inf_10 i_inf_11 i_inf_12 i_inf_13 i_inf_14 i_inf_15 i_inf_16 i_rec_1 i_rec_2 i_rec_3 i_rec_4 i_rec_5 i_rec_6 i_immune icb_1 icb_2 icb_3 icb_4 v_1 v_2 v_3 v_4 v_5 v_6 v_7 v_8 v_9 v_10 v_11 v_12 v_13 v_14 v_15 v_16 reinfec_r i_total_e i_total_i i_total_r i_immune_prev
statevalues: 100 1 0.6 0.07 1.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.99 0.99 0.99 0.99 0.17 0.17 0.17 0.17 0.17 0.17 0.17 0.17 0.01 0.01 0.01 0.01 0.01 0.01 0.01 0.01 0.03 0 0 0 0
initialvariablesvalue: scenario1.val

neighborports : initial pop sus expos_1 expos_2 expos_3 expos_4 expos_5 inf_1 inf_2 inf_3 inf_4 inf_5 inf_6 inf_7 inf_8 inf_9 inf_10 inf_11 inf_12 inf_13 inf_14 inf_15 inf_16 rec_1 rec_2 rec_3 rec_4 rec_5 rec_6 immune total_e total_i total_r

[sirs-zhong-rule]
rule : {
~initial := 0; ~pop := $population; ~sus := $i_sus; ~expos_1 := $i_expos_1; ~expos_2 := $i_expos_2; ~expos_3 := $i_expos_3; ~expos_4 := $i_expos_4; ~expos_5 := $i_expos_5; ~inf_1 := $i_inf_1; ~inf_2 := $i_inf_2; ~inf_3 := $i_inf_3; ~inf_4 := $i_inf_4; ~inf_5 := $i_inf_5; ~inf_6 := $i_inf_6; ~inf_7 := $i_inf_7; ~inf_8 := $i_inf_8; ~inf_9 := $i_inf_9; ~inf_10 := $i_inf_10; ~inf_11 := $i_inf_11; ~inf_12 := $i_inf_12; ~inf_13 := $i_inf_13; ~inf_14 := $i_inf_14; ~inf_15 := $i_inf_15; ~inf_16 := $i_inf_16; ~rec_1 := $i_rec_1; ~rec_2 := $i_rec_2; ~rec_3 := $i_rec_3; ~rec_4 := $i_rec_4; ~rec_5 := $i_rec_5; ~rec_6 := $i_rec_6; ~immune := $i_immune; ~total_e := $i_total_e; ~total_i := $i_total_i; ~total_r := $i_total_r;
}
 1 {(0,0)~initial = -1}

rule : {
~pop := $population; ~sus := $i_sus; ~expos_1 := $i_expos_1; ~expos_2 := $i_expos_2; ~expos_3 := $i_expos_3; ~expos_4 := $i_expos_4; ~expos_5 := $i_expos_5; ~inf_1 := $i_inf_1; ~inf_2 := $i_inf_2; ~inf_3 := $i_inf_3; ~inf_4 := $i_inf_4; ~inf_5 := $i_inf_5; ~inf_6 := $i_inf_6; ~inf_7 := $i_inf_7; ~inf_8 := $i_inf_8; ~inf_9 := $i_inf_9; ~inf_10 := $i_inf_10; ~inf_11 := $i_inf_11; ~inf_12 := $i_inf_12; ~inf_13 := $i_inf_13; ~inf_14 := $i_inf_14; ~inf_15 := $i_inf_15; ~inf_16 := $i_inf_16; ~rec_1 := $i_rec_1; ~rec_2 := $i_rec_2; ~rec_3 := $i_rec_3; ~rec_4 := $i_rec_4; ~rec_5 := $i_rec_5; ~rec_6 := $i_rec_6; ~immune := $i_immune; ~total_e := $i_total_e; ~total_i := $i_total_i; ~total_r := $i_total_r;
}
{

$i_immune_prev := $i_immune;
$i_immune := $i_immune_prev + (round(min((1 - $reinfec_r) * $i_rec_6, 1)*100)/100);

$i_rec_6 := $i_rec_5;
$i_rec_5 := $i_rec_4;
$i_rec_4 := $i_rec_3;
$i_rec_3 := $i_rec_2;
$i_rec_2 := $i_rec_1;
$i_rec_1 := $i_inf_16 + #macro(local_cured);

$i_inf_16 := round(min((1 - $cured_rate) * $i_inf_15, 1)*100)/100;
$i_inf_15 := round(min((1 - $cured_rate) * $i_inf_14, 1)*100)/100;
$i_inf_14 := round(min((1 - $cured_rate) * $i_inf_13, 1)*100)/100;
$i_inf_13 := round(min((1 - $cured_rate) * $i_inf_12, 1)*100)/100;
$i_inf_12 := round(min((1 - $cured_rate) * $i_inf_11, 1)*100)/100;
$i_inf_11 := round(min((1 - $cured_rate) * $i_inf_10, 1)*100)/100;
$i_inf_10 := round(min((1 - $cured_rate) * $i_inf_9, 1)*100)/100;
$i_inf_9 := round(min((1 - $cured_rate) * $i_inf_8, 1)*100)/100;
$i_inf_8 := round(min((1 - $cured_rate) * $i_inf_7, 1)*100)/100;
$i_inf_7 := round(min((1 - $cured_rate) * $i_inf_6, 1)*100)/100;
$i_inf_6 := round(min((1 - $cured_rate) * $i_inf_5, 1)*100)/100;
$i_inf_5 := round(min((1 - $cured_rate) * $i_inf_4, 1)*100)/100;
$i_inf_4 := round(min((1 - $cured_rate) * $i_inf_3, 1)*100)/100;
$i_inf_3 := round(min((1 - $cured_rate) * $i_inf_2, 1)*100)/100;
$i_inf_2 := round(min((1 - $cured_rate) * $i_inf_1, 1)*100)/100;
$i_inf_1 := $i_expos_5 + #macro(internal_infected);

$i_expos_5 := round(min((1 - $icb_4) * $i_expos_4, 1)*100)/100;
$i_expos_4 := round(min((1 - $icb_3) * $i_expos_3, 1)*100)/100;
$i_expos_3 := round(min((1 - $icb_2) * $i_expos_2, 1)*100)/100;
$i_expos_2 := round(min((1 - $icb_1) * $i_expos_1, 1)*100)/100;
$i_expos_1 := #macro(internal_exposed) + #macro(external_exposed);

$i_sus := 1 - $i_expos_1 - $i_expos_2 - $i_expos_3 - $i_expos_4 - $i_expos_5 - $i_inf_1 - $i_inf_2 - $i_inf_3 - $i_inf_4 - $i_inf_5 - $i_inf_6 - $i_inf_7 - $i_inf_8 - $i_inf_9 - $i_inf_10 - $i_inf_11 - $i_inf_12 - $i_inf_13 - $i_inf_14 - $i_inf_15 - $i_inf_16 - $i_rec_1 - $i_rec_2 - $i_rec_3 - $i_rec_4 - $i_rec_5 - $i_rec_6 - $i_immune;

$i_total_e := #macro(total_exposed);
$i_total_i := #macro(total_infected);
$i_total_r := #macro(total_recovered);
}
1 { (0,0)~initial != -1 }
