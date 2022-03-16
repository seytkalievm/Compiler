#include <map>
#include <string>
#include <iostream>
#include <SyntaxAnalyzer/Nodes/node.h>
#include <SyntaxAnalyzer/Nodes/nodeDeclaration.h>
#include <SyntaxAnalyzer/Nodes/NodeParameter.h>
#include <SyntaxAnalyzer/Nodes/NodeLiteral.h>

#ifndef COMPILER_GLOBALCONTEXT_H
#define COMPILER_GLOBALCONTEXT_H

class GlobalContext{
public:
    std::map <std::string, Node*> mapDeclared;

    Node* createQuote() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("quote");
        node->setType("functionExist");
        NodeParameter *element = new NodeParameter();
        element->setName("element");
        node->addParameter(element);
        return node;
    }

    Node* createSetq() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("setq");
        node->setType("functionExist");
        NodeParameter *atom = new NodeParameter();
        atom->setName("atom");
        NodeParameter *element = new NodeParameter();
        element->setName("element");
        node->addParameter(atom);
        node->addParameter(element);
        return node;
    }

    Node* createFunc() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("func");
        node->setType("functionExist");
        NodeParameter *atom = new NodeParameter();
        atom->setName("atom");
        NodeLiteral *list = new NodeLiteral();
        list->setName("list");
        NodeParameter *element = new NodeParameter();
        element->setName("element");
        node->addParameter(atom);
        node->addParameter(list);
        node->addParameter(element);
        return node;
    }

    Node* createLambda() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("lambda");
        node->setType("functionExist");
        NodeLiteral *list = new NodeLiteral();
        list->setName("list");
        NodeParameter *element = new NodeParameter();
        element->setName("element");
        node->addParameter(list);
        node->addParameter(element);
        return node;
    }
    
    Node* createProg() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("prog");
        node->setType("functionExist");
        NodeLiteral *list = new NodeLiteral();
        list->setName("list");
        NodeParameter *element = new NodeParameter();
        element->setName("element");
        node->addParameter(list);
        node->addParameter(element);
        return node;
    }

    Node* createCond() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("cond");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        NodeParameter *element2 = new NodeParameter();
        element2->setName("element2");
        NodeParameter *element3 = new NodeParameter();
        element3->setName("element3");
        node->addParameter(element1);
        node->addParameter(element2);
        node->addParameter(element3);
        return node;
    }

    Node* createWhile() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("while");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        NodeParameter *element2 = new NodeParameter();
        element2->setName("element2");
        node->addParameter(element1);
        node->addParameter(element2);
        return node;
    }

    Node* createReturn() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("return");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        node->addParameter(element1);
        return node;
    }

    Node* createBreak() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("break");
        node->setType("functionExist");
        return node;
    }

    Node* createPlus() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("plus");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        NodeParameter *element2 = new NodeParameter();
        element2->setName("element2");
        node->addParameter(element1);
        node->addParameter(element2);
        return node;
    }
    
    Node* createMinus() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("minus");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        NodeParameter *element2 = new NodeParameter();
        element2->setName("element2");
        node->addParameter(element1);
        node->addParameter(element2);
        return node;
    }

    Node* createTimes() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("times");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        NodeParameter *element2 = new NodeParameter();
        element2->setName("element2");
        node->addParameter(element1);
        node->addParameter(element2);
        return node;
    }

    Node* createDivide() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("divide");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        NodeParameter *element2 = new NodeParameter();
        element2->setName("element2");
        node->addParameter(element1);
        node->addParameter(element2);
        return node;
    }
    
    Node* createCons() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("cons");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        NodeParameter *element2 = new NodeParameter();
        element2->setName("element2");
        node->addParameter(element1);
        node->addParameter(element2);
        return node;
    }

    Node* createHead() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("head");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        node->addParameter(element1);
        return node;
    }

    Node* createTail() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("tail");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        node->addParameter(element1);
        return node;
    }

    Node* createEqual() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("equal");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        NodeParameter *element2 = new NodeParameter();
        element2->setName("element2");
        node->addParameter(element1);
        node->addParameter(element2);
        return node;
    }

    Node* createNonEqual() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("nonequal");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        NodeParameter *element2 = new NodeParameter();
        element2->setName("element2");
        node->addParameter(element1);
        node->addParameter(element2);
        return node;
    }

    Node* createLess() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("less");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        NodeParameter *element2 = new NodeParameter();
        element2->setName("element2");
        node->addParameter(element1);
        node->addParameter(element2);
        return node;
    }

    Node* createLessEq() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("lesseq");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        NodeParameter *element2 = new NodeParameter();
        element2->setName("element2");
        node->addParameter(element1);
        node->addParameter(element2);
        return node;
    }

    Node* createGreater() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("greater");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        NodeParameter *element2 = new NodeParameter();
        element2->setName("element2");
        node->addParameter(element1);
        node->addParameter(element2);
        return node;
    }

    Node* createGreaterEq() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("greatereq");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        NodeParameter *element2 = new NodeParameter();
        element2->setName("element2");
        node->addParameter(element1);
        node->addParameter(element2);
        return node;
    }

    Node* createIsInt() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("isint");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        node->addParameter(element1);
        return node;
    }

    Node* createIsReal() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("isreal");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        node->addParameter(element1);
        return node;
    }

    Node* createIsBool() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("isbool");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        node->addParameter(element1);
        return node;
    }

    Node* createIsNull() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("isnull");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        node->addParameter(element1);
        return node;
    }

    Node* createIsAtom() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("isatom");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        node->addParameter(element1);
        return node;
    }

    Node* createIsList() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("islist");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        node->addParameter(element1);
        return node;
    }

    Node* createAnd() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("and");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        NodeParameter *element2 = new NodeParameter();
        element2->setName("element2");
        node->addParameter(element1);
        node->addParameter(element2);
        return node;
    }

    Node* createOr() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("or");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        NodeParameter *element2 = new NodeParameter();
        element2->setName("element2");
        node->addParameter(element1);
        node->addParameter(element2);
        return node;
    }

    Node* createXor() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("xor");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        NodeParameter *element2 = new NodeParameter();
        element2->setName("element2");
        node->addParameter(element1);
        node->addParameter(element2);
        return node;
    }

    Node* createNot() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("not");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        node->addParameter(element1);
        return node;
    }

    Node* createEval() {
        NodeDeclaration *node = new NodeDeclaration();
        node->setName("eval");
        node->setType("functionExist");
        NodeParameter *element1 = new NodeParameter();
        element1->setName("element1");
        node->addParameter(element1);
        return node;
    }

    GlobalContext() {
        addDefinition("quote", createQuote());
        addDefinition("setq", createSetq());
        addDefinition("func", createFunc());
        addDefinition("lambda", createLambda());
        addDefinition("prog", createProg());
        addDefinition("cond", createCond());
        addDefinition("while", createWhile());
        addDefinition("return", createReturn());
        addDefinition("break", createBreak());

        addDefinition("plus", createPlus());
        addDefinition("minus", createMinus());
        addDefinition("times", createTimes());
        addDefinition("divide", createDivide());

        addDefinition("head", createHead());
        addDefinition("tail", createTail());
        addDefinition("cons", createCons());

        addDefinition("equal", createEqual());
        addDefinition("nonequal", createNonEqual());
        addDefinition("less", createLess());
        addDefinition("lesseq", createLessEq());
        addDefinition("greater", createGreater());
        addDefinition("greatereq", createGreaterEq());

        addDefinition("isint", createIsInt());
        addDefinition("isreal", createIsReal());
        addDefinition("isbool", createIsBool());
        addDefinition("isnull", createIsNull());
        addDefinition("isatom", createIsAtom());
        addDefinition("islist", createIsList());

        addDefinition("and", createAnd());
        addDefinition("or", createOr());
        addDefinition("xor", createXor());
        addDefinition("not", createNot());

        addDefinition("eval", createEval());
    }
    
    GlobalContext(const GlobalContext& cp) {
        mapDeclared = cp.mapDeclared;
    }

    bool isDefined(std::string name) {
        return mapDeclared.count(name) != 0;
    }
    virtual Node* getDefinition(std::string name) {
        if (!isDefined(name)) {
            std::cout << name << " not exist\n";
            exit(0);
        }
        return mapDeclared[name];
    }
    void addDefinition(std::string name, Node* def) {
        if (isDefined(name)) {
            std::cout << name << " already exist\n";
            exit(0);
        }
        mapDeclared[name] = def;
    }
};

#endif