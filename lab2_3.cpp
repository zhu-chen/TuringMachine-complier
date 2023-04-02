#include <bits/stdc++.h>
using namespace std;

//settings
const string FILENAME="Turing";
vector<char> alphabet={'B','0','1','+','=','#'};

void write(string q_pre,char char_pre,char char_next,bool direction,string q_next);
void movuntil(string q_pre,char target,bool direction,bool direction_next,string q_next,char target_next='Z');
void movuntil(string q_pre,string target,bool direction,bool direction_next,string q_next,char target_next='Z');
void movstep(string q_pre,int step,bool direction,string q_next);

void work(){ //write your code here
    movuntil("q0",'=',1,0,"qadd_1_00");
    //the begin of first step
    write("qadd_1_00",'0','#',0,"qadd_2_00");
    write("qadd_1_00",'1','#',0,"qadd_2_01");
    write("qadd_1_01",'0','#',0,"qadd_2_01");
    write("qadd_1_01",'1','#',0,"qadd_2_10");
    //add the first number
    movuntil("qadd_2_00",'B',0,1,"qadd_3_00");
    movuntil("qadd_2_01",'B',0,1,"qadd_3_01");
    movuntil("qadd_2_10",'B',0,1,"qadd_3_10");
    //move to the begin of second number
    movuntil("qadd_3_00","+#",1,0,"qadd_4_00");
    movuntil("qadd_3_01","+#",1,0,"qadd_4_01");
    movuntil("qadd_3_10","+#",1,0,"qadd_4_10");
    //move to the end of second number
    write("qadd_4_00",'B','B',0,"qadd_5.5_00");
    write("qadd_4_01",'B','B',0,"qadd_5.5_01");
    write("qadd_4_10",'B','B',0,"qadd_5.5_10");
    //solve when the second number is 0
    write("qadd_4_00",'0','#',0,"qadd_5_00");
    write("qadd_4_00",'1','#',0,"qadd_5_01");
    write("qadd_4_01",'0','#',0,"qadd_5_01");
    write("qadd_4_01",'1','#',0,"qadd_5_10");
    write("qadd_4_10",'0','#',0,"qadd_5_10");
    write("qadd_4_10",'1','#',0,"qadd_5_11");
    //add the second number
    movuntil("qadd_5_00",'B',0,0,"qadd_5.5_00");
    movuntil("qadd_5_01",'B',0,0,"qadd_5.5_01");
    movuntil("qadd_5_10",'B',0,0,"qadd_5.5_10");
    movuntil("qadd_5_11",'B',0,0,"qadd_5.5_11");
    //move to the begin of result 
    movuntil("qadd_5.5_00",'B',0,1,"qadd_6_00",'0');
    movuntil("qadd_5.5_01",'B',0,1,"qadd_6_00",'1');
    movuntil("qadd_5.5_10",'B',0,1,"qadd_6_01",'0');
    movuntil("qadd_5.5_11",'B',0,1,"qadd_6_01",'1');
    //print the result
    movuntil("qadd_6_00",'+',1,1,"qadd_7_00");
    movuntil("qadd_6_01",'+',1,1,"qadd_7_01");
    //move to the begin of the first number
    movuntil("qadd_7_00",'#',1,0,"qadd_1_00");
    movuntil("qadd_7_01",'#',1,0,"qadd_1_01");
    //begin of next step
    write("qadd_1_00",'+','+',0,"qadd_sp2_00");
    write("qadd_1_01",'+','+',0,"qadd_sp2_01");
    //solve when the first number is 0
    movuntil("qadd_sp2_00",'B',0,1,"qadd_sp3_00");
    movuntil("qadd_sp2_01",'B',0,1,"qadd_sp3_01");
    //move to the begin of second number
    movuntil("qadd_sp3_00","+#",1,0,"qadd_sp4_00");
    movuntil("qadd_sp3_01","+#",1,0,"qadd_sp4_01");
    //move to the end of second number
    write("qadd_sp4_00",'0','#',0,"qadd_sp5_00");
    write("qadd_sp4_00",'1','#',0,"qadd_sp5_01");
    write("qadd_sp4_01",'0','#',0,"qadd_sp5_01");
    write("qadd_sp4_01",'1','#',0,"qadd_sp5_10");
    //add the second number
    movuntil("qadd_sp5_00",'B',0,0,"qadd_sp5.5_00");
    movuntil("qadd_sp5_01",'B',0,0,"qadd_sp5.5_01");
    movuntil("qadd_sp5_10",'B',0,0,"qadd_sp5.5_10");
    //move to the begin of result
    movuntil("qadd_sp5.5_00",'B',0,1,"qadd_sp6_00",'0');
    movuntil("qadd_sp5.5_01",'B',0,1,"qadd_sp6_00",'1');
    movuntil("qadd_sp5.5_10",'B',0,1,"qadd_sp6_01",'0');
    // print the result
    movuntil("qadd_sp6_00",'#',1,0,"qadd_sp4_00");
    movuntil("qadd_sp6_01",'#',1,0,"qadd_sp4_01");
    //move to the begin of the first number and begin of next step
    write("qadd_sp4_00",'B','B',0,"qmov_1.5");
    write("qadd_sp4_01",'B','B',0,"qmov_0");
    movuntil("qmov_0",'B',0,1,"qmov_1.5",'1');
    //begin the move of the result and solve the last carry
    movuntil("qmov_1",'B',0,0,"qmov_1.5");
    movuntil("qmov_1.5",'B',0,1,"qmov_2");
    //move to the begin of the result
    write("qmov_2",'0','B',1,"qmov_3_0");
    write("qmov_2",'1','B',1,"qmov_3_1");
    //detect one bit of the result
    movuntil("qmov_3_0",'=',1,1,"qmov_3.5_0");
    movuntil("qmov_3_1",'=',1,1,"qmov_3.5_1");
    movuntil("qmov_3.5_0",'B',1,0,"qmov_1",'0');
    movuntil("qmov_3.5_1",'B',1,0,"qmov_1",'1');
    //print one bit of the result
    write("qmov_2",'B','B',1,"qa");
}

/*
complier
direction:1 R 0 L
*/

int main(){
    freopen((FILENAME+".out").c_str(),"w",stdout);
    work();
    return 0;
}

void write(string q_pre,char char_pre,char char_next,bool direction,string q_next){
    cout<<q_pre<<","<<char_pre<<","<<char_next<<","<<(direction?'R':'L')<<","<<q_next<<endl;
}

void movuntil(string q_pre,char target,bool direction,bool direction_next,string q_next,char target_next){
    for(int i=0;i<alphabet.size();i++){
        if(alphabet[i]==target){
            write(q_pre,alphabet[i],(target_next=='Z')?alphabet[i]:target_next,direction_next,q_next);
        }else{
            write(q_pre,alphabet[i],alphabet[i],direction,q_pre);
        }
    }
}

void movuntil(string q_pre,string target,bool direction,bool direction_next,string q_next,char target_next){
    for(int i=0;i<alphabet.size();i++){
        if(target.find(alphabet[i])!=string::npos){
            write(q_pre,alphabet[i],(target_next=='Z')?alphabet[i]:target_next,direction_next,q_next);
        }else{
            write(q_pre,alphabet[i],alphabet[i],direction,q_pre);
        }
    }
}

void movstep(string q_pre,int step,bool direction,string q_next){
    for(int i=0;i<alphabet.size();i++){
        write(q_pre,alphabet[i],alphabet[i],direction,q_pre+"_step"+(char)(step-1+'0'));
    }
    for(int i=step-2;i;i--){
        for(int j=0;j<alphabet.size();j++){
            write(q_pre+"_step"+(char)(i+1+'0'),alphabet[j],alphabet[j],direction,q_pre+"_step"+(char)(i+'0'));
        }
    }
    for(int i=0;i<alphabet.size();i++){
        write(q_pre+"_step1",alphabet[i],alphabet[i],direction,q_next);
    }
}