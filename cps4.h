//comments added
#ifndef CPS4_H
#define CPS4_H
#include <utility>
#include "element.h"


class cps4 :public element
{
private:
public:
    cps4(int id, std::vector<node_ptr>);
    void print_element() const;
    void setedges();
    std::vector<node_ptr> get_face(unsigned int) const ;
    bool is_boundary() ;
    int elements_shared_by_face(std::vector<node_ptr> ) const;
    element_type get_element_type();
};

#endif // CPS4_H
