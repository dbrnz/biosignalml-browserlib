/*****************************************************************************
 *                                                                           *
 *  BioSignalML Browser in C++                                               *
 *                                                                           *
 *  Copyright (c) 2014-2015  David Brooks                                    *
 *                                                                           *
 *  Licensed under the Apache License, Version 2.0 (the "License");          *
 *  you may not use this file except in compliance with the License.         *
 *  You may obtain a copy of the License at                                  *
 *                                                                           *
 *      http://www.apache.org/licenses/LICENSE-2.0                           *
 *                                                                           *
 *  Unless required by applicable law or agreed to in writing, software      *
 *  distributed under the License is distributed on an "AS IS" BASIS,        *
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 *  See the License for the specific language governing permissions and      *
 *  limitations under the License.                                           *
 *                                                                           *
 *****************************************************************************/

#ifndef BROWSER_MAINWINDOW_H
#define BROWSER_MAINWINDOW_H

#include "typedefs.h"
#include "chartform.h"

#include "signallist.h"
#include "annotationlist.h"
#include "scroller.h"

#include <biosignalml/biosignalml.h>

#include <QMainWindow>
#include <QDockWidget>
#include <QVBoxLayout>
#include <QThread>


namespace Ui {

  class MainWindow
  /*============*/
  {
   public:
    void setupUi(QMainWindow *mainWindow, QWidget *signalsWidget,
                 QWidget *annotationsWidget, QWidget *scrollWidget) ;

    QWidget *centralwidget ;
    QVBoxLayout *verticalLayout ;
    browser::ChartForm *chartform ;
    QDockWidget *signalsDock ;
    QDockWidget *annotationsDock ;
    QDockWidget *scrollDock ;
    } ;

  } ;


namespace browser {

  class SignalReadThread : public QObject
  /*===================================*/
  {
   Q_OBJECT

   public:
    SignalReadThread(bsml::Signal::Ptr signal, bsml::Interval::Ptr interval,
                     ChartPlot *plotter) ;
    void start(void) ;
    void stop(void) ;
    bool wait(unsigned long time) ;

   signals:
    void append_points(QString, const bsml::data::TimeSeries::Ptr &) ;

   private:
    bsml::Signal::Ptr m_signal ;
    bsml::Interval::Ptr m_interval ;
    QString m_id ;
    bool m_exit ;
    QThread m_thread ;
    } ;

  } ;

#endif
