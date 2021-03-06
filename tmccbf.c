#include"tmccbf.h"

int main(int argc, char **argv) {
    char *file_in;

    if(argc == 1) {
        usage();
    } else if(argc == 2) {
        file_in = argv[1];
    } else {
        for(int i = 1; i < 3; i++) {
            if(!strcmp(argv[i], "-d"))
                DEBUG_MODE = true;
            else
                file_in = argv[i];
        }
    }

    char *file_ex;

    if((file_ex = strstr(file_in, ".")) == NULL) {
        fprintf(stderr, "[error] FileType: this is not .tmcc\n");
        exit(1);
    } else {
        if(strcmp(file_ex, ".tmcc")) {
            fprintf(stderr, "[error] FileType: this is not .tmcc, but %s\n", file_ex);
            exit(1);
        }
    }

    FILE* f;

    if((f = fopen(file_in, "r")) == NULL) {
        fprintf(stderr, "[error] File: file open failed\n");
        exit(1);
    }

    char *contents = contents2var(f);

    if(DEBUG_MODE) {
        printf("file input: %s\n", contents);
    }

    str2tk(contents);

    if(DEBUG_MODE) {
        printf("token: %s\n", contents);
        printf("output: \n");
    }
    exec(contents);

    free(contents);
    fclose(f);

    return 0;
}

char *contents2var(FILE *file_contents) {
    char *strp;

    fseek(file_contents, 0, SEEK_END);
    int file_size = ftell(file_contents);

    if(DEBUG_MODE) {
        printf("file_size: %d\n", file_size);
    }

    if(file_size > MAX_LENGTH) {
        fprintf(stderr, "[error] Size: File size too large.\n");
        exit(1);
    }


    if((strp = malloc(file_size)) == NULL) {
        fprintf(stderr,"[error] malloc error\n");
        exit(1);
    }

    fseek(file_contents, 0, SEEK_SET);

    for(int i = 0; i < file_size; i++) {
        strp[i] = fgetc(file_contents);
    }

    return strp;
}

//これしか思いつかんかった
void str2tk(char *from_str) {
    str2plus(from_str);
    str2minus(from_str);
    str2gt(from_str);
    str2lt(from_str);
    str2period(from_str);
    str2comma(from_str);
    str2lb(from_str);
    str2rb(from_str);
}

void str2plus(char *from_str) {
    char *p;
    char tmp[strlen(from_str)];             //ここきらい

    while((p = strstr(from_str, tk_plus)) != NULL) {
        *p = '\0';
        p += strlen(tk_plus);
        strcpy(tmp, p);
        strcat(from_str, "+");
        strcat(from_str, tmp);
    }
}

void str2minus(char *from_str) {
    char *p;
    char tmp[strlen(from_str)];             //ここきらい

    while((p = strstr(from_str, tk_minus)) != NULL) {
        *p = '\0';
        p += strlen(tk_minus);
        strcpy(tmp, p);
        strcat(from_str, "-");
        strcat(from_str, tmp);
    }
}

void str2gt(char *from_str) {
    char *p;
    char tmp[strlen(from_str)];             //ここきらい

    while((p = strstr(from_str, tk_gt)) != NULL) {
        *p = '\0';
        p += strlen(tk_gt);
        strcpy(tmp, p);
        strcat(from_str, ">");
        strcat(from_str, tmp);
    }
}

void str2lt(char *from_str) {
    char *p;
    char tmp[strlen(from_str)];             //ここきらい

    while((p = strstr(from_str, tk_lt)) != NULL) {
        *p = '\0';
        p += strlen(tk_lt);
        strcpy(tmp, p);
        strcat(from_str, "<");
        strcat(from_str, tmp);
    }
}

void str2period(char *from_str) {
    char *p;
    char tmp[strlen(from_str)];             //ここきらい

    while((p = strstr(from_str, tk_period)) != NULL) {
        *p = '\0';
        p += strlen(tk_period);
        strcpy(tmp, p);
        strcat(from_str, ".");
        strcat(from_str, tmp);
    }
}

void str2comma(char *from_str) {
    char *p;
    char tmp[strlen(from_str)];             //ここきらい

    while((p = strstr(from_str, tk_comma)) != NULL) {
        *p = '\0';
        p += strlen(tk_comma);
        strcpy(tmp, p);
        strcat(from_str, ",");
        strcat(from_str, tmp);
    }
}

void str2lb(char *from_str) {
    char *p;
    char tmp[strlen(from_str)];             //ここきらい

    while((p = strstr(from_str, tk_lb)) != NULL) {
        *p = '\0';
        p += strlen(tk_lb);
        strcpy(tmp, p);
        strcat(from_str, "[");
        strcat(from_str, tmp);
    }
}

void str2rb(char *from_str) {
    char *p;
    char tmp[strlen(from_str)];             //ここきらい

    while((p = strstr(from_str, tk_rb)) != NULL) {
        *p = '\0';
        p += strlen(tk_rb);
        strcpy(tmp, p);
        strcat(from_str, "]");
        strcat(from_str, tmp);
    }
}

void exec(char *strin) {
    if(strlen(strin) > 30000) {
        fprintf(stderr, "[error] file size too large\n");
        exit(1);
    }

    char data[30000] = {0};
    char *ptr = data;
    char current;
    int nest;

    for(int i = 0; strin[i] != 0; i++) {
        current = strin[i];

        if(current == '>')
            ptr++;
        else if(current == '<')
            ptr--;
        else if(current == '+')
            (*ptr)++;
        else if(current == '-')
            (*ptr)--;
        else if(current == '.')
            putchar(*ptr);
        else if(current == ',')
            *ptr = getchar();
        else if(current == '[')
            continue;
        else if(current == ']' && *ptr) {
            nest = 1;

            while(nest > 0) {
                current = strin[--i];
                if(current == '[')
                    nest--;
                else if(current == ']')
                    nest++;
            }
        }
    }
}

void usage() {
    fprintf(stderr, "[error] Usage: tmccbf <filename> [option]\n");
    exit(1);
}
