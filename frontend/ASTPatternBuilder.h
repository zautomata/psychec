// Copyright (c) 2008 Roberto Raggi <roberto.raggi@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef CFE_AST_PATTERN_BUILDER_H
#define CFE_AST_PATTERN_BUILDER_H

#include "FrontendConfig.h"
#include "AST.h"
#include "MemoryPool.h"

namespace psyche {

class CFE_API ASTPatternBuilder
{
    MemoryPool pool;

public:
    ASTPatternBuilder() {}

    void reset() { pool.reset(); }

    ObjCSelectorArgumentAST *ObjCSelectorArgument()
    {
        ObjCSelectorArgumentAST *ast = new (&pool) ObjCSelectorArgumentAST;
        return ast;
    }

    ObjCSelectorAST *ObjCSelector(ObjCSelectorArgumentListAST *selector_argument_list = 0)
    {
        ObjCSelectorAST *ast = new (&pool) ObjCSelectorAST;
        ast->selector_argument_list = selector_argument_list;
        return ast;
    }

    SimpleSpecifierAST *SimpleSpecifier()
    {
        SimpleSpecifierAST *ast = new (&pool) SimpleSpecifierAST;
        return ast;
    }

    AlignmentSpecifierAST *AlignmentSpecifier(ExpressionAST *typeIdExprOrAlignmentExpr = 0)
    {
        AlignmentSpecifierAST *ast = new (&pool) AlignmentSpecifierAST;
        ast->typeIdExprOrAlignmentExpr = typeIdExprOrAlignmentExpr;
        return ast;
    }

    GnuAttributeSpecifierAST *GnuAttributeSpecifier(GnuAttributeListAST *attribute_list = 0)
    {
        GnuAttributeSpecifierAST *ast = new (&pool) GnuAttributeSpecifierAST;
        ast->attribute_list = attribute_list;
        return ast;
    }

    GnuAttributeAST *GnuAttribute(ExpressionListAST *expression_list = 0)
    {
        GnuAttributeAST *ast = new (&pool) GnuAttributeAST;
        ast->expression_list = expression_list;
        return ast;
    }

    TypeofSpecifierAST *TypeofSpecifier(ExpressionAST *expression = 0)
    {
        TypeofSpecifierAST *ast = new (&pool) TypeofSpecifierAST;
        ast->expression = expression;
        return ast;
    }

    DecltypeSpecifierAST *DecltypeSpecifier(ExpressionAST *expression = 0)
    {
        DecltypeSpecifierAST *ast = new (&pool) DecltypeSpecifierAST;
        ast->expression = expression;
        return ast;
    }

    DeclaratorAST *Declarator(SpecifierListAST *attribute_list = 0, PtrOperatorListAST *ptr_operator_list = 0, CoreDeclaratorAST *core_declarator = 0, PostfixDeclaratorListAST *postfix_declarator_list = 0, SpecifierListAST *post_attribute_list = 0, ExpressionAST *initializer = 0)
    {
        DeclaratorAST *ast = new (&pool) DeclaratorAST;
        ast->attribute_list = attribute_list;
        ast->ptr_operator_list = ptr_operator_list;
        ast->core_declarator = core_declarator;
        ast->postfix_declarator_list = postfix_declarator_list;
        ast->post_attribute_list = post_attribute_list;
        ast->initializer = initializer;
        return ast;
    }

    SimpleDeclarationAST *SimpleDeclaration(SpecifierListAST *decl_specifier_list = 0, DeclaratorListAST *declarator_list = 0)
    {
        SimpleDeclarationAST *ast = new (&pool) SimpleDeclarationAST;
        ast->decl_specifier_list = decl_specifier_list;
        ast->declarator_list = declarator_list;
        return ast;
    }

    EmptyDeclarationAST *EmptyDeclaration()
    {
        EmptyDeclarationAST *ast = new (&pool) EmptyDeclarationAST;
        return ast;
    }

    AccessDeclarationAST *AccessDeclaration()
    {
        AccessDeclarationAST *ast = new (&pool) AccessDeclarationAST;
        return ast;
    }

    QtObjectTagAST *QtObjectTag()
    {
        QtObjectTagAST *ast = new (&pool) QtObjectTagAST;
        return ast;
    }

    QtPrivateSlotAST *QtPrivateSlot(SpecifierListAST *type_specifier_list = 0, DeclaratorAST *declarator = 0)
    {
        QtPrivateSlotAST *ast = new (&pool) QtPrivateSlotAST;
        ast->type_specifier_list = type_specifier_list;
        ast->declarator = declarator;
        return ast;
    }

    QtPropertyDeclarationItemAST *QtPropertyDeclarationItem(ExpressionAST *expression = 0)
    {
        QtPropertyDeclarationItemAST *ast = new (&pool) QtPropertyDeclarationItemAST;
        ast->expression = expression;
        return ast;
    }

    QtPropertyDeclarationAST *QtPropertyDeclaration(ExpressionAST *expression = 0, ExpressionAST *type_id = 0, NameAST *property_name = 0, QtPropertyDeclarationItemListAST *property_declaration_item_list = 0)
    {
        QtPropertyDeclarationAST *ast = new (&pool) QtPropertyDeclarationAST;
        ast->expression = expression;
        ast->type_id = type_id;
        ast->property_name = property_name;
        ast->property_declaration_item_list = property_declaration_item_list;
        return ast;
    }

    QtEnumDeclarationAST *QtEnumDeclaration(NameListAST *enumerator_list = 0)
    {
        QtEnumDeclarationAST *ast = new (&pool) QtEnumDeclarationAST;
        ast->enumerator_list = enumerator_list;
        return ast;
    }

    QtFlagsDeclarationAST *QtFlagsDeclaration(NameListAST *flag_enums_list = 0)
    {
        QtFlagsDeclarationAST *ast = new (&pool) QtFlagsDeclarationAST;
        ast->flag_enums_list = flag_enums_list;
        return ast;
    }

    QtInterfaceNameAST *QtInterfaceName(NameAST *interface_name = 0, NameListAST *constraint_list = 0)
    {
        QtInterfaceNameAST *ast = new (&pool) QtInterfaceNameAST;
        ast->interface_name = interface_name;
        ast->constraint_list = constraint_list;
        return ast;
    }

    QtInterfacesDeclarationAST *QtInterfacesDeclaration(QtInterfaceNameListAST *interface_name_list = 0)
    {
        QtInterfacesDeclarationAST *ast = new (&pool) QtInterfacesDeclarationAST;
        ast->interface_name_list = interface_name_list;
        return ast;
    }

    AsmDefinitionAST *AsmDefinition()
    {
        AsmDefinitionAST *ast = new (&pool) AsmDefinitionAST;
        return ast;
    }

    BaseSpecifierAST *BaseSpecifier(NameAST *name = 0)
    {
        BaseSpecifierAST *ast = new (&pool) BaseSpecifierAST;
        ast->name = name;
        return ast;
    }

    IdExpressionAST *IdExpression(NameAST *name = 0)
    {
        IdExpressionAST *ast = new (&pool) IdExpressionAST;
        ast->name = name;
        return ast;
    }

    CompoundExpressionAST *CompoundExpression(CompoundStatementAST *statement = 0)
    {
        CompoundExpressionAST *ast = new (&pool) CompoundExpressionAST;
        ast->statement = statement;
        return ast;
    }

    CompoundLiteralAST *CompoundLiteral(ExpressionAST *type_id = 0, ExpressionAST *initializer = 0)
    {
        CompoundLiteralAST *ast = new (&pool) CompoundLiteralAST;
        ast->type_id = type_id;
        ast->initializer = initializer;
        return ast;
    }

    QtMethodAST *QtMethod(DeclaratorAST *declarator = 0)
    {
        QtMethodAST *ast = new (&pool) QtMethodAST;
        ast->declarator = declarator;
        return ast;
    }

    QtMemberDeclarationAST *QtMemberDeclaration(ExpressionAST *type_id = 0)
    {
        QtMemberDeclarationAST *ast = new (&pool) QtMemberDeclarationAST;
        ast->type_id = type_id;
        return ast;
    }

    BinaryExpressionAST *BinaryExpression(ExpressionAST *left_expression = 0, ExpressionAST *right_expression = 0)
    {
        BinaryExpressionAST *ast = new (&pool) BinaryExpressionAST;
        ast->left_expression = left_expression;
        ast->right_expression = right_expression;
        return ast;
    }

    CastExpressionAST *CastExpression(ExpressionAST *type_id = 0, ExpressionAST *expression = 0)
    {
        CastExpressionAST *ast = new (&pool) CastExpressionAST;
        ast->type_id = type_id;
        ast->expression = expression;
        return ast;
    }

    ClassSpecifierAST *ClassSpecifier(SpecifierListAST *attribute_list = 0, NameAST *name = 0, BaseSpecifierListAST *base_clause_list = 0, DeclarationListAST *member_specifier_list = 0)
    {
        ClassSpecifierAST *ast = new (&pool) ClassSpecifierAST;
        ast->attribute_list = attribute_list;
        ast->name = name;
        ast->base_clause_list = base_clause_list;
        ast->member_specifier_list = member_specifier_list;
        return ast;
    }

    CaseStatementAST *CaseStatement(ExpressionAST *expression = 0, StatementAST *statement = 0)
    {
        CaseStatementAST *ast = new (&pool) CaseStatementAST;
        ast->expression = expression;
        ast->statement = statement;
        return ast;
    }

    CompoundStatementAST *CompoundStatement(StatementListAST *statement_list = 0)
    {
        CompoundStatementAST *ast = new (&pool) CompoundStatementAST;
        ast->statement_list = statement_list;
        return ast;
    }

    ConditionAST *Condition(SpecifierListAST *type_specifier_list = 0, DeclaratorAST *declarator = 0)
    {
        ConditionAST *ast = new (&pool) ConditionAST;
        ast->type_specifier_list = type_specifier_list;
        ast->declarator = declarator;
        return ast;
    }

    ConditionalExpressionAST *ConditionalExpression(ExpressionAST *condition = 0, ExpressionAST *left_expression = 0, ExpressionAST *right_expression = 0)
    {
        ConditionalExpressionAST *ast = new (&pool) ConditionalExpressionAST;
        ast->condition = condition;
        ast->left_expression = left_expression;
        ast->right_expression = right_expression;
        return ast;
    }

    CppCastExpressionAST *CppCastExpression(ExpressionAST *type_id = 0, ExpressionAST *expression = 0)
    {
        CppCastExpressionAST *ast = new (&pool) CppCastExpressionAST;
        ast->type_id = type_id;
        ast->expression = expression;
        return ast;
    }

    CtorInitializerAST *CtorInitializer(MemInitializerListAST *member_initializer_list = 0)
    {
        CtorInitializerAST *ast = new (&pool) CtorInitializerAST;
        ast->member_initializer_list = member_initializer_list;
        return ast;
    }

    DeclarationStatementAST *DeclarationStatement(DeclarationAST *declaration = 0)
    {
        DeclarationStatementAST *ast = new (&pool) DeclarationStatementAST;
        ast->declaration = declaration;
        return ast;
    }

    DeclaratorIdAST *DeclaratorId(NameAST *name = 0)
    {
        DeclaratorIdAST *ast = new (&pool) DeclaratorIdAST;
        ast->name = name;
        return ast;
    }

    NestedDeclaratorAST *NestedDeclarator(DeclaratorAST *declarator = 0)
    {
        NestedDeclaratorAST *ast = new (&pool) NestedDeclaratorAST;
        ast->declarator = declarator;
        return ast;
    }

    FunctionDeclaratorAST *FunctionDeclarator(ParameterDeclarationClauseAST *parameter_declaration_clause = 0, SpecifierListAST *cv_qualifier_list = 0, ExceptionSpecificationAST *exception_specification = 0, TrailingReturnTypeAST *trailing_return_type = 0, ExpressionAST *as_cpp_initializer = 0)
    {
        FunctionDeclaratorAST *ast = new (&pool) FunctionDeclaratorAST;
        ast->parameter_declaration_clause = parameter_declaration_clause;
        ast->cv_qualifier_list = cv_qualifier_list;
        ast->exception_specification = exception_specification;
        ast->trailing_return_type = trailing_return_type;
        ast->as_cpp_initializer = as_cpp_initializer;
        return ast;
    }

    ArrayDeclaratorAST *ArrayDeclarator(ExpressionAST *expression = 0)
    {
        ArrayDeclaratorAST *ast = new (&pool) ArrayDeclaratorAST;
        ast->expression = expression;
        return ast;
    }

    DeleteExpressionAST *DeleteExpression(ExpressionAST *expression = 0)
    {
        DeleteExpressionAST *ast = new (&pool) DeleteExpressionAST;
        ast->expression = expression;
        return ast;
    }

    DoStatementAST *DoStatement(StatementAST *statement = 0, ExpressionAST *expression = 0)
    {
        DoStatementAST *ast = new (&pool) DoStatementAST;
        ast->statement = statement;
        ast->expression = expression;
        return ast;
    }

    NamedTypeSpecifierAST *NamedTypeSpecifier(NameAST *name = 0)
    {
        NamedTypeSpecifierAST *ast = new (&pool) NamedTypeSpecifierAST;
        ast->name = name;
        return ast;
    }

    ElaboratedTypeSpecifierAST *ElaboratedTypeSpecifier(SpecifierListAST *attribute_list = 0, NameAST *name = 0)
    {
        ElaboratedTypeSpecifierAST *ast = new (&pool) ElaboratedTypeSpecifierAST;
        ast->attribute_list = attribute_list;
        ast->name = name;
        return ast;
    }

    EnumSpecifierAST *EnumSpecifier(NameAST *name = 0, SpecifierListAST *type_specifier_list = 0, EnumeratorListAST *enumerator_list = 0)
    {
        EnumSpecifierAST *ast = new (&pool) EnumSpecifierAST;
        ast->name = name;
        ast->type_specifier_list = type_specifier_list;
        ast->enumerator_list = enumerator_list;
        return ast;
    }

    EnumeratorAST *Enumerator(ExpressionAST *expression = 0)
    {
        EnumeratorAST *ast = new (&pool) EnumeratorAST;
        ast->expression = expression;
        return ast;
    }

    ExceptionDeclarationAST *ExceptionDeclaration(SpecifierListAST *type_specifier_list = 0, DeclaratorAST *declarator = 0)
    {
        ExceptionDeclarationAST *ast = new (&pool) ExceptionDeclarationAST;
        ast->type_specifier_list = type_specifier_list;
        ast->declarator = declarator;
        return ast;
    }

    DynamicExceptionSpecificationAST *DynamicExceptionSpecification(ExpressionListAST *type_id_list = 0)
    {
        DynamicExceptionSpecificationAST *ast = new (&pool) DynamicExceptionSpecificationAST;
        ast->type_id_list = type_id_list;
        return ast;
    }

    NoExceptSpecificationAST *NoExceptSpecification(ExpressionAST *expression = 0)
    {
        NoExceptSpecificationAST *ast = new (&pool) NoExceptSpecificationAST;
        ast->expression = expression;
        return ast;
    }

    ExpressionOrDeclarationStatementAST *ExpressionOrDeclarationStatement(ExpressionStatementAST *expression = 0, DeclarationStatementAST *declaration = 0)
    {
        ExpressionOrDeclarationStatementAST *ast = new (&pool) ExpressionOrDeclarationStatementAST;
        ast->expression = expression;
        ast->declaration = declaration;
        return ast;
    }

    ExpressionStatementAST *ExpressionStatement(ExpressionAST *expression = 0)
    {
        ExpressionStatementAST *ast = new (&pool) ExpressionStatementAST;
        ast->expression = expression;
        return ast;
    }

    FunctionDefinitionAST *FunctionDefinition(SpecifierListAST *decl_specifier_list = 0, DeclaratorAST *declarator = 0, CtorInitializerAST *ctor_initializer = 0, StatementAST *function_body = 0)
    {
        FunctionDefinitionAST *ast = new (&pool) FunctionDefinitionAST;
        ast->decl_specifier_list = decl_specifier_list;
        ast->declarator = declarator;
        ast->ctor_initializer = ctor_initializer;
        ast->function_body = function_body;
        return ast;
    }

    ForeachStatementAST *ForeachStatement(SpecifierListAST *type_specifier_list = 0, DeclaratorAST *declarator = 0, ExpressionAST *initializer = 0, ExpressionAST *expression = 0, StatementAST *statement = 0)
    {
        ForeachStatementAST *ast = new (&pool) ForeachStatementAST;
        ast->type_specifier_list = type_specifier_list;
        ast->declarator = declarator;
        ast->initializer = initializer;
        ast->expression = expression;
        ast->statement = statement;
        return ast;
    }

    RangeBasedForStatementAST *RangeBasedForStatement(SpecifierListAST *type_specifier_list = 0, DeclaratorAST *declarator = 0, ExpressionAST *expression = 0, StatementAST *statement = 0)
    {
        RangeBasedForStatementAST *ast = new (&pool) RangeBasedForStatementAST;
        ast->type_specifier_list = type_specifier_list;
        ast->declarator = declarator;
        ast->expression = expression;
        ast->statement = statement;
        return ast;
    }

    ForStatementAST *ForStatement(StatementAST *initializer = 0, ExpressionAST *condition = 0, ExpressionAST *expression = 0, StatementAST *statement = 0)
    {
        ForStatementAST *ast = new (&pool) ForStatementAST;
        ast->initializer = initializer;
        ast->condition = condition;
        ast->expression = expression;
        ast->statement = statement;
        return ast;
    }

    IfStatementAST *IfStatement(ExpressionAST *condition = 0, StatementAST *statement = 0, StatementAST *else_statement = 0)
    {
        IfStatementAST *ast = new (&pool) IfStatementAST;
        ast->condition = condition;
        ast->statement = statement;
        ast->else_statement = else_statement;
        return ast;
    }

    ArrayInitializerAST *ArrayInitializer(ExpressionListAST *expression_list = 0)
    {
        ArrayInitializerAST *ast = new (&pool) ArrayInitializerAST;
        ast->expression_list = expression_list;
        return ast;
    }

    LabeledStatementAST *LabeledStatement(StatementAST *statement = 0)
    {
        LabeledStatementAST *ast = new (&pool) LabeledStatementAST;
        ast->statement = statement;
        return ast;
    }

    LinkageBodyAST *LinkageBody(DeclarationListAST *declaration_list = 0)
    {
        LinkageBodyAST *ast = new (&pool) LinkageBodyAST;
        ast->declaration_list = declaration_list;
        return ast;
    }

    LinkageSpecificationAST *LinkageSpecification(DeclarationAST *declaration = 0)
    {
        LinkageSpecificationAST *ast = new (&pool) LinkageSpecificationAST;
        ast->declaration = declaration;
        return ast;
    }

    MemInitializerAST *MemInitializer(NameAST *name = 0, ExpressionAST *expression = 0)
    {
        MemInitializerAST *ast = new (&pool) MemInitializerAST;
        ast->name = name;
        ast->expression = expression;
        return ast;
    }

    NestedNameSpecifierAST *NestedNameSpecifier(NameAST *class_or_namespace_name = 0)
    {
        NestedNameSpecifierAST *ast = new (&pool) NestedNameSpecifierAST;
        ast->class_or_namespace_name = class_or_namespace_name;
        return ast;
    }

    QualifiedNameAST *QualifiedName(NestedNameSpecifierListAST *nested_name_specifier_list = 0, NameAST *unqualified_name = 0)
    {
        QualifiedNameAST *ast = new (&pool) QualifiedNameAST;
        ast->nested_name_specifier_list = nested_name_specifier_list;
        ast->unqualified_name = unqualified_name;
        return ast;
    }

    OperatorFunctionIdAST *OperatorFunctionId(OperatorAST *op = 0)
    {
        OperatorFunctionIdAST *ast = new (&pool) OperatorFunctionIdAST;
        ast->op = op;
        return ast;
    }

    ConversionFunctionIdAST *ConversionFunctionId(SpecifierListAST *type_specifier_list = 0, PtrOperatorListAST *ptr_operator_list = 0)
    {
        ConversionFunctionIdAST *ast = new (&pool) ConversionFunctionIdAST;
        ast->type_specifier_list = type_specifier_list;
        ast->ptr_operator_list = ptr_operator_list;
        return ast;
    }

    AnonymousNameAST *AnonymousName()
    {
        AnonymousNameAST *ast = new (&pool) AnonymousNameAST;
        return ast;
    }

    SimpleNameAST *SimpleName()
    {
        SimpleNameAST *ast = new (&pool) SimpleNameAST;
        return ast;
    }

    DestructorNameAST *DestructorName(NameAST *unqualified_name = 0)
    {
        DestructorNameAST *ast = new (&pool) DestructorNameAST;
        ast->unqualified_name = unqualified_name;
        return ast;
    }

    TemplateIdAST *TemplateId(ExpressionListAST *template_argument_list = 0)
    {
        TemplateIdAST *ast = new (&pool) TemplateIdAST;
        ast->template_argument_list = template_argument_list;
        return ast;
    }

    NamespaceAST *Namespace(SpecifierListAST *attribute_list = 0, DeclarationAST *linkage_body = 0)
    {
        NamespaceAST *ast = new (&pool) NamespaceAST;
        ast->attribute_list = attribute_list;
        ast->linkage_body = linkage_body;
        return ast;
    }

    NamespaceAliasDefinitionAST *NamespaceAliasDefinition(NameAST *name = 0)
    {
        NamespaceAliasDefinitionAST *ast = new (&pool) NamespaceAliasDefinitionAST;
        ast->name = name;
        return ast;
    }

    AliasDeclarationAST *AliasDeclaration(NameAST *name = 0, TypeIdAST *typeId = 0)
    {
        AliasDeclarationAST *ast = new (&pool) AliasDeclarationAST;
        ast->name = name;
        ast->typeId = typeId;
        return ast;
    }

    ExpressionListParenAST *ExpressionListParen(ExpressionListAST *expression_list = 0)
    {
        ExpressionListParenAST *ast = new (&pool) ExpressionListParenAST;
        ast->expression_list = expression_list;
        return ast;
    }

    NewArrayDeclaratorAST *NewArrayDeclarator(ExpressionAST *expression = 0)
    {
        NewArrayDeclaratorAST *ast = new (&pool) NewArrayDeclaratorAST;
        ast->expression = expression;
        return ast;
    }

    NewExpressionAST *NewExpression(ExpressionListParenAST *new_placement = 0, ExpressionAST *type_id = 0, NewTypeIdAST *new_type_id = 0, ExpressionAST *new_initializer = 0)
    {
        NewExpressionAST *ast = new (&pool) NewExpressionAST;
        ast->new_placement = new_placement;
        ast->type_id = type_id;
        ast->new_type_id = new_type_id;
        ast->new_initializer = new_initializer;
        return ast;
    }

    NewTypeIdAST *NewTypeId(SpecifierListAST *type_specifier_list = 0, PtrOperatorListAST *ptr_operator_list = 0, NewArrayDeclaratorListAST *new_array_declarator_list = 0)
    {
        NewTypeIdAST *ast = new (&pool) NewTypeIdAST;
        ast->type_specifier_list = type_specifier_list;
        ast->ptr_operator_list = ptr_operator_list;
        ast->new_array_declarator_list = new_array_declarator_list;
        return ast;
    }

    OperatorAST *Operator()
    {
        OperatorAST *ast = new (&pool) OperatorAST;
        return ast;
    }

    ParameterDeclarationAST *ParameterDeclaration(SpecifierListAST *type_specifier_list = 0, DeclaratorAST *declarator = 0, ExpressionAST *expression = 0)
    {
        ParameterDeclarationAST *ast = new (&pool) ParameterDeclarationAST;
        ast->type_specifier_list = type_specifier_list;
        ast->declarator = declarator;
        ast->expression = expression;
        return ast;
    }

    ParameterDeclarationClauseAST *ParameterDeclarationClause(ParameterDeclarationListAST *parameter_declaration_list = 0)
    {
        ParameterDeclarationClauseAST *ast = new (&pool) ParameterDeclarationClauseAST;
        ast->parameter_declaration_list = parameter_declaration_list;
        return ast;
    }

    CallAST *Call(ExpressionAST *base_expression = 0, ExpressionListAST *expression_list = 0)
    {
        CallAST *ast = new (&pool) CallAST;
        ast->base_expression = base_expression;
        ast->expression_list = expression_list;
        return ast;
    }

    ArrayAccessAST *ArrayAccess(ExpressionAST *base_expression = 0, ExpressionAST *expression = 0)
    {
        ArrayAccessAST *ast = new (&pool) ArrayAccessAST;
        ast->base_expression = base_expression;
        ast->expression = expression;
        return ast;
    }

    PostIncrDecrAST *PostIncrDecr(ExpressionAST *base_expression = 0)
    {
        PostIncrDecrAST *ast = new (&pool) PostIncrDecrAST;
        ast->base_expression = base_expression;
        return ast;
    }

    MemberAccessAST *MemberAccess(ExpressionAST *base_expression = 0, NameAST *member_name = 0)
    {
        MemberAccessAST *ast = new (&pool) MemberAccessAST;
        ast->base_expression = base_expression;
        ast->member_name = member_name;
        return ast;
    }

    TypeidExpressionAST *TypeidExpression(ExpressionAST *expression = 0)
    {
        TypeidExpressionAST *ast = new (&pool) TypeidExpressionAST;
        ast->expression = expression;
        return ast;
    }

    TypenameCallExpressionAST *TypenameCallExpression(NameAST *name = 0, ExpressionAST *expression = 0)
    {
        TypenameCallExpressionAST *ast = new (&pool) TypenameCallExpressionAST;
        ast->name = name;
        ast->expression = expression;
        return ast;
    }

    TypeConstructorCallAST *TypeConstructorCall(SpecifierListAST *type_specifier_list = 0, ExpressionAST *expression = 0)
    {
        TypeConstructorCallAST *ast = new (&pool) TypeConstructorCallAST;
        ast->type_specifier_list = type_specifier_list;
        ast->expression = expression;
        return ast;
    }

    PointerToMemberAST *PointerToMember(NestedNameSpecifierListAST *nested_name_specifier_list = 0, SpecifierListAST *cv_qualifier_list = 0)
    {
        PointerToMemberAST *ast = new (&pool) PointerToMemberAST;
        ast->nested_name_specifier_list = nested_name_specifier_list;
        ast->cv_qualifier_list = cv_qualifier_list;
        return ast;
    }

    PointerAST *Pointer(SpecifierListAST *cv_qualifier_list = 0)
    {
        PointerAST *ast = new (&pool) PointerAST;
        ast->cv_qualifier_list = cv_qualifier_list;
        return ast;
    }

    ReferenceAST *Reference()
    {
        ReferenceAST *ast = new (&pool) ReferenceAST;
        return ast;
    }

    BreakStatementAST *BreakStatement()
    {
        BreakStatementAST *ast = new (&pool) BreakStatementAST;
        return ast;
    }

    ContinueStatementAST *ContinueStatement()
    {
        ContinueStatementAST *ast = new (&pool) ContinueStatementAST;
        return ast;
    }

    GotoStatementAST *GotoStatement()
    {
        GotoStatementAST *ast = new (&pool) GotoStatementAST;
        return ast;
    }

    ReturnStatementAST *ReturnStatement(ExpressionAST *expression = 0)
    {
        ReturnStatementAST *ast = new (&pool) ReturnStatementAST;
        ast->expression = expression;
        return ast;
    }

    SizeofExpressionAST *SizeofExpression(ExpressionAST *expression = 0)
    {
        SizeofExpressionAST *ast = new (&pool) SizeofExpressionAST;
        ast->expression = expression;
        return ast;
    }

    AlignofExpressionAST *AlignofExpression(TypeIdAST *typeId = 0)
    {
        AlignofExpressionAST *ast = new (&pool) AlignofExpressionAST;
        ast->typeId = typeId;
        return ast;
    }

    PointerLiteralAST *PointerLiteral()
    {
        PointerLiteralAST *ast = new (&pool) PointerLiteralAST;
        return ast;
    }

    NumericLiteralAST *NumericLiteral()
    {
        NumericLiteralAST *ast = new (&pool) NumericLiteralAST;
        return ast;
    }

    BoolLiteralAST *BoolLiteral()
    {
        BoolLiteralAST *ast = new (&pool) BoolLiteralAST;
        return ast;
    }

    ThisExpressionAST *ThisExpression()
    {
        ThisExpressionAST *ast = new (&pool) ThisExpressionAST;
        return ast;
    }

    NestedExpressionAST *NestedExpression(ExpressionAST *expression = 0)
    {
        NestedExpressionAST *ast = new (&pool) NestedExpressionAST;
        ast->expression = expression;
        return ast;
    }

    StaticAssertDeclarationAST *StaticAssertDeclaration(ExpressionAST *expression = 0, ExpressionAST *string_literal = 0)
    {
        StaticAssertDeclarationAST *ast = new (&pool) StaticAssertDeclarationAST;
        ast->expression = expression;
        ast->string_literal = string_literal;
        return ast;
    }

    StringLiteralAST *StringLiteral(StringLiteralAST *next = 0)
    {
        StringLiteralAST *ast = new (&pool) StringLiteralAST;
        ast->next = next;
        return ast;
    }

    SwitchStatementAST *SwitchStatement(ExpressionAST *condition = 0, StatementAST *statement = 0)
    {
        SwitchStatementAST *ast = new (&pool) SwitchStatementAST;
        ast->condition = condition;
        ast->statement = statement;
        return ast;
    }

    TemplateDeclarationAST *TemplateDeclaration(DeclarationListAST *template_parameter_list = 0, DeclarationAST *declaration = 0)
    {
        TemplateDeclarationAST *ast = new (&pool) TemplateDeclarationAST;
        ast->template_parameter_list = template_parameter_list;
        ast->declaration = declaration;
        return ast;
    }

    ThrowExpressionAST *ThrowExpression(ExpressionAST *expression = 0)
    {
        ThrowExpressionAST *ast = new (&pool) ThrowExpressionAST;
        ast->expression = expression;
        return ast;
    }

    NoExceptOperatorExpressionAST *NoExceptOperatorExpression(ExpressionAST *expression = 0)
    {
        NoExceptOperatorExpressionAST *ast = new (&pool) NoExceptOperatorExpressionAST;
        ast->expression = expression;
        return ast;
    }

    TranslationUnitAST *TranslationUnit(DeclarationListAST *declaration_list = 0)
    {
        TranslationUnitAST *ast = new (&pool) TranslationUnitAST;
        ast->declaration_list = declaration_list;
        return ast;
    }

    TryBlockStatementAST *TryBlockStatement(StatementAST *statement = 0, CatchClauseListAST *catch_clause_list = 0)
    {
        TryBlockStatementAST *ast = new (&pool) TryBlockStatementAST;
        ast->statement = statement;
        ast->catch_clause_list = catch_clause_list;
        return ast;
    }

    CatchClauseAST *CatchClause(ExceptionDeclarationAST *exception_declaration = 0, StatementAST *statement = 0)
    {
        CatchClauseAST *ast = new (&pool) CatchClauseAST;
        ast->exception_declaration = exception_declaration;
        ast->statement = statement;
        return ast;
    }

    TypeIdAST *TypeId(SpecifierListAST *type_specifier_list = 0, DeclaratorAST *declarator = 0)
    {
        TypeIdAST *ast = new (&pool) TypeIdAST;
        ast->type_specifier_list = type_specifier_list;
        ast->declarator = declarator;
        return ast;
    }

    TypenameTypeParameterAST *TypenameTypeParameter(NameAST *name = 0, ExpressionAST *type_id = 0)
    {
        TypenameTypeParameterAST *ast = new (&pool) TypenameTypeParameterAST;
        ast->name = name;
        ast->type_id = type_id;
        return ast;
    }

    TemplateTypeParameterAST *TemplateTypeParameter(DeclarationListAST *template_parameter_list = 0, NameAST *name = 0, ExpressionAST *type_id = 0)
    {
        TemplateTypeParameterAST *ast = new (&pool) TemplateTypeParameterAST;
        ast->template_parameter_list = template_parameter_list;
        ast->name = name;
        ast->type_id = type_id;
        return ast;
    }

    UnaryExpressionAST *UnaryExpression(ExpressionAST *expression = 0)
    {
        UnaryExpressionAST *ast = new (&pool) UnaryExpressionAST;
        ast->expression = expression;
        return ast;
    }

    UsingAST *Using(NameAST *name = 0)
    {
        UsingAST *ast = new (&pool) UsingAST;
        ast->name = name;
        return ast;
    }

    UsingDirectiveAST *UsingDirective(NameAST *name = 0)
    {
        UsingDirectiveAST *ast = new (&pool) UsingDirectiveAST;
        ast->name = name;
        return ast;
    }

    WhileStatementAST *WhileStatement(ExpressionAST *condition = 0, StatementAST *statement = 0)
    {
        WhileStatementAST *ast = new (&pool) WhileStatementAST;
        ast->condition = condition;
        ast->statement = statement;
        return ast;
    }

    ObjCClassForwardDeclarationAST *ObjCClassForwardDeclaration(SpecifierListAST *attribute_list = 0, NameListAST *identifier_list = 0)
    {
        ObjCClassForwardDeclarationAST *ast = new (&pool) ObjCClassForwardDeclarationAST;
        ast->attribute_list = attribute_list;
        ast->identifier_list = identifier_list;
        return ast;
    }

    ObjCClassDeclarationAST *ObjCClassDeclaration(SpecifierListAST *attribute_list = 0, NameAST *class_name = 0, NameAST *category_name = 0, NameAST *superclass = 0, ObjCProtocolRefsAST *protocol_refs = 0, ObjCInstanceVariablesDeclarationAST *inst_vars_decl = 0, DeclarationListAST *member_declaration_list = 0)
    {
        ObjCClassDeclarationAST *ast = new (&pool) ObjCClassDeclarationAST;
        ast->attribute_list = attribute_list;
        ast->class_name = class_name;
        ast->category_name = category_name;
        ast->superclass = superclass;
        ast->protocol_refs = protocol_refs;
        ast->inst_vars_decl = inst_vars_decl;
        ast->member_declaration_list = member_declaration_list;
        return ast;
    }

    ObjCProtocolForwardDeclarationAST *ObjCProtocolForwardDeclaration(SpecifierListAST *attribute_list = 0, NameListAST *identifier_list = 0)
    {
        ObjCProtocolForwardDeclarationAST *ast = new (&pool) ObjCProtocolForwardDeclarationAST;
        ast->attribute_list = attribute_list;
        ast->identifier_list = identifier_list;
        return ast;
    }

    ObjCProtocolDeclarationAST *ObjCProtocolDeclaration(SpecifierListAST *attribute_list = 0, NameAST *name = 0, ObjCProtocolRefsAST *protocol_refs = 0, DeclarationListAST *member_declaration_list = 0)
    {
        ObjCProtocolDeclarationAST *ast = new (&pool) ObjCProtocolDeclarationAST;
        ast->attribute_list = attribute_list;
        ast->name = name;
        ast->protocol_refs = protocol_refs;
        ast->member_declaration_list = member_declaration_list;
        return ast;
    }

    ObjCProtocolRefsAST *ObjCProtocolRefs(NameListAST *identifier_list = 0)
    {
        ObjCProtocolRefsAST *ast = new (&pool) ObjCProtocolRefsAST;
        ast->identifier_list = identifier_list;
        return ast;
    }

    ObjCMessageArgumentAST *ObjCMessageArgument(ExpressionAST *parameter_value_expression = 0)
    {
        ObjCMessageArgumentAST *ast = new (&pool) ObjCMessageArgumentAST;
        ast->parameter_value_expression = parameter_value_expression;
        return ast;
    }

    ObjCMessageExpressionAST *ObjCMessageExpression(ExpressionAST *receiver_expression = 0, ObjCSelectorAST *selector = 0, ObjCMessageArgumentListAST *argument_list = 0)
    {
        ObjCMessageExpressionAST *ast = new (&pool) ObjCMessageExpressionAST;
        ast->receiver_expression = receiver_expression;
        ast->selector = selector;
        ast->argument_list = argument_list;
        return ast;
    }

    ObjCProtocolExpressionAST *ObjCProtocolExpression()
    {
        ObjCProtocolExpressionAST *ast = new (&pool) ObjCProtocolExpressionAST;
        return ast;
    }

    ObjCTypeNameAST *ObjCTypeName(ExpressionAST *type_id = 0)
    {
        ObjCTypeNameAST *ast = new (&pool) ObjCTypeNameAST;
        ast->type_id = type_id;
        return ast;
    }

    ObjCEncodeExpressionAST *ObjCEncodeExpression(ObjCTypeNameAST *type_name = 0)
    {
        ObjCEncodeExpressionAST *ast = new (&pool) ObjCEncodeExpressionAST;
        ast->type_name = type_name;
        return ast;
    }

    ObjCSelectorExpressionAST *ObjCSelectorExpression(ObjCSelectorAST *selector = 0)
    {
        ObjCSelectorExpressionAST *ast = new (&pool) ObjCSelectorExpressionAST;
        ast->selector = selector;
        return ast;
    }

    ObjCInstanceVariablesDeclarationAST *ObjCInstanceVariablesDeclaration(DeclarationListAST *instance_variable_list = 0)
    {
        ObjCInstanceVariablesDeclarationAST *ast = new (&pool) ObjCInstanceVariablesDeclarationAST;
        ast->instance_variable_list = instance_variable_list;
        return ast;
    }

    ObjCVisibilityDeclarationAST *ObjCVisibilityDeclaration()
    {
        ObjCVisibilityDeclarationAST *ast = new (&pool) ObjCVisibilityDeclarationAST;
        return ast;
    }

    ObjCPropertyAttributeAST *ObjCPropertyAttribute(ObjCSelectorAST *method_selector = 0)
    {
        ObjCPropertyAttributeAST *ast = new (&pool) ObjCPropertyAttributeAST;
        ast->method_selector = method_selector;
        return ast;
    }

    ObjCPropertyDeclarationAST *ObjCPropertyDeclaration(SpecifierListAST *attribute_list = 0, ObjCPropertyAttributeListAST *property_attribute_list = 0, DeclarationAST *simple_declaration = 0)
    {
        ObjCPropertyDeclarationAST *ast = new (&pool) ObjCPropertyDeclarationAST;
        ast->attribute_list = attribute_list;
        ast->property_attribute_list = property_attribute_list;
        ast->simple_declaration = simple_declaration;
        return ast;
    }

    ObjCMessageArgumentDeclarationAST *ObjCMessageArgumentDeclaration(ObjCTypeNameAST *type_name = 0, SpecifierListAST *attribute_list = 0, NameAST *param_name = 0)
    {
        ObjCMessageArgumentDeclarationAST *ast = new (&pool) ObjCMessageArgumentDeclarationAST;
        ast->type_name = type_name;
        ast->attribute_list = attribute_list;
        ast->param_name = param_name;
        return ast;
    }

    ObjCMethodPrototypeAST *ObjCMethodPrototype(ObjCTypeNameAST *type_name = 0, ObjCSelectorAST *selector = 0, ObjCMessageArgumentDeclarationListAST *argument_list = 0, SpecifierListAST *attribute_list = 0)
    {
        ObjCMethodPrototypeAST *ast = new (&pool) ObjCMethodPrototypeAST;
        ast->type_name = type_name;
        ast->selector = selector;
        ast->argument_list = argument_list;
        ast->attribute_list = attribute_list;
        return ast;
    }

    ObjCMethodDeclarationAST *ObjCMethodDeclaration(ObjCMethodPrototypeAST *method_prototype = 0, StatementAST *function_body = 0)
    {
        ObjCMethodDeclarationAST *ast = new (&pool) ObjCMethodDeclarationAST;
        ast->method_prototype = method_prototype;
        ast->function_body = function_body;
        return ast;
    }

    ObjCSynthesizedPropertyAST *ObjCSynthesizedProperty()
    {
        ObjCSynthesizedPropertyAST *ast = new (&pool) ObjCSynthesizedPropertyAST;
        return ast;
    }

    ObjCSynthesizedPropertiesDeclarationAST *ObjCSynthesizedPropertiesDeclaration(ObjCSynthesizedPropertyListAST *property_identifier_list = 0)
    {
        ObjCSynthesizedPropertiesDeclarationAST *ast = new (&pool) ObjCSynthesizedPropertiesDeclarationAST;
        ast->property_identifier_list = property_identifier_list;
        return ast;
    }

    ObjCDynamicPropertiesDeclarationAST *ObjCDynamicPropertiesDeclaration(NameListAST *property_identifier_list = 0)
    {
        ObjCDynamicPropertiesDeclarationAST *ast = new (&pool) ObjCDynamicPropertiesDeclarationAST;
        ast->property_identifier_list = property_identifier_list;
        return ast;
    }

    ObjCFastEnumerationAST *ObjCFastEnumeration(SpecifierListAST *type_specifier_list = 0, DeclaratorAST *declarator = 0, ExpressionAST *initializer = 0, ExpressionAST *fast_enumeratable_expression = 0, StatementAST *statement = 0)
    {
        ObjCFastEnumerationAST *ast = new (&pool) ObjCFastEnumerationAST;
        ast->type_specifier_list = type_specifier_list;
        ast->declarator = declarator;
        ast->initializer = initializer;
        ast->fast_enumeratable_expression = fast_enumeratable_expression;
        ast->statement = statement;
        return ast;
    }

    ObjCSynchronizedStatementAST *ObjCSynchronizedStatement(ExpressionAST *synchronized_object = 0, StatementAST *statement = 0)
    {
        ObjCSynchronizedStatementAST *ast = new (&pool) ObjCSynchronizedStatementAST;
        ast->synchronized_object = synchronized_object;
        ast->statement = statement;
        return ast;
    }

    LambdaExpressionAST *LambdaExpression(LambdaIntroducerAST *lambda_introducer = 0, LambdaDeclaratorAST *lambda_declarator = 0, StatementAST *statement = 0)
    {
        LambdaExpressionAST *ast = new (&pool) LambdaExpressionAST;
        ast->lambda_introducer = lambda_introducer;
        ast->lambda_declarator = lambda_declarator;
        ast->statement = statement;
        return ast;
    }

    LambdaIntroducerAST *LambdaIntroducer(LambdaCaptureAST *lambda_capture = 0)
    {
        LambdaIntroducerAST *ast = new (&pool) LambdaIntroducerAST;
        ast->lambda_capture = lambda_capture;
        return ast;
    }

    LambdaCaptureAST *LambdaCapture(CaptureListAST *capture_list = 0)
    {
        LambdaCaptureAST *ast = new (&pool) LambdaCaptureAST;
        ast->capture_list = capture_list;
        return ast;
    }

    CaptureAST *Capture(NameAST *identifier = 0)
    {
        CaptureAST *ast = new (&pool) CaptureAST;
        ast->identifier = identifier;
        return ast;
    }

    LambdaDeclaratorAST *LambdaDeclarator(ParameterDeclarationClauseAST *parameter_declaration_clause = 0, SpecifierListAST *attributes = 0, ExceptionSpecificationAST *exception_specification = 0, TrailingReturnTypeAST *trailing_return_type = 0)
    {
        LambdaDeclaratorAST *ast = new (&pool) LambdaDeclaratorAST;
        ast->parameter_declaration_clause = parameter_declaration_clause;
        ast->attributes = attributes;
        ast->exception_specification = exception_specification;
        ast->trailing_return_type = trailing_return_type;
        return ast;
    }

    TrailingReturnTypeAST *TrailingReturnType(SpecifierListAST *attributes = 0, SpecifierListAST *type_specifier_list = 0, DeclaratorAST *declarator = 0)
    {
        TrailingReturnTypeAST *ast = new (&pool) TrailingReturnTypeAST;
        ast->attributes = attributes;
        ast->type_specifier_list = type_specifier_list;
        ast->declarator = declarator;
        return ast;
    }

    BracedInitializerAST *BracedInitializer(ExpressionListAST *expression_list = 0)
    {
        BracedInitializerAST *ast = new (&pool) BracedInitializerAST;
        ast->expression_list = expression_list;
        return ast;
    }

    DotDesignatorAST *DotDesignator()
    {
        DotDesignatorAST *ast = new (&pool) DotDesignatorAST;
        return ast;
    }

    BracketDesignatorAST *BracketDesignator(ExpressionAST *expression = 0)
    {
        BracketDesignatorAST *ast = new (&pool) BracketDesignatorAST;
        ast->expression = expression;
        return ast;
    }

    DesignatedInitializerAST *DesignatedInitializer(DesignatorListAST *designator_list = 0, ExpressionAST *initializer = 0)
    {
        DesignatedInitializerAST *ast = new (&pool) DesignatedInitializerAST;
        ast->designator_list = designator_list;
        ast->initializer = initializer;
        return ast;
    }

    BaseSpecifierListAST *BaseSpecifierList(BaseSpecifierAST *value, BaseSpecifierListAST *next = 0)
    {
        BaseSpecifierListAST *list = new (&pool) BaseSpecifierListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    CaptureListAST *CaptureList(CaptureAST *value, CaptureListAST *next = 0)
    {
        CaptureListAST *list = new (&pool) CaptureListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    CatchClauseListAST *CatchClauseList(CatchClauseAST *value, CatchClauseListAST *next = 0)
    {
        CatchClauseListAST *list = new (&pool) CatchClauseListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    DeclarationListAST *DeclarationList(DeclarationAST *value, DeclarationListAST *next = 0)
    {
        DeclarationListAST *list = new (&pool) DeclarationListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    DeclaratorListAST *DeclaratorList(DeclaratorAST *value, DeclaratorListAST *next = 0)
    {
        DeclaratorListAST *list = new (&pool) DeclaratorListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    DesignatorListAST *DesignatorList(DesignatorAST *value, DesignatorListAST *next = 0)
    {
        DesignatorListAST *list = new (&pool) DesignatorListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    EnumeratorListAST *EnumeratorList(EnumeratorAST *value, EnumeratorListAST *next = 0)
    {
        EnumeratorListAST *list = new (&pool) EnumeratorListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    ExpressionListAST *ExpressionList(ExpressionAST *value, ExpressionListAST *next = 0)
    {
        ExpressionListAST *list = new (&pool) ExpressionListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    GnuAttributeListAST *GnuAttributeList(GnuAttributeAST *value, GnuAttributeListAST *next = 0)
    {
        GnuAttributeListAST *list = new (&pool) GnuAttributeListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    MemInitializerListAST *MemInitializerList(MemInitializerAST *value, MemInitializerListAST *next = 0)
    {
        MemInitializerListAST *list = new (&pool) MemInitializerListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    NameListAST *NameList(NameAST *value, NameListAST *next = 0)
    {
        NameListAST *list = new (&pool) NameListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    NestedNameSpecifierListAST *NestedNameSpecifierList(NestedNameSpecifierAST *value, NestedNameSpecifierListAST *next = 0)
    {
        NestedNameSpecifierListAST *list = new (&pool) NestedNameSpecifierListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    NewArrayDeclaratorListAST *NewArrayDeclaratorList(NewArrayDeclaratorAST *value, NewArrayDeclaratorListAST *next = 0)
    {
        NewArrayDeclaratorListAST *list = new (&pool) NewArrayDeclaratorListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    ObjCMessageArgumentDeclarationListAST *ObjCMessageArgumentDeclarationList(ObjCMessageArgumentDeclarationAST *value, ObjCMessageArgumentDeclarationListAST *next = 0)
    {
        ObjCMessageArgumentDeclarationListAST *list = new (&pool) ObjCMessageArgumentDeclarationListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    ObjCMessageArgumentListAST *ObjCMessageArgumentList(ObjCMessageArgumentAST *value, ObjCMessageArgumentListAST *next = 0)
    {
        ObjCMessageArgumentListAST *list = new (&pool) ObjCMessageArgumentListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    ObjCPropertyAttributeListAST *ObjCPropertyAttributeList(ObjCPropertyAttributeAST *value, ObjCPropertyAttributeListAST *next = 0)
    {
        ObjCPropertyAttributeListAST *list = new (&pool) ObjCPropertyAttributeListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    ObjCSelectorArgumentListAST *ObjCSelectorArgumentList(ObjCSelectorArgumentAST *value, ObjCSelectorArgumentListAST *next = 0)
    {
        ObjCSelectorArgumentListAST *list = new (&pool) ObjCSelectorArgumentListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    ObjCSynthesizedPropertyListAST *ObjCSynthesizedPropertyList(ObjCSynthesizedPropertyAST *value, ObjCSynthesizedPropertyListAST *next = 0)
    {
        ObjCSynthesizedPropertyListAST *list = new (&pool) ObjCSynthesizedPropertyListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    ParameterDeclarationListAST *ParameterDeclarationList(ParameterDeclarationAST *value, ParameterDeclarationListAST *next = 0)
    {
        ParameterDeclarationListAST *list = new (&pool) ParameterDeclarationListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    PostfixDeclaratorListAST *PostfixDeclaratorList(PostfixDeclaratorAST *value, PostfixDeclaratorListAST *next = 0)
    {
        PostfixDeclaratorListAST *list = new (&pool) PostfixDeclaratorListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    PtrOperatorListAST *PtrOperatorList(PtrOperatorAST *value, PtrOperatorListAST *next = 0)
    {
        PtrOperatorListAST *list = new (&pool) PtrOperatorListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    QtInterfaceNameListAST *QtInterfaceNameList(QtInterfaceNameAST *value, QtInterfaceNameListAST *next = 0)
    {
        QtInterfaceNameListAST *list = new (&pool) QtInterfaceNameListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    QtPropertyDeclarationItemListAST *QtPropertyDeclarationItemList(QtPropertyDeclarationItemAST *value, QtPropertyDeclarationItemListAST *next = 0)
    {
        QtPropertyDeclarationItemListAST *list = new (&pool) QtPropertyDeclarationItemListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    SpecifierListAST *SpecifierList(SpecifierAST *value, SpecifierListAST *next = 0)
    {
        SpecifierListAST *list = new (&pool) SpecifierListAST;
        list->next = next;
        list->value = value;
        return list;
    }

    StatementListAST *StatementList(StatementAST *value, StatementListAST *next = 0)
    {
        StatementListAST *list = new (&pool) StatementListAST;
        list->next = next;
        list->value = value;
        return list;
    }

};

} // end of namespace psyche

#endif // CFE_AST_PATTERN_BUILDER_H
