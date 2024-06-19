#include "list.hpp"

int main(void)
{
    intCell *a = null;
    intCell *b = new intCell(1, null, null);
    intCell *back = null;
    // intCell *c = new intCell(5, null, null);

    a = b;
    b = new intCell(2, a, null);
    a->right = b;
    // b->right = c;

    a->print();
    printf("\n");

    printf("\n");
    return (0);
}