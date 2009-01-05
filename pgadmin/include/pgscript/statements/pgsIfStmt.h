//////////////////////////////////////////////////////////////////////////
//
// pgScript - PostgreSQL Tools
// RCS-ID:      $Id$
// Copyright (C) 2002 - 2009, The pgAdmin Development Team
// This software is released under the Artistic Licence
//
//////////////////////////////////////////////////////////////////////////


#ifndef PGSIFSTMT_H_
#define PGSIFSTMT_H_

#include "pgscript/pgScript.h"
#include "pgscript/statements/pgsStmt.h"

class pgsIfStmt : public pgsStmt
{

private:

	const pgsExpression * m_cond;
	const pgsStmt * m_stmt_list_if;
	const pgsStmt * m_stmt_list_else;

public:

	pgsIfStmt(const pgsExpression * cond, const pgsStmt * stmt_list_if,
			const pgsStmt * stmt_list_else, pgsThread * app = 0);

	virtual ~pgsIfStmt();

	virtual void eval(pgsVarMap & vars) const;

private:

	pgsIfStmt(const pgsIfStmt & that);

	pgsIfStmt & operator=(const pgsIfStmt & that);

};

#endif /*PGSIFSTMT_H_*/
