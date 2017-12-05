//! \file
/*
**  Copyright (C) - Triton
**
**  This program is under the terms of the BSD License.
*/

#ifndef TRITON_SYMBOLICVALUE_H
#define TRITON_SYMBOLICVALUE_H

#include <string>
#include <memory>

#include <triton/ast.hpp>
#include <triton/symbolicEnums.hpp>
#include <triton/tritonTypes.hpp>



//! The Triton namespace
namespace triton {
/*!
 *  \addtogroup triton
 *  @{
 */

  namespace ast {
    // Forward declaration
    class AbstractNode;
  }

  //! The Engines namespace
  namespace engines {
  /*!
   *  \ingroup triton
   *  \addtogroup engines
   *  @{
   */

    //! The Symbolic Execution namespace
    namespace symbolic {
    /*!
     *  \ingroup engines
     *  \addtogroup symbolic
     *  @{
     */

      //! \class SymbolicValue
      /*! \brief The base class for symbolic expression and symbolic value */
      class SymbolicValue {

        protected:
          //! The kind of the symbolic value.
          symkind_e kind;

          //! The root node (AST) of the symbolic value.
          std::shared_ptr<triton::ast::AbstractNode> ast;

          //! The comment of the symbolic value.
          std::string comment;

          //! The symbolic value id. This id is unique.
          triton::usize id;

        public:
          //! Constructor.
          SymbolicValue(std::shared_ptr<triton::ast::AbstractNode> expr, triton::usize id, symkind_e kind, const std::string& comment="");

          //! Returns the symbolic value id.
          triton::usize getId(void) const;

          //! Returns true if the symbolic value is assigned to a memory. \sa triton::engines::symbolic::symkind_e
          bool isMemory(void) const;

          //! Returns true if the symbolic value is assigned to a register. \sa triton::engines::symbolic::symkind_e
          bool isRegister(void) const;

          //! Returns true if the value contains a symbolic variable.
          bool isSymbolized(void) const;

          //! Returns the kind of the symbolic value.
          symkind_e getKind(void) const;

          //! Sets the kind of the symbolic value.
          void setKind(symkind_e k);

          //! Returns the comment of the symbolic value.
          const std::string& getComment(void) const;

          //! Sets a comment to the symbolic value.
          void setComment(const std::string& comment);

          //! Returns the SMT AST root node of the symbolic value. This is the semantics.
          triton::ast::AbstractNode* getAst(void) const;
          std::shared_ptr<triton::ast::AbstractNode> const& getShareAst(void);

          //! Returns a new SMT AST root node of the symbolic value. This new instance is a duplicate of the original node and may be changed without changing the original semantics.
          std::shared_ptr<triton::ast::AbstractNode> getNewAst(void) const;

          //! Sets a root node.
          void setAst(std::shared_ptr<triton::ast::AbstractNode> const& node);
      };

    /*! @} End of symbolic namespace */
    };
  /*! @} End of engines namespace */
  };
/*! @} End of triton namespace */
};

#endif /* TRITON_SYMBOLICVALUE_H */


