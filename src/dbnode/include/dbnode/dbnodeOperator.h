#ifndef DBNODEOPERATOR
#define DBNODEOPERATOR
#include <string>
struct dbNode {
    std::string name;
    int eng;
    int math;
    dbNode* prev;
    dbNode* next;
};

void reverseAll(dbNode** head_ref, dbNode** rear_ref);
void pushNew(dbNode** head_ref, dbNode** rear_ref, std::string new_name, int eng, int math);
void appendNew(dbNode** head_ref, dbNode** rear_ref, std::string new_name, int eng, int math);
dbNode* extract(dbNode** head_ref, dbNode** rear_ref, std::string name);
#endif
