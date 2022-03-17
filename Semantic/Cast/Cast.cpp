#include <SyntaxAnalyzer/Nodes/rootNode.h>
#include <Semantic/Cast/Cast.h>
#include <Semantic/Context/GlobalContext.h>
#include <Semantic/Context/FuncContext.h>

void CastNode(Node* node, GlobalContext* context) {

    //std::cerr << node->getName() << '\n';

    if (node->nodeType == "literal" && node->getName() == "list") {
        for (auto val: node->getListVal()) {
            CastNode(val, context);
        }
    }
    if (node->nodeType == "Invocation") {
        //std::cerr << node->name() << ':' << node->nodeType << "  " << context->;
        node->setDeclaration(context->getDefinition(node->getName()));
        for (auto parameter: node->getParameters()) {
            CastNode(parameter, context);
        }
    }
    if (node->nodeType == "Declaration") {
        context->addDefinition(node->getName(), node);
        FuncContext *funcContext = new FuncContext(*context);
        for (auto parameter: node->getParameters()) {
            funcContext->addParameter(parameter->getName(), parameter->getDeclaration());
        }
        CastNode(node->getExpression(), funcContext);
    }
    
}

void CastRoot(RootNode* root) {
    GlobalContext context = GlobalContext();
    for (auto node: root->nodes) {
        CastNode(node, &context);
    }
}