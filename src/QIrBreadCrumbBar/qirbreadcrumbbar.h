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
#ifndef QIRBREADCRUMBBAR_H
#define QIRBREADCRUMBBAR_H

#include <QWidget>
#include "../Common/qirwidget.h"

class QComboBox;
template < typename T >
class QList;

QIR_BEGIN_NAMESPACE

class QIrAbstractBreadCrumbModel;
class QIrBreadCrumbBarUi;

class QIRONSHARED_EXPORT QIrBreadCrumbBar : public QWidget, public QIrWidget
{
    Q_OBJECT
    QIR_DECLARE_UI(QIrBreadCrumbBar)
	Q_PROPERTY(bool editable READ isEditable WRITE setEditable RESET goToDefault DESIGNABLE true)
    Q_PROPERTY(QString location READ location WRITE setLocation DESIGNABLE true NOTIFY locationChanged)

public:
	QIR_WIDGET_CAST

    explicit QIrBreadCrumbBar( QWidget * parent = 0 );
    ~QIrBreadCrumbBar();
	
    QSize sizeHint() const;

    bool isEditable() const;
	void setEditable( bool );

	QString location() const;
    void setLocation( const QString & );

    QComboBox * comboBox() const;

	QIrAbstractBreadCrumbModel * model() const;
	void setModel( QIrAbstractBreadCrumbModel * );

	inline QString widgetGroupKey() const { return "qiron_breadcrumbbar"; }
	
	void refresh();

public slots:
    void edit();
    void goToDefault();

protected:
	QIrSubStyle * defaultSubStyle() const;
	inline void subStyleChanged() { refresh(); }

	void resizeEvent( QResizeEvent * );
	void paintEvent( QPaintEvent * );
	
signals:
    void locationChanged( const QString & );
};

QIR_END_NAMESPACE

#endif // QIRBREADCRUMBBAR_H


