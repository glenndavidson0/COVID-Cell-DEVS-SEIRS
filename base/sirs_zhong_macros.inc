
#BeginMacro(local_cured) 
(( round(min($cured_rate * $i_inf_15, 1)*100) +
round(min($cured_rate * $i_inf_14, 1)*100) +
round(min($cured_rate * $i_inf_13, 1)*100) +
round(min($cured_rate * $i_inf_12, 1)*100) +
round(min($cured_rate * $i_inf_11, 1)*100) +
round(min($cured_rate * $i_inf_10, 1)*100) +
round(min($cured_rate * $i_inf_9, 1)*100) +
round(min($cured_rate * $i_inf_8, 1)*100) +
round(min($cured_rate * $i_inf_7, 1)*100) +
round(min($cured_rate * $i_inf_6, 1)*100) +
round(min($cured_rate * $i_inf_5, 1)*100) +
round(min($cured_rate * $i_inf_4, 1)*100) +
round(min($cured_rate * $i_inf_3, 1)*100) +
round(min($cured_rate * $i_inf_2, 1)*100) +
round(min($cured_rate * $i_inf_1, 1)*100) ) / 100 )
#EndMacro

#BeginMacro(internal_exposed) 
( round(min(( 
$i_sus * (
($v_16 * $i_inf_16) +
($v_15 * $i_inf_15) +
($v_14 * $i_inf_14) +
($v_13 * $i_inf_13) +
($v_12 * $i_inf_12) +
($v_11 * $i_inf_11) +
($v_10 * $i_inf_10) +
($v_9 * $i_inf_9) +
($v_8 * $i_inf_8) +
($v_7 * $i_inf_7) +
($v_6 * $i_inf_6) +
($v_5 * $i_inf_5) +
($v_4 * $i_inf_4) +
($v_3 * $i_inf_3) +
($v_2 * $i_inf_2) +
($v_1 * $i_inf_1)
)), 1)*100) / 100 )
#EndMacro

#BeginMacro(external_exposed) 
( round(min((
$connection * $movement * $i_sus * (
((1,0)~pop / $population) * $v_16 * (1,0)~inf_16 +
((1,0)~pop / $population) * $v_15 * (1,0)~inf_15 +
((1,0)~pop / $population) * $v_14 * (1,0)~inf_14 +
((1,0)~pop / $population) * $v_13 * (1,0)~inf_13 +
((1,0)~pop / $population) * $v_12 * (1,0)~inf_12 +
((1,0)~pop / $population) * $v_11 * (1,0)~inf_11 +
((1,0)~pop / $population) * $v_10 * (1,0)~inf_10 +
((1,0)~pop / $population) * $v_9 * (1,0)~inf_9 +
((1,0)~pop / $population) * $v_8 * (1,0)~inf_8 +
((1,0)~pop / $population) * $v_7 * (1,0)~inf_7 +
((1,0)~pop / $population) * $v_6 * (1,0)~inf_6 +
((1,0)~pop / $population) * $v_5 * (1,0)~inf_5 +
((1,0)~pop / $population) * $v_4 * (1,0)~inf_4 +
((1,0)~pop / $population) * $v_3 * (1,0)~inf_3 +
((1,0)~pop / $population) * $v_2 * (1,0)~inf_2 +
((1,0)~pop / $population) * $v_1 * (1,0)~inf_1
)), 1)*100) / 100 ) +
( round(min((
$connection * $movement * $i_sus * (
((0,-1)~pop / $population) * $v_16 * (0,-1)~inf_16 +
((0,-1)~pop / $population) * $v_15 * (0,-1)~inf_15 +
((0,-1)~pop / $population) * $v_14 * (0,-1)~inf_14 +
((0,-1)~pop / $population) * $v_13 * (0,-1)~inf_13 +
((0,-1)~pop / $population) * $v_12 * (0,-1)~inf_12 +
((0,-1)~pop / $population) * $v_11 * (0,-1)~inf_11 +
((0,-1)~pop / $population) * $v_10 * (0,-1)~inf_10 +
((0,-1)~pop / $population) * $v_9 * (0,-1)~inf_9 +
((0,-1)~pop / $population) * $v_8 * (0,-1)~inf_8 +
((0,-1)~pop / $population) * $v_7 * (0,-1)~inf_7 +
((0,-1)~pop / $population) * $v_6 * (0,-1)~inf_6 +
((0,-1)~pop / $population) * $v_5 * (0,-1)~inf_5 +
((0,-1)~pop / $population) * $v_4 * (0,-1)~inf_4 +
((0,-1)~pop / $population) * $v_3 * (0,-1)~inf_3 +
((0,-1)~pop / $population) * $v_2 * (0,-1)~inf_2 +
((0,-1)~pop / $population) * $v_1 * (0,-1)~inf_1
)), 1)*100) / 100 ) +
( round(min((
$connection * $movement * $i_sus * (
((0,1)~pop / $population) * $v_16 * (0,1)~inf_16 +
((0,1)~pop / $population) * $v_15 * (0,1)~inf_15 +
((0,1)~pop / $population) * $v_14 * (0,1)~inf_14 +
((0,1)~pop / $population) * $v_13 * (0,1)~inf_13 +
((0,1)~pop / $population) * $v_12 * (0,1)~inf_12 +
((0,1)~pop / $population) * $v_11 * (0,1)~inf_11 +
((0,1)~pop / $population) * $v_10 * (0,1)~inf_10 +
((0,1)~pop / $population) * $v_9 * (0,1)~inf_9 +
((0,1)~pop / $population) * $v_8 * (0,1)~inf_8 +
((0,1)~pop / $population) * $v_7 * (0,1)~inf_7 +
((0,1)~pop / $population) * $v_6 * (0,1)~inf_6 +
((0,1)~pop / $population) * $v_5 * (0,1)~inf_5 +
((0,1)~pop / $population) * $v_4 * (0,1)~inf_4 +
((0,1)~pop / $population) * $v_3 * (0,1)~inf_3 +
((0,1)~pop / $population) * $v_2 * (0,1)~inf_2 +
((0,1)~pop / $population) * $v_1 * (0,1)~inf_1
)), 1)*100) / 100 ) +
( round(min((
$connection * $movement * $i_sus * (
((-1,0)~pop / $population) * $v_16 * (-1,0)~inf_16 +
((-1,0)~pop / $population) * $v_15 * (-1,0)~inf_15 +
((-1,0)~pop / $population) * $v_14 * (-1,0)~inf_14 +
((-1,0)~pop / $population) * $v_13 * (-1,0)~inf_13 +
((-1,0)~pop / $population) * $v_12 * (-1,0)~inf_12 +
((-1,0)~pop / $population) * $v_11 * (-1,0)~inf_11 +
((-1,0)~pop / $population) * $v_10 * (-1,0)~inf_10 +
((-1,0)~pop / $population) * $v_9 * (-1,0)~inf_9 +
((-1,0)~pop / $population) * $v_8 * (-1,0)~inf_8 +
((-1,0)~pop / $population) * $v_7 * (-1,0)~inf_7 +
((-1,0)~pop / $population) * $v_6 * (-1,0)~inf_6 +
((-1,0)~pop / $population) * $v_5 * (-1,0)~inf_5 +
((-1,0)~pop / $population) * $v_4 * (-1,0)~inf_4 +
((-1,0)~pop / $population) * $v_3 * (-1,0)~inf_3 +
((-1,0)~pop / $population) * $v_2 * (-1,0)~inf_2 +
((-1,0)~pop / $population) * $v_1 * (-1,0)~inf_1
)), 1)*100) / 100 )
#EndMacro

#BeginMacro(internal_infected) 
( round(min(( 
($icb_4 * $i_expos_4) +
($icb_3 * $i_expos_3) +
($icb_2 * $i_expos_2) +
($icb_1 * $i_expos_1)
), 1)*100) / 100 )
#EndMacro

#BeginMacro(total_exposed)
($i_expos_1 +
 $i_expos_2 +
 $i_expos_3 + 
 $i_expos_4 +
 $i_expos_5)
#EndMacro

#BeginMacro(total_infected)
($i_inf_16 +
 $i_inf_15 +
 $i_inf_14 +
 $i_inf_13 +
 $i_inf_12 +
 $i_inf_11 +
 $i_inf_10 +
 $i_inf_9 +
 $i_inf_8 +
 $i_inf_7 +
 $i_inf_6 +
 $i_inf_5 +
 $i_inf_4 +
 $i_inf_3 +
 $i_inf_2 +
 $i_inf_1)
#EndMacro

#BeginMacro(total_recovered)
($i_rec_6 +
 $i_rec_5 +
 $i_rec_4 +
 $i_rec_3 +
 $i_rec_2 +
 $i_rec_1)
#EndMacro
