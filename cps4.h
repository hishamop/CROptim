#ifndef CPS4_H
#define CPS4_H
#include <utility>
#include "element.h"


class cps4 :public element
{
public:
    cps4(int id, std::vector<node_ptr>);
    void print_element() const;
    void setedges();
    bool is_boundary_element();

};

#endif // CPS4_H
