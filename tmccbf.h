#ifndef TMCCBF
    #define TMCCBF
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<stdbool.h>

    #define MAX_LENGTH 4096
    const char *tk_plus = "SMD";	        //+
    const char *tk_minus = "にゃんこ";	    //-
    const char *tk_gt = "しの";	        //>
    const char *tk_lt = "さばにき";	    	//<
    const char *tk_period = "ゲェジ";	    //.
    const char *tk_comma = "がりん";         //,
    const char *tk_lb = "NEMO";             //[
    const char *tk_rb = "キュゥ";             //]

    bool DEBUG_MODE = false;

    extern char *contents2var(FILE *file_contents);
    extern void str2plus(char *from_str);
    extern void str2minus(char *from_str);
    extern void str2gt(char *from_str);
    extern void str2lt(char *from_str);
    extern void str2period(char *from_str);
    extern void str2comma(char *from_str);
    extern void str2lb(char *from_str);
    extern void str2rb(char *from_str);
    extern void str2tk(char *from_str);
    extern void exec(char *strin);
#endif