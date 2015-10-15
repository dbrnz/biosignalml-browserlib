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

#ifndef BROWSER_ANNOTATIONDIALOG_H
#define BROWSER_ANNOTATIONDIALOG_H

#include "ui_annotationdialog.h"
#include "chartplot.h"

#include <QDialog>
#include <QListWidgetItem>


namespace browser {

  class TagItem : public QListWidgetItem
  /*==================================*/
  {
   public:
    TagItem(const QString &uri, const QString &label) ;

    inline const QString &uri(void) const { return m_uri ; }
    inline const QString &label(void) const { return m_label ; }

   private:
    QString m_uri ;
    QString m_label ;
    } ;


  class AnnotationDialog : public QDialog
  /*===================================*/
  {
   public:
    AnnotationDialog(ChartPlot *parent, const QString &id, float start, float end,
                     const QString &text="", const QStringList &tags=QStringList()) ;
    QString get_annotation(void) const ;
    QStringList get_tags(void) const ;

   public slots:
    void show_tags(void) ;

   private:
    Ui_AnnotationDialog m_ui ;
    bool m_tagsvisible ;
    } ;

  } ;

#endif
