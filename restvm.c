#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Um interpretador simples para instruções de texto:
   - SET var value
   - ADD var value
   - SUB var value
   - MUL var value
   - GET var dest
   - PRINT arg
   - LABEL name
   - JMP label
   - JNZ label  (jump if last_temp != 0)
   - IF <cond> GOTO label (cond as "a > b" where a,b são var/number)
   - HALT
*/

typedef struct Var {
    char name[128];
    double val_num;
    char val_str[256];
    int is_str;
    struct Var *next;
} Var;

Var *vars = NULL;
double last_temp = 0;

Var* find_var(const char *name) {
    Var *p = vars;
    while (p) { if (strcmp(p->name, name)==0) return p; p=p->next; }
    return NULL;
}
Var* set_var(const char *name, double v, const char *s, int is_str) {
    Var *p = find_var(name);
    if (!p) {
        p = (Var*)malloc(sizeof(Var));
        strcpy(p->name, name);
        p->val_num = 0;
        p->val_str[0]=0;
        p->is_str = 0;
        p->next = vars; vars = p;
    }
    p->val_num = v;
    if (is_str && s) { strncpy(p->val_str, s, 255); p->is_str = 1; } else p->is_str = 0;
    return p;
}

double get_num(const char *token) {
    Var *v = find_var(token);
    if (v) return v->val_num;
    return atof(token);
}

/* Retorna string de uma variável ou o próprio token */
const char* get_str(const char *token) {
    Var *v = find_var(token);
    if (v && v->is_str) return v->val_str;
    return token;
}

int is_label(const char *s) {
    return 1; /* labels are handled separately */
}

int main(int argc, char **argv) {
    FILE *f = fopen("out.asm","r");
    if (!f) { perror("out.asm"); return 1; }
    /* read lines into memory for two-pass (resolve labels) */
    char **lines = NULL;
    int nlines=0;
    char buf[1024];
    while (fgets(buf, sizeof(buf), f)) {
        lines = realloc(lines, sizeof(char*)*(nlines+1));
        lines[nlines] = strdup(buf);
        nlines++;
    }
    fclose(f);

    /* map labels to line indices */
    typedef struct Label { char name[128]; int idx; struct Label *next;} Label;
    Label *labels = NULL;
    for (int i=0;i<nlines;i++){
        if (strncmp(lines[i],"LABEL ",6)==0) {
            char name[128]; sscanf(lines[i]+6, "%127s", name);
            Label *L = malloc(sizeof(Label)); strcpy(L->name,name); L->idx = i; L->next = labels; labels = L;
        }
    }

    int pc = 0;
    while (pc < nlines) {
        char *line = lines[pc];
        /* trim leading spaces */
        char *p = line;
        while (*p==' '||*p=='\t') p++;
        if (strncmp(p,"#",1)==0 || *p==0) { pc++; continue; }
        if (strncmp(p,"SET ",4)==0) {
            char name[128]; char rest[256];
            sscanf(p+4, "%127s %255[^\n]", name, rest);
            /* if rest starts with quote -> string */
            if (rest[0]=='"') {
                /* remove quotes */
                char tmp[256]; int L=strlen(rest);
                if (rest[L-1]=='\n') rest[L-1]=0;
                if (rest[strlen(rest)-1]=='"') {
                    rest[strlen(rest)-1]=0;
                }
                char *s = rest+1;
                set_var(name, 0, s, 1);
            } else {
                double v = get_num(rest);
                set_var(name, v, NULL, 0);
            }
            pc++; continue;
        }
        if (strncmp(p,"ADD ",4)==0) {
            char name[128]; char rest[256];
            sscanf(p+4, "%127s %255[^\n]", name, rest);
            double v = get_num(rest);
            Var *vv = find_var(name);
            if (!vv) vv = set_var(name, 0, NULL, 0);
            vv->val_num += v;
            last_temp = vv->val_num;
            pc++; continue;
        }
        if (strncmp(p,"SUB ",4)==0) {
            char name[128]; char rest[256];
            sscanf(p+4, "%127s %255[^\n]", name, rest);
            double v = get_num(rest);
            Var *vv = find_var(name);
            if (!vv) vv = set_var(name, 0, NULL, 0);
            vv->val_num -= v;
            last_temp = vv->val_num;
            pc++; continue;
        }
        if (strncmp(p,"MUL ",4)==0) {
            char a[128], b[128];
            sscanf(p+4, "%127s %127s", a, b);
            double va = get_num(a);
            double vb = get_num(b);
            double res = va * vb;
            /* store back to first operand if it's a var */
            Var *vv = find_var(a);
            if (vv) { vv->val_num = res; last_temp = res; }
            else last_temp = res;
            pc++; continue;
        }
        if (strncmp(p,"GET ",4)==0) {
            /* GET var destVar */
            char a[128], b[128];
            sscanf(p+4, "%127s %127s", a, b);
            double v = get_num(a);
            set_var(b, v, NULL, 0);
            last_temp = v;
            pc++; continue;
        }
        if (strncmp(p,"PRINT ",6)==0) {
            char rest[256];
            sscanf(p+6, "%255[^\n]", rest);
            if (rest[0]=='"') {
                /* string literal */
                int L=strlen(rest);
                if (rest[L-1]=='\n') rest[L-1]=0;
                if (rest[strlen(rest)-1]=='"') rest[strlen(rest)-1]=0;
                printf("%s\n", rest+1);
            } else {
                /* var or number */
                Var *v = find_var(rest);
                if (v) {
                    if (v->is_str) printf("%s\n", v->val_str);
                    else printf("%g\n", v->val_num);
                } else {
                    printf("%s\n", rest);
                }
            }
            pc++; continue;
        }
        if (strncmp(p,"JMP ",4)==0) {
            char label[128]; sscanf(p+4, "%127s", label);
            Label *L = labels;
            int found = -1;
            while (L) { if (strcmp(L->name,label)==0) { found = L->idx; break; } L=L->next; }
            if (found>=0) { pc = found+1; continue; } else pc++; continue;
        }
        if (strncmp(p,"JNZ ",4)==0) {
            char label[128]; sscanf(p+4, "%127s", label);
            if (last_temp != 0) {
                Label *L = labels; int found=-1;
                while (L) { if (strcmp(L->name,label)==0) { found = L->idx; break; } L=L->next; }
                if (found>=0) { pc = found+1; continue; }
            }
            pc++; continue;
        }
        if (strncmp(p,"IF ",3)==0) {
            /* basic parse: IF a > b GOTO label ou IF a == b GOTO label */
            char a[128], op[4], b[128], goto_kw[8], label[128];
            sscanf(p+3, "%127s %3s %127s %7s %127s", a, op, b, goto_kw, label);
            
            int cond = 0;
            Var *va_var = find_var(a);
            
            /* Remove aspas de b se existirem (literal string) */
            char b_clean[128];
            if (b[0] == '"') {
                int len = strlen(b);
                strncpy(b_clean, b+1, len-2);
                b_clean[len-2] = '\0';
            } else {
                strcpy(b_clean, b);
            }
            
            Var *vb_var = find_var(b_clean);
            
            /* Se o operando 'a' é string ou 'b' é literal string, faz comparação de strings */
            if ((va_var && va_var->is_str) || b[0] == '"') {
                const char *sa = get_str(a);
                const char *sb = (b[0] == '"') ? b_clean : get_str(b_clean);
                if (strcmp(op, "==")==0) cond = (strcmp(sa, sb) == 0);
                else if (strcmp(op, "!=")==0) cond = (strcmp(sa, sb) != 0);
            } else {
                /* Comparação numérica */
                double va = get_num(a), vb = get_num(b);
                if (strcmp(op, ">")==0) cond = (va > vb);
                else if (strcmp(op, "<")==0) cond = (va < vb);
                else if (strcmp(op, "==")==0) cond = (va == vb);
            }
            
            if (cond) {
                Label *L = labels; int found=-1;
                while (L) { if (strcmp(L->name,label)==0) { found = L->idx; break; } L=L->next; }
                if (found>=0) { pc = found+1; continue; }
            }
            pc++; continue;
        }
        if (strncmp(p,"HALT",4)==0) break;
        pc++;
    }

    return 0;
}
