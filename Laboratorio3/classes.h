#ifndef CLASSES_H
#define	CLASSES_H

enum lines {
    NOLINE, SINGLELINE, DOUBLELINE
};

enum modes {
    NOMODE, INT_FLOAT, INT_INT_INT
};

enum parameters {
    KTE_E, KTE_A, KTE_f
};

enum sizes {
    NODES, ELEMENTS, DIRICHLET, NEUMANN
};

class item {
protected:
    int id;
    float x;
    int node1;
    int node2;
    float value;

public:

    int getId() {
        return id;
    }

    float getX() {
        return x;
    }

    int getNode1() {
        return node1;
    }

    int getNode2() {
        return node2;
    }

    float getValue() {
        return value;
    }

    virtual void setIntFloat(int n, float r) = 0;
    virtual void setIntIntInt(int n1, int n2, int n3) = 0;

};

class node : public item {
public:

    void setIntFloat(int identifier, float x_coordinate) {
        id = identifier;
        x = x_coordinate;
    }

    void setIntIntInt(int n1, int n2, int n3) {
    }
};

class element : public item {
public:

    void setIntFloat(int n1, float r) {
    }

    void setIntIntInt(int identifier, int firstnode, int secondnode) {
        id = identifier;
        node1 = firstnode;
        node2 = secondnode;
    }
};

class condition : public item {
public:

    void setIntFloat(int node_to_apply, float prescribed_value) {
        node1 = node_to_apply;
        value = prescribed_value;
    }

    void setIntIntInt(int n1, int n2, int n3) {
    }
};

class mesh {
    float parameters[2];
    int sizes[4];
    node *node_list;
    element *element_list;
    condition *dirichlet_list;
    condition *neumann_list;
public:

    void setParameters(float E, float A, float f ) {
        parameters[KTE_E] = E;
        parameters[KTE_A] = A;
        parameters[KTE_f] = f;
    }

    void setSizes(int nnodes, int neltos, int ndirich, int nneu) {
        sizes[NODES] = nnodes;
        sizes[ELEMENTS] = neltos;
        sizes[DIRICHLET] = ndirich;
        sizes[NEUMANN] = nneu;
    }

    int getSize(int s) {
        return sizes[s];
    }

    float getParameter(int p) {
        return parameters[p];
    }

    void createData() {
        node_list = new node[sizes[NODES]];
        element_list = new element[sizes[ELEMENTS]];
        dirichlet_list = new condition[sizes[DIRICHLET]];
        neumann_list = new condition[sizes[NEUMANN]];
    }

    node* getNodes() {
        return node_list;
    }

    element* getElements() {
        return element_list;
    }

    condition* getDirichlet() {
        return dirichlet_list;
    }

    condition* getNeumann() {
        return neumann_list;
    }

    node getNode(int i) {
        return node_list[i];
    }

    element getElement(int i) {
        return element_list[i];
    }

    condition getCondition(int i, int type) {
        if (type == DIRICHLET) return dirichlet_list[i];
        else return neumann_list[i];
    }
};


#endif	/* CLASSES_H */

