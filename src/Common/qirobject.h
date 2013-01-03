/********************************************************************** 
**
** This file is part of QIron Toolkit.
**
** Copyright (C) 2009-2020 Dzimi Mve Alexandre <dzimiwine@gmail.com>
** 
** Contact: dzimiwine@gmail.com
** 
** QIron is a free toolkit developed in Qt by Dzimi Mve A.; you can redistribute 
** sources and libraries of this library and/or modify them under the terms of 
** the GNU Library General Public License version 3.0 as published by the 
** Free Software Foundation and appearing in the file LICENSE.txt included in 
** the packaging of this file.
** Please review the following information to ensure the GNU General 
** Public License version 3.0 requirements will be met: 
** http://www.gnu.org/copyleft/gpl.html.
**
** This SDK is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Library General Public License for more details.
**
**********************************************************************/
#ifndef QIROBJECT_H
#define QIROBJECT_H

#include <QString>
#include "qiron_export.h"


QIR_BEGIN_NAMESPACE

template < class T > class QList;
class QIrObject;
typedef QList< QIrObject * > QIrObjectList;
class QIrObjectPrivate;

class QIRONSHARED_EXPORT QIrObject
{
	friend class QIrObjectPrivate;

public:
	QIrObject();
        virtual ~QIrObject();

	static QIrObjectList allObjects( const QString & objectGroupKey = QString() );

	inline virtual QString objectGroupKey() const { return "qiron_object"; }

protected:
	QIrObject( QIrObjectPrivate & p );
	
	QIrObjectPrivate * p_ptr;
};

QIR_END_NAMESPACE

#endif // QIROBJECT_H
