# TuringMachine-complier
auto make a turing machine in UCAS cs101 lab

## How to use it?
fill in the FILENAME and the alphabet(the alphabet should cover all the characters including B)
add your code to the `void work()`in the form below
complie and run the code,you can find the output in the FILENAME.out

## features

in this code 0 means L and 1 means R

+ `void write(string q_pre,char char_pre,char char_next,bool direction,string q_next);`

write a single line q_pre,char_pre,char_next,L/R,q_next

+ `void movuntil(string q_pre,char target,bool direction,bool direction_next,string q_next,char target_next='Z');`

q_pre move towards L/R until meet the target character and go to the q_next

if target_next is not blank,change the target to target_next

+ `void movuntil(string q_pre,string target,bool direction,bool direction_next,string q_next,char target_next='Z');`

q_pre move towards L/R until meet the characters in the target and go to the q_next

if target_next is not blank,change the target to target_next

+ `void movstep(string q_pre,int step,bool direction,string q_next);`

q_pre moves [step] steps L/R and go to q_next
