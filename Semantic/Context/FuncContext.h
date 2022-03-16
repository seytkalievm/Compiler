#include <map>
#include <string>
#include <iostream>
#include <SyntaxAnalyzer/Nodes/node.h>
#include <Semantic/Context/GlobalContext.h>

#ifndef COMPILER_FUNCCONTEXT_H
#define COMPILER_FUNCCONTEXT_H

class FuncContext: public GlobalContext{
public:
    std::map <std::string, Node*> mapParameters;

    FuncContext() {}

    FuncContext(const GlobalContext& cp): GlobalContext(cp) {}

    bool isDefinedParameter(std::string name) {
        return mapParameters.count(name) != 0;
    }

    virtual Node* getDefinition(std::string name) {
        if (!isDefinedParameter(name) && !isDefined(name)) {
            std::cout << name << " not exist\n";
            exit(0);
        }

        if (isDefinedParameter(name)) {
            return mapParameters[name];
        }

        return mapDeclared[name];
    }
    void addParameter(std::string name, Node* def) {
        if (isDefinedParameter(name)) {
            std::cout << name << " already exist\n";
            exit(0);
        }
        mapParameters[name] = def;
    }
};

#endif