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
#ifndef QIRWIDGET_H
#define QIRWIDGET_H

#include "qiron_export.h"

template < typename T >
class QList;
class QString;

QIR_BEGIN_NAMESPACE

class QIrSubStyle;
class QIrWidget;
typedef QList< QIrWidget * > QIrWidgetList;
class QIrWidgetUi;

class QIRONSHARED_EXPORT QIrWidget
{
	friend class QIrWidgetUi;

public:
	QIrWidget();
        virtual ~QIrWidget();

	static QIrWidgetList allWidgets( const QString & widgetGroupKey = QString() );

	QIrSubStyle * subStyle() const;
	void setSubStyle( QIrSubStyle * );

	static QIrSubStyle * subStyle( const QString & widgetGroupKey );
	static QIrSubStyle * subStyle( const QIrWidget * w );
	static void setSubStyle( const QString & widgetGroupKey, QIrSubStyle * subStyle);
	static void setSubStyle(QIrWidget * w, QIrSubStyle * subStyle);

	virtual QWidget * toWidget() = 0;
	virtual const QWidget * toWidget() const = 0;

	inline virtual QString widgetGroupKey() const { return "qiron_widget"; }

protected:
	QIrWidget( QIrWidgetUi & ui );
	virtual QIrSubStyle * defaultSubStyle() const { return 0; }
	virtual void subStyleChanged();

	QIrWidgetUi * ui_ptr;
};

QIR_END_NAMESPACE

#endif // QIRWIDGET_H
