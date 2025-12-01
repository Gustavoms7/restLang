/* vm.c - VM minimalista para assembly gerado pelo parser
   compile: gcc -o vm vm.c -std=c99
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STACK_MAX 1024
#define LINE_MAX 512
#define VARS_MAX 256
#define LABELS_MAX 512

typedef struct {
    char *name;
    char *value;
} Var;

typedef struct {
    char *label;
    int lineno;
} Label;

char *stack[STACK_MAX];
int sp = 0;

Var vars[VARS_MAX];
int varcount = 0;

Label labels[LABELS_MAX];
int labelcount = 0;

char *lines[10000];
int nlines = 0;

/* sensores / constantes */
double sistema_preco_kilo = 20.0;
double sistema_preco_rodizio = 50.0;
double sistema_preco_bebida = 6.0;

void push_str(const char *s) {
    if (sp >= STACK_MAX) { fprintf(stderr,"Stack overflow\n"); exit(1); }
    stack[sp++] = strdup(s);
}
char *pop_str() {
    if (sp <= 0) { return strdup("0"); }
    char *r = stack[--sp];
    return r;
}
char *peek_str() {
    if (sp <= 0) return strdup("0");
    return stack[sp-1];
}

void store_var(const char *name, const char *val) {
    for (int i=0;i<varcount;i++){
        if (strcmp(vars[i].name,name)==0) {
            free(vars[i].value);
            vars[i].value = strdup(val);
            return;
        }
    }
    if (varcount < VARS_MAX) {
        vars[varcount].name = strdup(name);
        vars[varcount].value = strdup(val);
        varcount++;
    } else {
        fprintf(stderr,"Too many vars\n");
    }
}

char* load_var(const char *name) {
    for (int i=0;i<varcount;i++){
        if (strcmp(vars[i].name,name)==0) return strdup(vars[i].value);
    }
    return strdup("0");
}

void add_label(const char *label, int lineno) {
    labels[labelcount].label = strdup(label);
    labels[labelcount].lineno = lineno;
    labelcount++;
}

int find_label(const char *label) {
    for (int i=0;i<labelcount;i++){
        if (strcmp(labels[i].label,label)==0) return labels[i].lineno;
    }
    return -1;
}

void trim(char *s) {
    int i=0,j=strlen(s)-1;
    while (s[i]==' '||s[i]=='\t') i++;
    while (j>=i && (s[j]==' '||s[j]=='\t'||s[j]=='\r'||s[j]=='\n')) { s[j]=0; j--; }
    if (i>0) memmove(s,s+i,strlen(s+i)+1);
}

void run() {
    /* primeira passagem: localizar labels */
    for (int i=0;i<nlines;i++){
        char buf[LINE_MAX];
        strncpy(buf, lines[i], LINE_MAX);
        trim(buf);
        int L = strlen(buf);
        if (L>0 && buf[L-1]==':') {
            buf[L-1]=0;
            trim(buf);
            add_label(buf, i);
        }
    }

    /* execução linha-a-linha */
    for (int pc=0; pc<nlines; pc++) {
        char line[LINE_MAX];
        strncpy(line, lines[pc], LINE_MAX);
        trim(line);
        if (strlen(line)==0) continue;
        /* rótulo: pular */
        int L = strlen(line);
        if (L>0 && line[L-1]==':') continue;
        /* parse básico de instrução */
        char instr[64];
        if (sscanf(line, "%63s", instr) != 1) continue;
        if (strcmp(instr,"PUSH")==0) {
            char *arg = strchr(line,' ');
            if (!arg) continue;
            trim(arg+1);
            push_str(arg+1);
        } else if (strcmp(instr,"POP")==0) {
            char *v = pop_str(); free(v);
        } else if (strcmp(instr,"DUP")==0) {
            char *v = peek_str();
            push_str(v);
            free(v);
        } else if (strcmp(instr,"ADD")==0) {
            char *a = pop_str(); char *b = pop_str();
            double da = atof(a); double db = atof(b);
            char buf[64]; snprintf(buf,64,"%g", da+db);
            push_str(buf);
            free(a); free(b);
        } else if (strcmp(instr,"SUB")==0) {
            char *a = pop_str(); char *b = pop_str();
            double da = atof(a); double db = atof(b);
            char buf[64]; snprintf(buf,64,"%g", db-da);
            push_str(buf);
            free(a); free(b);
        } else if (strcmp(instr,"STORE")==0) {
            char name[128], valbuf[256];
            if (sscanf(line+6, "%127s %255[^\n]", name, valbuf) >= 1) {
                trim(valbuf);
                if (strlen(valbuf)==0) {
                    /* se sem valor, pop */
                    char *v = pop_str();
                    store_var(name, v);
                    free(v);
                } else {
                    /* fórmula simples: valor literal ou var */
                    /* se string literal "..." */
                    if (valbuf[0]=='"') {
                        /* remove aspas */
                        char *s = strdup(valbuf+1);
                        s[strlen(s)-1]=0;
                        store_var(name, s);
                        free(s);
                    } else {
                        store_var(name, valbuf);
                    }
                }
            }
        } else if (strcmp(instr,"LOAD")==0) {
            char name[128];
            if (sscanf(line+5, "%127s", name)==1) {
                char *v = load_var(name);
                push_str(v);
                free(v);
            }
        } else if (strcmp(instr,"JMP")==0) {
            char label[128];
            if (sscanf(line+4, "%127s", label)==1) {
                int dest = find_label(label);
                if (dest>=0) { pc = dest; continue; }
            }
        } else if (strcmp(instr,"JZ")==0) {
            char label[128];
            if (sscanf(line+3, "%127s", label)==1) {
                char *v = pop_str();
                double dv = atof(v);
                free(v);
                if (dv == 0.0) {
                    int dest = find_label(label);
                    if (dest>=0) { pc = dest; continue; }
                }
            }
        } else if (strcmp(instr,"PRINT")==0) {
            char *arg = strchr(line,' ');
            if (!arg) continue;
            trim(arg+1);
            if (arg[1]=='"') {
                char *s = strdup(arg+2); s[strlen(s)-1]=0;
                printf("%s\n", s);
                free(s);
            } else {
                printf("%s\n", arg+1);
            }
        } else if (strcmp(instr,"PRINT_ATTR")==0) {
            char attr[128];
            if (sscanf(line+11,"%127s", attr)==1) {
                /* suportamos cliente.peso, cliente.bebidas, cliente.sobremesas, sistema.preco_kilo etc */
                if (strcmp(attr,"sistema.preco_kilo")==0) {
                    printf("%g\n", sistema_preco_kilo);
                } else if (strcmp(attr,"sistema.preco_rodizio")==0) {
                    printf("%g\n", sistema_preco_rodizio);
                } else if (strcmp(attr,"sistema.preco_bebida")==0) {
                    printf("%g\n", sistema_preco_bebida);
                } else if (strcmp(attr,"sistema.hora_atual")==0) {
                    time_t t = time(NULL);
                    struct tm *tm = localtime(&t);
                    printf("%02d:%02d:%02d\n", tm->tm_hour, tm->tm_min, tm->tm_sec);
                } else {
                    /* procurar var */
                    char *v = load_var(attr);
                    printf("%s\n", v);
                    free(v);
                }
            }
        } else if (strcmp(instr,"ADICIONAR_ITEM")==0) {
            /* apenas registra no log */
            char name[128]; int qtd=0;
            if (sscanf(line+13, " \"%127[^\"]\" %d", name, &qtd) >= 1) {
                printf("[VM] ADICIONAR_ITEM nome=\"%s\" qtd=%d\n", name, qtd);
            }
        } else if (strcmp(instr,"CALCULAR_PESO")==0) {
            char arg[64];
            if (sscanf(line+13, "%63s", arg)==1) {
                printf("[VM] CALCULAR_PESO %s -> cálculo simples aplicado\n", arg);
                /* exemplo: calcular total = peso * preco_kilo (se armazenado) */
                double peso = atof(arg);
                double total = peso * sistema_preco_kilo;
                printf("[VM] Total (peso*preco_kilo)= %g\n", total);
            }
        } else if (strcmp(instr,"FECHAR_CONTA")==0) {
            printf("[VM] FECHAR_CONTA: fechando comanda (simulação)\n");
        } else if (strcmp(instr,"SECTION")==0) {
            /* ignore */
        } else {
            /* instrução desconhecida: imprime para debug */
            printf("[VM] instr desconhecida: %s\n", line);
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) { fprintf(stderr, "Usage: %s <saida.asm>\n", argv[0]); return 1; }
    FILE *f = fopen(argv[1],"r");
    if (!f) { perror("fopen"); return 1; }
    char buf[LINE_MAX];
    while (fgets(buf, LINE_MAX, f)) {
        lines[nlines++] = strdup(buf);
    }
    fclose(f);
    run();
    return 0;
}
