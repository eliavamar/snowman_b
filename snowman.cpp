#include "snowman.hpp"
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
namespace ariel{
    const int l_up_arm=2;
    const int snowman_length=7;
    const int CASE_A=1;
    const int CASE_B=2;
    const int CASE_C=3;
    string hat_func(int h){
        string hat;
        if(h==CASE_A){
        hat="  _===_";}
        else if(h==CASE_B){
        hat= "   ___\n  .....";}
        else if(h==CASE_C){
        hat="    _ \n" "   /_\\ ";
        }
        else {
        hat="   ___\n  (_*_) "; 
        }
        return hat;
    }
    string nose_func(int n){
        string nose;
        if(n==CASE_A){
        nose=",";}
        else if(n==CASE_B){
        nose= ".";}
        else if(n==CASE_C){
        nose="_";}
        else {
        nose=" "; }
        return nose;

    }
    string eye_func(int e){
        string eye;
        if(e==CASE_A){
        eye=".";}
        else if(e==CASE_B){
        eye= "o";}
        else if(e==CASE_C){
        eye="O";}
        else {
        eye="-"; }
        return eye;
    }
     string l_arm_func(int arm){
        string l_arm;
        if(arm==CASE_A){
        l_arm="<";}
        else if(arm==CASE_B){
        l_arm= "\\";}
        else if(arm==CASE_C){
        l_arm="/";}
        else {
        l_arm=" "; }
        return l_arm;
    }
     string r_arm_func(int arm){
        string r_arm;
        if(arm==CASE_A){
        r_arm=">";}
        else if(arm==CASE_B){
        r_arm= "/";}
        else if(arm==CASE_C){
        r_arm="\\";}
        else {
        r_arm=" "; }
        return r_arm;
    }
    string face_func(int nose,int l_eye,int r_eye,int l_arm){
    string face;
    if(l_up_arm==l_arm){
    face=" "+l_arm_func(l_arm)+"("+eye_func(l_eye)+nose_func(nose)+eye_func(r_eye)+")";
    }
    else {face="  ("+eye_func(l_eye)+nose_func(nose)+eye_func(r_eye)+")";}
    return face;
    }    
    string toros_func(int t){
        string torso="(";
        if(t==CASE_A){
        torso+=" : ";}
        else if(t==CASE_B){
        torso+= "] [";}
        else if(t==CASE_C){
        torso+="> <";}
        else {
        torso+="   ";}
        torso+=")"; 
        return torso;
    }
      string base_body_func(int b){
           string base_body="  (";
        if(b==CASE_A){
        base_body=base_body+" : ";}
        else if(b==CASE_B){
       base_body=base_body+"\" \"";}
        else if(b==CASE_C){
        base_body=base_body+"___";}
        else{
        base_body=base_body+"   ";}
        base_body=base_body+")"; 
        return base_body;
    }
    string connet_face_to_body(int nose,int l_eye,int r_eye,int l_arm ,int r_arm,int toros_body){
        string face=face_func(nose,l_eye,r_eye,l_arm);
        string left_arm=l_arm_func(l_arm);
        string right_arm=r_arm_func(r_arm);
        string t_body=toros_func(toros_body);
        int up_body=2;
        int no_arm=4;
        if(l_arm!=l_up_arm){
        if(l_arm!=no_arm){t_body=left_arm+t_body;}
        else {t_body ="  "+t_body;}
        }
        if(r_arm==up_body){
        face=face+right_arm;}
        else { t_body=t_body+right_arm;}
        string body=" ";
        if(l_arm==no_arm){
         body=face+"\n"+t_body;}
        else {body=face+"\n"+" "+t_body;}
        return body;
    }
    void chack_input(int x){
        int f_unvalid=0;
        int sec_unvalid=4;
      if(x<f_unvalid){
      throw string("unvalid number");
      }
      const int reminder=10;
      for(int i=snowman_length;i>-1;i--){
      if(x%reminder==f_unvalid||x%reminder>sec_unvalid){
        throw string("unvalid number");
    }
    x=x/reminder;
 }
    if(x>f_unvalid){
    throw string("unvalid number");
    }

    }
    string snowman(int x){
    chack_input(x);
    const int reminder=10;
    int base=x%reminder;
    x=x/reminder;
    int torso=x%(reminder);
    x=x/reminder;
    int r_arm=x%(reminder);
    x=x/reminder;
    int l_arm=x%(reminder);
    x=x/reminder;
    int r_eye=x%(reminder);
    x=x/reminder;
    int l_eye=x%(reminder);
    x=x/reminder;
    int nose=x%(reminder);
    x=x/reminder;
    int hat_case=x%(reminder); 
    string hat=hat_func(hat_case);
    string mid_body=connet_face_to_body(nose,l_eye,r_eye,l_arm,r_arm,torso);
    string base_body=base_body_func(base);
    string snowman=hat+"\n"+ mid_body+"\n"+base_body;
  
    return snowman;
    } 
}

   