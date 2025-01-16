#ifndef FIELD_H
#define FIELD_H
#define LENGTH 50
#define MAX_FIELDS 3
typedef struct fields{
    char f1[LENGTH];
    char f2[LENGTH];
    char f3[LENGTH];
}fields_t;

typedef struct array{
    char *values[MAX_FIELDS];
}array_t;

array_t *detectFields_test(FILE *ptr,int n);
fields_t *detectFields(FILE *ptr,int n);
char *ReadLine(FILE *ptr);

#endif
