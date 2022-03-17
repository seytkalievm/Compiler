#include <string>
#include <vector>
#include "node.h"

#ifndef COMPILER_NODELITERAL_H
#define COMPILER_NODELITERAL_H

class NodeLiteral: public Node {
public:
    std::string name;
    int intVal;
    double realVal;
    bool booleanVal;
    std::vector <Node*> listVal;

    NodeLiteral() {
        this->nodeType = "literal";
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
    virtual llvm::Value *codegen() {
        if (name == "real") {
            return llvm::ConstantFP::get(TheContext, llvm::APFloat(realVal));
        }
        if (name == "int") {
            return llvm::ConstantInt::get(TheContext, llvm::APInt(32, intVal));
        }
        if (name == "boolean") {
            return llvm::ConstantInt::get(TheContext, llvm::APInt(1, (int)booleanVal));
        }
        if (name == "list") {
            auto *VectorTy = llvm::VectorType::get(listVal[0]->codegen()->getType(), (int)listVal.size(), true);
            llvm::Value *vec = llvm::UndefValue::get(VectorTy);
            int counter = 0;
            for (auto el: listVal) {
                auto element = el->codegen();
                if (element->getType() != listVal[0]->codegen()->getType()) {
                    std::cout << "not same type";
                    exit(0);
                }
                vec = Builder.CreateInsertElement(vec, element, counter++);
            }
            return vec;
        }
    }
};

#endif 