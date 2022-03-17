#include <string>
#include <vector>
#include <iostream>

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Transforms/Utils/FunctionComparator.h"

#ifndef COMPILER_NODE_H
#define COMPILER_NODE_H

static llvm::LLVMContext TheContext;
static llvm::IRBuilder<> Builder(TheContext);
static std::unique_ptr<llvm::Module> TheModule = std::make_unique<llvm::Module>("soso", TheContext);
static std::map<std::string, llvm::Value *> NamedValues;

class Node {
public:
    std::string nodeType;

    virtual llvm::Value *codegen() = 0;

    virtual std::string getName(){
        return "";
    } 
    virtual std::vector<Node*> getParameters(){
        return std::vector<Node*>();
    }       
    virtual Node* getDeclaration(){
        return NULL;
    }
    virtual Node* getExpression(){
        return NULL;
    }
    virtual std::vector <Node*> getListVal(){
         return std::vector<Node*>();
    }
    virtual int getIntVal(){
        return 0;
    }
    virtual double getRealVal(){
        return 0;
    }
    virtual bool getBooleanVal(){
        return 0;
    }
    virtual std::string getType(){
        return "";
    }   

    virtual void setDeclaration(Node* node){
        
    }
    virtual void setExpression(Node* node){

    }
    virtual void setName(std::string name){

    }
    virtual void addParameter(Node* node){

    }
    virtual void setIntVal(int x){

    }
    virtual void setRealVal(double x){

    }
    virtual void setBooleanVal(bool x){

    }
    virtual void addListVal(Node* x){

    }
    virtual void setType(std::string x){
        
    }
};

#endif //COMPILER_NODE_H
