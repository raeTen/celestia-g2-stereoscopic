// qtstereosettings.h
//
// Copyright (C) 2001-2015, Celestia Development Team
//
// Dockable stereo settings panel for Qt4(5) UI.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
#ifndef _QTSTEREOSETTINGS_H_
#define _QTSTEREOSETTINGS_H_
#include <QDockWidget>

class CelestiaCore;
class QComboBox;
class QSlider;
class QLabel;
class QCheckBox;
class QSpacerItem;
class QVBoxLayout;
class QCloseEvent;
class QShowEvent;


class StereoSettings : public QDockWidget
{
Q_OBJECT

 public:
    StereoSettings(CelestiaCore* _appCore, const QString& title, QWidget* parent);
    ~StereoSettings();

 private:
     CelestiaCore* appCore;
     QComboBox* stereoModeSelectBox;
     QVBoxLayout* m_pLayout;
     //QSpacerItem* vspacer;
     QWidget* parentwidget;
     
 private slots:
     void slotRefreshValues(QWidget* pWidget);
     void slotRefreshValues(int);
     void uiVisibility(bool);

 
};
#endif // _QTSTEREOSETTINGS_H_
