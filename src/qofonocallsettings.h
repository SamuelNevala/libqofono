/****************************************************************************
**
** Copyright (C) 2013 Jolla Ltd.
** Contact: lorn.potter@jollamobile.com
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
****************************************************************************/

#ifndef QOFONOCallSettings_H
#define QOFONOCallSettings_H

#include <QObject>
#include <QDBusVariant>

#include "qofono_global.h"
//! This class is used to access ofono call settings API
/*!
 * The API is documented in
 * http://git.kernel.org/?p=network/ofono/ofono.git;a=blob_plain;f=doc/call-settings-api.txt
 */

class QOfonoCallSettingsPrivate;
class QOFONOSHARED_EXPORT QOfonoCallSettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString modemPath READ modemPath WRITE setModemPath NOTIFY modemPathChanged)


public:
    explicit QOfonoCallSettings(QObject *parent = 0);
    ~QOfonoCallSettings();

    QString modemPath() const;
    void setModemPath(const QString &path);

    QString callingLinePresentation();
    QString calledLinePresentation();
    QString callingNamePresentation();
    QString connectedLinePresentation();
    QString connectedLineRestriction();
    QString callingLineRestriction();

    QString hideCallerId();
    void setHideCallerId(const QString &setting);

    QString voiceCallWaiting();
    void setVoiceCallWaiting(const QString &setting);

    bool isValid() const;
Q_SIGNALS:

    void callingLinePresentationChanged(const QString &setting);
    void calledLinePresentationChanged(const QString &setting);
    void callingNamePresentationChanged(const QString &setting);
    void connectedLinePresentationChanged(const QString &setting);
    void connectedLineRestrictionChanged(const QString &setting);
    void callingLineRestrictionChanged(const QString &setting);
    void hideCallerIdChanged(const QString &setting);
    void voiceCallWaitingChanged(const QString &setting);
    void modemPathChanged(const QString &path);

public slots:
    
private:
    QOfonoCallSettingsPrivate *d_ptr;
private slots:
    void propertyChanged(const QString &property,const QDBusVariant &value);
};

#endif // QOFONOCallSettings_H
