

#ifndef FUNCTIONPARSER_H
#define FUNCTIONPARSER_H

struct function_element {
    char op;
    double rval;
    struct function_element *next;
};

#endif