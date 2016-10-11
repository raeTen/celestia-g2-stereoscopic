// qtstereosettings.cpp
//
// Copyright (C) 2001-2015, Celestia Development Team
//
// dockable stereo settings panel for Qt4 UI.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

#include "celestia/celestiacore.h"
///#include "celutil/utf8.h"

#include <QVBoxLayout>

#include "qtstereosettings.h"
#include <QSignalMapper>
#include <QComboBox>
#include <QSlider>
#include <QLabel>
#include <QCheckBox>
#include <QString>
#include <QSpacerItem>
#include <QCloseEvent>
#include <QShowEvent>

//TODO getting mode and label values from celestiacore
const char* modelist[] = {"None","Anaglyph","Shutter","Shutter_i","Side-by-side crosseyed",NULL};
const char* sliderlabellist[] = {"Stereo Mode","Stereo Depth","BackPlane relief","FrontPlane depth","FooBar",NULL};
const char* checkboxlabellist[] = {"Inverted Stereo","Simple settings","RightEye",NULL};

using namespace std;
StereoSettings::StereoSettings( CelestiaCore* _appCore,
                                const QString& title,
                                QWidget* parent) :
    QDockWidget(title, parent),
    appCore(_appCore),
    stereoModeSelectBox(NULL),
    parentwidget(parent)
{
    QSignalMapper* pSignalMapper = new QSignalMapper(this);
    connect(this ,SIGNAL( visibilityChanged(bool) ),\
            this,\
            SLOT( uiVisibility(bool) ) );
    QWidget* stereoWidget = new QWidget( this );

    m_pLayout = new QVBoxLayout( stereoWidget );

    stereoModeSelectBox = new QComboBox(stereoWidget);
    int i = 0;
    while (modelist[i] != '\0'){
        stereoModeSelectBox->addItem(_( modelist[i] ));
        i++;
        stereoModeSelectBox->setCurrentIndex(appCore->stereo->getMode());
    }
    connect(stereoModeSelectBox, \
            SIGNAL(currentIndexChanged(int)), \
            this, \
            SLOT(slotRefreshValues(int)));
    
    i=0;
    //adding sliders+labels
    while ( sliderlabellist[i] != '\0' )
    {
        if (i==0) {
            QLabel* m_pLabel = new QLabel( stereoWidget );
            QString strLabelName = "StereoLabel" + QString().setNum(i);
            m_pLabel->setObjectName( strLabelName );
            m_pLabel->setText( sliderlabellist[i] );
            m_pLayout->addWidget( m_pLabel );
            m_pLayout->addWidget( stereoModeSelectBox );
        }
        else
        {
        QLabel* m_pLabel = new QLabel( stereoWidget );
        QString strLabelName = "SliderLabel" + QString().setNum(i);
        m_pLabel->setObjectName( strLabelName );
        
        QSlider* pSlider = new QSlider( stereoWidget );
        QString strSliderName = "StereoSlider" + QString().setNum(i);
        pSlider->setObjectName( strSliderName );
        pSlider->setMinimum( 0 );
        pSlider->setMaximum( 148 );
        pSlider->setSingleStep( 1 );
        pSlider->setOrientation( Qt::Horizontal );
        //default values from core
        pSlider->setValue(appCore->stereo->getStereoVal(i-1));
        m_pLabel->setText( sliderlabellist[i] +QString(" ") +\
                            QString::number( pSlider->value() ) );
        m_pLayout->addWidget(m_pLabel);
        m_pLayout->addWidget( pSlider );
        connect( pSlider, SIGNAL( valueChanged(int)), pSignalMapper, SLOT(map()) );
        pSignalMapper->setMapping( pSlider, pSlider );

        }
        i++;
    }
    i=0;
    //adding checkboxes
    while ( checkboxlabellist[i] != '\0' )
    {
        QCheckBox* pCheckbox = new QCheckBox( stereoWidget );
        QString strSliderName = "StereoCheckbox" + QString().setNum(i);
        pCheckbox->setObjectName( strSliderName );
        pCheckbox->setText( checkboxlabellist[i] +QString(" ") );
        m_pLayout->addWidget( pCheckbox );
        connect( pCheckbox, SIGNAL( stateChanged(int)), pSignalMapper, SLOT(map() ) );
        pSignalMapper->setMapping( pCheckbox, pCheckbox );
        i++;
    }
    connect( pSignalMapper, SIGNAL( mapped(QWidget*) ), this, SLOT( slotRefreshValues(QWidget*) ) );

    QSpacerItem* vspacer = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    m_pLayout->addItem( vspacer );
    stereoWidget->setLayout( m_pLayout );
    this->setWidget( stereoWidget );

}

StereoSettings::~StereoSettings()
{
}
/*mapped overloaded slots*/
void StereoSettings::slotRefreshValues( QWidget* pWidget )
{
    QSlider* actSlider = qobject_cast<QSlider*>(pWidget);
    if ( actSlider != NULL )
    {
        QString nr = actSlider->objectName().right(1);
        QLabel* actLabel = sender()->parent()->findChild<QLabel*>("SliderLabel"+nr);
        if (actLabel != NULL){
            actLabel->setText( sliderlabellist[nr.toInt()] + QString(" ")\
                                + QString::number(actSlider->value() ) );
            appCore->stereo->setStereoVal( nr.toInt()-1, actSlider->value() );
            //appCore->stereo->printVals();
        }
    }
    QCheckBox* actCheckbox = qobject_cast<QCheckBox*>(pWidget);
    if ( actCheckbox != NULL )
    {
        QString nr = actCheckbox->objectName().right(1);
        appCore->stereo->setStereoFlag( nr.toInt(), actCheckbox->isChecked() );
    }
}
void StereoSettings::slotRefreshValues( int mode )
{
    appCore->stereo->setMode(mode);
    //appCore->stereo->printVals();
}
void StereoSettings::uiVisibility(bool visible)
{
    appCore->stereo->uiVisible = visible;
}

