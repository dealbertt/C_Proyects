#ifndef JSON_H
#define JSON_H
#include "field.h"
#include "packet.h"
void toArray(char *arr[], char *line,int index);
char *toJson(packet_t *pack,fields_t *fields);
char *Value(char *line);
char *fieldToJson(char *field);
char *Key(char *line);
#endif
