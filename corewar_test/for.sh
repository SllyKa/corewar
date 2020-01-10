MAPS="Eraser.cor ultima.cor"
NUM=2100
MIN=NUM
MAX=NUM+200
for (( i=$MIN; i <= $MAX; i++ ))
do
../vm_champs/corewar $MAPS -d $i > their;
./corewar -o $MAPS -dump $i > our;
diff their our >> diff.diff
echo "итерация $i" >> diff.diff
done
# # MAPS="fluttershy.cor bee_gees.cor"
# # NUM=25902
# # MIN=NUM
# # MAX=NUM+2
# # for (( i=$MIN; i <= $MAX; i++ ))
# # do
# # ./corewar_def $MAPS -d $i > their;
# # ./corewar $MAPS -dump $i > our;
# # diff their our >> diff.diff
# # done
# # MAPS="bee_gees.cor fluttershy.cor"
# # NUM=25902
# # MIN=NUM
# # MAX=NUM+2
# # for (( i=$MIN; i <= $MAX; i++ ))
# # do
# # ./corewar_def $MAPS -d $i > their;
# # ./corewar $MAPS -dump $i > our;
# # diff their our >> diff.diff
# # done
# MAPS="zork.cor zork.cor zork.cor"
# NUM=27432
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="jumper.cor jumper.cor jumper.cor"
# NUM=24401
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="fluttershy.cor fluttershy.cor fluttershy.cor"
# NUM=25902
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# # MAPS="bee_gees.cor bee_gees.cor bee_gees.cor"
# # NUM=25902
# # MIN=NUM
# # MAX=NUM+2
# # for (( i=$MIN; i <= $MAX; i++ ))
# # do
# # ./corewar_def $MAPS -d $i > their;
# # ./corewar $MAPS -dump $i > our;
# # diff their our >> diff.diff
# # done
# MAPS="zork.cor jumper.cor fluttershy.cor"
# NUM=24366
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="fluttershy.cor zork.cor jumper.cor"
# NUM=24366
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="zork.cor fluttershy.cor jumper.cor"
# NUM=24366
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="jumper.cor zork.cor fluttershy.cor"
# NUM=24366
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# # MAPS="jumper.cor bee_gees.cor fluttershy.cor"
# # NUM=24366
# # MIN=NUM
# # MAX=NUM+2
# # for (( i=$MIN; i <= $MAX; i++ ))
# # do
# # ./corewar_def $MAPS -d $i > their;
# # ./corewar $MAPS -dump $i > our;
# # diff their our >> diff.diff
# # done
# # MAPS="bee_gees.cor fluttershy.cor zork.cor"
# # NUM=24366
# # MIN=NUM
# # MAX=NUM+2
# # for (( i=$MIN; i <= $MAX; i++ ))
# # do
# # ./corewar_def $MAPS -d $i > their;
# # ./corewar $MAPS -dump $i > our;
# # diff their our >> diff.diff
# # done
# # MAPS="bee_gees.cor zork.cor jumper.cor"
# # NUM=24366
# # MIN=NUM
# # MAX=NUM+2
# # for (( i=$MIN; i <= $MAX; i++ ))
# # do
# # ./corewar_def $MAPS -d $i > their;
# # ./corewar $MAPS -dump $i > our;
# # diff their our >> diff.diff
# # done
# # MAPS="bee_gees.cor bee_gees.cor fluttershy.cor"
# # NUM=25902
# # MIN=NUM
# # MAX=NUM+2
# # for (( i=$MIN; i <= $MAX; i++ ))
# # do
# # ./corewar_def $MAPS -d $i > their;
# # ./corewar $MAPS -dump $i > our;
# # diff their our >> diff.diff
# # done
# MAPS="zork.cor zork.cor zork.cor zork.cor"
# NUM=26689
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="jumper.cor jumper.cor jumper.cor jumper.cor"
# NUM=24401
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="fluttershy.cor fluttershy.cor fluttershy.cor fluttershy.cor"
# NUM=25902
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# # MAPS="bee_gees.cor bee_gees.cor bee_gees.cor bee_gees.cor"
# # NUM=25902
# # MIN=NUM
# # MAX=NUM+2
# # for (( i=$MIN; i <= $MAX; i++ ))
# # do
# # ./corewar_def $MAPS -d $i > their;
# # ./corewar $MAPS -dump $i > our;
# # diff their our >> diff.diff
# # done
# # MAPS="zork.cor jumper.cor fluttershy.cor bee_gees.cor"
# # NUM=24366
# # MIN=NUM
# # MAX=NUM+2
# # for (( i=$MIN; i <= $MAX; i++ ))
# # do
# # ./corewar_def $MAPS -d $i > their;
# # ./corewar $MAPS -dump $i > our;
# # diff their our >> diff.diff
# # done
# # MAPS="zork.cor bee_gees.cor jumper.cor fluttershy.cor"
# # NUM=24366
# # MIN=NUM
# # MAX=NUM+2
# # for (( i=$MIN; i <= $MAX; i++ ))
# # do
# # ./corewar_def $MAPS -d $i > their;
# # ./corewar $MAPS -dump $i > our;
# # diff their our >> diff.diff
# # done
# MAPS="zork.cor bee_gees.cor jumper.cor zork.cor"
# NUM=24366
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="zork.cor fluttershy.cor jumper.cor zork.cor"
# NUM=24366
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="helltrain.cor fluttershy.cor"
# NUM=25902
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="jumper.cor helltrain.cor fluttershy.cor"
# NUM=24366
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="zork.cor helltrain.cor jumper.cor fluttershy.cor"
# NUM=24366
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="zork.cor helltrain.cor jumper.cor helltrain.cor"
# NUM=24366
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="helltrain.cor"
# NUM=27438
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="Code_eater.cor Hidden.cor le_pet_de_nonne.cor sencha.cor"
# NUM=27713
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="tchupka.cor TheHarvester.cor wave.cor"
# NUM=55555
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="zork.cor Olezhka_super.cor"
# NUM=33060
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="Olezhka_super.cor zork.cor"
# NUM=33060
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="tets.cor tets.cor"
# NUM=1535
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="add.cor add_carry.cor aff.cor and.cor"
# NUM=1535
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="and_or_xor_read_overflow.cor"
# NUM=1666
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="and_or_xor_read_overflow.cor and_or_xor_overflow.cor fork.cor fork2.cor"
# NUM=122666
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="fork_backflow.cor fork_neg_overflow.cor fork_overflow.cor fork_overflow_with_live.cor"
# NUM=61108
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="fork_neg_overflow_tru.cor"
# NUM=3060
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="ld_1.cor ld_2.cor ld_carry.cor ld_st_overflow.cor"
# NUM=1535
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="ldi_1.cor ldi_2.cor ldi_bug_in_zaz_corewar.cor ldi_carry.cor"
# NUM=1535
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="lfork.cor lfork_overflow.1.cor lfork_overflow.cor live.cor"
# NUM=1535
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="lld_overflow.cor lldi_carry.cor lldi_overflow.cor negative_st.cor"
# NUM=4605
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="or.cor process_next_pc_overflow.cor st.cor sti_1.cor"
# NUM=1535
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="sti_2.cor sub.cor sub_carry.cor t.cor"
# NUM=1535
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="test_limit.cor testing1.cor testing2.cor xor.cor"
# NUM=9214
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
# MAPS="zjmp_neg_overflow.cor zjmp_neg_overflow_fail.cor zjmp_overflow.cor"
# NUM=3080
# MIN=NUM
# MAX=NUM+2
# for (( i=$MIN; i <= $MAX; i++ ))
# do
# ./corewar_def $MAPS -d $i > their;
# ./corewar $MAPS -dump $i > our;
# diff their our >> diff.diff
# done
