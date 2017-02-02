#ifndef NODE_H
#define NODE_H


#include <vector>

class node
{
private:
    float m_xcord,m_ycord,m_zcord;
    int m_id;
    int m_shared_by{0};
    std::vector<double>m_nodeTract;          // Traction in x,y(,z) directions at node.
    std::vector<double>m_dispDof;            // x,y,z displacement at nodes.
    std::vector<double>m_stressDof;          // stress Dof at node.

public:
    node();
    node(int id,float x,float y);
    node(int id,float x, float y, float z);
    void printnode();
    void set_stressDof(int pos, double val);
    void set_nodeTract(int axis_no,double val);
    void set_dispDof(int constrain_no);
    int getindex() const;
    void count_sharing();
    bool is_boundary_node();
    int get_shared_by() const;
};
#endif // NODE_H
