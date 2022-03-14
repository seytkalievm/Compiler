#include <SyntaxAnalyzer/Parsers/ElementParser.h>
#include <SyntaxAnalyzer/Parser.h>

#ifndef COMPILER_CONDPARSER_H
#define COMPILER_CONDPARSER_H

Node* CondParser(Parser *parser, int *tokenNumber) {
    NodeInvocation *cond_node = new NodeInvocation();
    (*tokenNumber) ++;
    cond_node->setName("cond");
    cond_node->addParameter(ElementParser(parser, tokenNumber));
    cond_node->addParameter(ElementParser(parser, tokenNumber));

    if (parser->GetToken(*tokenNumber).code != tokOpenBracket) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position);
    }
    (*tokenNumber) ++;

    cond_node->addParameter(ElementParser(parser, tokenNumber));

    if (parser->GetToken(*tokenNumber).code != tokCloseBracket) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position);
    }
    (*tokenNumber) ++;

    return cond_node;
}

#endif //COMPILER_CONDPARSER_H
