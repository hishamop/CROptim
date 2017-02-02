#include <iostream>
#include "cmodel.h"
#include "cfileio.h"
using namespace std;

int main()
{
    CModel model;

    {
        CFileio read("input.in",&model);
    }

    model.print_nodes();
    model.print_elems();
    model.print_nodeset();
    model.print_elset();
}
