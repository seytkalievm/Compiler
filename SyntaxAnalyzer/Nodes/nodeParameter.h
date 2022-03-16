#include <string>
#include <vector>
#include "node.h"

#ifndef COMPILER_NODEParameter_H
#define COMPILER_NODEParameter_H

class NodeParameter: public Node {
public:
    std::string name;
    int intVal;
    double realVal;
    bool booleanVal;
    std::vector <Node*> listVal;

    NodeParameter() {
        this->nodeType = "parameter";
        this->intVal = 0;
        this->realVal = 0.0;
        this->booleanVal = false;
        this->listVal = std::vector <Node*>();
    }

    virtual std::string getName() {
        return name;
    }
    virtual std::vector <Node*> getListVal() {
        return listVal;
    }
    virtual int getIntVal() {
        return intVal;
    }
    virtual double getRealVal() {
        return realVal;
    }
    virtual bool getBooleanVal() {
        return booleanVal;
    }

    virtual void setName(std::string name) {
        this->name = name;
    }
    virtual void setIntVal(int x) {
        this->intVal = x;
    }
    virtual void setRealVal(double x) {
        this->realVal = x;
    } 
    virtual void setBooleanVal(bool x) {
        this->booleanVal = x;
    }
    virtual void addListVal(Node* x) {
        this->listVal.push_back(x);
    }
};

#endif 