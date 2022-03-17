#include <string>
#include <vector>
#include "node.h"

#ifndef COMPILER_NODEINVOCATION_H
#define COMPILER_NODEINVOCATION_H

class NodeInvocation: public Node {
public:
    std::string name;
    std::vector<Node*> parameters;
    Node* declaration;

    NodeInvocation() {
        this->nodeType = "Invocation";
    }

    virtual std::string getName() {
        return name;
    }
    virtual std::vector <Node*> getParameters() {
        return parameters;
    }
    virtual Node* getDeclaration() {
        return declaration;
    }

    virtual void setDeclaration(Node* declaration) {
        this->declaration = declaration;
    }
    virtual void setName(std::string name) {
        this->name = name;
    }
    virtual void addParameter(Node* node) {
        parameters.push_back(node);
    }

    virtual llvm::Value *codegen() {
        if (getDeclaration()->getType() == "variable") {
            llvm::Value *V = getDeclaration()->getExpression()->codegen();
            return V;
        }
        if (getDeclaration()->getType() == "functionExist") {
            if (getName() == "plus") {
                llvm::Value *L = parameters[0]->codegen();
                llvm::Value *R = parameters[1]->codegen();
                if (L->getType()->isIntegerTy(32) && R->getType()->isIntegerTy(32)) {
                    return Builder.CreateAdd(L, R, "addtmp");
                }
                if (L->getType()->isDoubleTy() && R->getType()->isDoubleTy()) {
                    return Builder.CreateFAdd(L, R, "addtmp");
                }
                std::cout << "not integer or real arguments";
                exit(0);
            }
            if (getName() == "minus") {
                llvm::Value *L = parameters[0]->codegen();
                llvm::Value *R = parameters[1]->codegen();
                if (L->getType()->isIntegerTy(32) && R->getType()->isIntegerTy(32)) {
                    return Builder.CreateSub(L, R, "subtmp");
                }
                if (L->getType()->isDoubleTy() && R->getType()->isDoubleTy()) {
                    return Builder.CreateFSub(L, R, "subtmp");
                }
                std::cout << "not integer or real arguments";
                exit(0);
            }
            if (getName() == "times") {
                llvm::Value *L = parameters[0]->codegen();
                llvm::Value *R = parameters[1]->codegen();
                if (L->getType()->isIntegerTy(32) && R->getType()->isIntegerTy(32)) {
                    return Builder.CreateMul(L, R, "addmul");
                }
                if (L->getType()->isDoubleTy() && R->getType()->isDoubleTy()) {
                    return Builder.CreateFMul(L, R, "addmul");
                }
                std::cout << "not integer or real arguments";
                exit(0);
            }
            if (getName() == "divide") {
                llvm::Value *L = parameters[0]->codegen();
                llvm::Value *R = parameters[1]->codegen();
                if (L->getType()->isIntegerTy(32) && R->getType()->isIntegerTy(32)) {
                    return Builder.CreateUDiv(L, R, "adddiv");
                }
                if (L->getType()->isDoubleTy() && R->getType()->isDoubleTy()) {
                    return Builder.CreateFDiv(L, R, "adddiv");
                }
                std::cout << "not integer or real arguments";
                exit(0);
            }
            if (getName() == "or") {
                llvm::Value *L = parameters[0]->codegen();
                llvm::Value *R = parameters[1]->codegen();
                if (!L->getType()->isIntegerTy(1) || !R->getType()->isIntegerTy(1)) {
                    std::cout << "not boolean arguments";
                    exit(0);
                }
                return Builder.CreateOr(L, R, "ortmp");
            }
            if (getName() == "and") {
                llvm::Value *L = parameters[0]->codegen();
                llvm::Value *R = parameters[1]->codegen();
                if (!L->getType()->isIntegerTy(1) || !R->getType()->isIntegerTy(1)) {
                    std::cout << "not boolean arguments";
                    exit(0);
                }
                return Builder.CreateAnd(L, R, "andtmp");
            }
            if (getName() == "xor") {
                llvm::Value *L = parameters[0]->codegen();
                llvm::Value *R = parameters[1]->codegen();
                if (!L->getType()->isIntegerTy(1) || !R->getType()->isIntegerTy(1)) {
                    std::cout << "not boolean arguments";
                    exit(0);
                }
                return Builder.CreateXor(L, R, "xortmp");
            }
            if (getName() == "not") {
                llvm::Value *V = parameters[0]->codegen();
                if (!V->getType()->isIntegerTy(1)) {
                    std::cout << "not boolean arguments";
                    exit(0);
                }
                return Builder.CreateNot(V, "nottmp");
            }
            if (getName() == "isint") {
                llvm::Value *V = parameters[0]->codegen();
                return llvm::ConstantInt::get(TheContext, llvm::APInt(1, (int)V->getType()->isIntegerTy(32)));
            }
            if (getName() == "isreal") {
                llvm::Value *V = parameters[0]->codegen();
                return llvm::ConstantInt::get(TheContext, llvm::APInt(1, (int)V->getType()->isDoubleTy()));
            }
            if (getName() == "isbool") {
                llvm::Value *V = parameters[0]->codegen();
                return llvm::ConstantInt::get(TheContext, llvm::APInt(1, (int)V->getType()->isIntegerTy(1)));
            }
            if (getName() == "isatom") {
                return llvm::ConstantInt::get(TheContext, llvm::APInt(1, (int)(parameters[0]->getDeclaration()->getType() == "variable")));
            }
            if (getName() == "islist") {
                llvm::Value *V = parameters[0]->codegen();
                return llvm::ConstantInt::get(TheContext, llvm::APInt(1, (int)V->getType()->isVectorTy()));
            }
            if (getName() == "head") {
                llvm::Value *vec = parameters[0]->codegen();
                return Builder.CreateExtractElement(vec, (uint64_t)0);
            }
            if (getName() == "tail") {
                llvm::Value *vec = parameters[0]->codegen();
                int size = parameters[0]->getListVal().size();
                return Builder.CreateExtractElement(vec, (uint64_t)size - 1);
            }
            if (getName() == "equal") {
                llvm::Value *L = parameters[0]->codegen();
                llvm::Value *R = parameters[1]->codegen();
                return Builder.CreateCmp(llvm::CmpInst::Predicate::ICMP_EQ, L, R);
            }
            if (getName() == "nonequal") {
                llvm::Value *L = parameters[0]->codegen();
                llvm::Value *R = parameters[1]->codegen();
                return Builder.CreateCmp(llvm::CmpInst::Predicate::ICMP_NE, L, R);
            }
            if (getName() == "less") {
                llvm::Value *L = parameters[0]->codegen();
                llvm::Value *R = parameters[1]->codegen();
                return Builder.CreateCmp(llvm::CmpInst::Predicate::ICMP_ULT, L, R);
            }
            if (getName() == "lesseq") {
                llvm::Value *L = parameters[0]->codegen();
                llvm::Value *R = parameters[1]->codegen();
                return Builder.CreateCmp(llvm::CmpInst::Predicate::ICMP_ULE, L, R);
            }
            if (getName() == "greater") {
                llvm::Value *L = parameters[0]->codegen();
                llvm::Value *R = parameters[1]->codegen();
                return Builder.CreateCmp(llvm::CmpInst::Predicate::ICMP_UGT, L, R);
            }
            if (getName() == "greatereq") {
                llvm::Value *L = parameters[0]->codegen();
                llvm::Value *R = parameters[1]->codegen();
                return Builder.CreateCmp(llvm::CmpInst::Predicate::ICMP_UGE, L, R);
            }

        }
        if (getDeclaration()->getType() == "functionNew") {
            if (getParameters().size() != getDeclaration()->getParameters().size()) {
                std::cout << "not valid parameters\n";
                exit(0);
            }

            for (int i = 0; i < getParameters().size(); i++) {
                getDeclaration()->getParameters()[i]->getDeclaration()->setExpression(getParameters()[i]);
            }

            return getDeclaration()->getExpression()->codegen();
        }
    }
};

#endif //COMPILER_NODEINVOCATION_H
