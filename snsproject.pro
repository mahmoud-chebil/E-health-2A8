QT       += core gui sql printsupport network
QT       +=multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Doctor/doctor.cpp \
    Doctor/medicalfile.cpp \
    Doctor/patient.cpp \
    administration/admin.cpp \
    administration/department.cpp \
    administration/dialog.cpp \
    administration/mailing/emailaddress.cpp \
    administration/mailing/mimeattachment.cpp \
    administration/mailing/mimecontentformatter.cpp \
    administration/mailing/mimefile.cpp \
    administration/mailing/mimehtml.cpp \
    administration/mailing/mimeinlinefile.cpp \
    administration/mailing/mimemessage.cpp \
    administration/mailing/mimemultipart.cpp \
    administration/mailing/mimepart.cpp \
    administration/mailing/mimetext.cpp \
    administration/mailing/quotedprintable.cpp \
    administration/mailing/smtpclient.cpp \
    administration/recruits.cpp \
    connection.cpp \
    employee/appointment.cpp \
    employee/consultation.cpp \
    employee/employee.cpp \
    main.cpp \
    login.cpp

HEADERS += \
    Doctor/doctor.h \
    Doctor/medicalfile.h \
    Doctor/patient.h \
    administration/admin.h \
    administration/department.h \
    administration/dialog.h \
    administration/mailing/SmtpMime \
    administration/mailing/emailaddress.h \
    administration/mailing/mimeattachment.h \
    administration/mailing/mimecontentformatter.h \
    administration/mailing/mimefile.h \
    administration/mailing/mimehtml.h \
    administration/mailing/mimeinlinefile.h \
    administration/mailing/mimemessage.h \
    administration/mailing/mimemultipart.h \
    administration/mailing/mimepart.h \
    administration/mailing/mimetext.h \
    administration/mailing/quotedprintable.h \
    administration/mailing/smtpclient.h \
    administration/mailing/smtpexports.h \
    administration/recruits.h \
    connection.h \
    employee/appointment.h \
    employee/consultation.h \
    employee/employee.h \
    login.h

FORMS += \
    Doctor/doctor.ui \
    administration/admin.ui \
    administration/dialog.ui \
    employee/employee.ui \
    login.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    Doctor/White_Background.jpg \
    Doctor/istockphoto-1211152561-612x612.jpg \
    administration/click.mp3 \
    administration/eAdministration.jpg.560x300_q85_box-267,0,6493,3338_crop_detail.jpg \
    administration/flech.jpg \
    administration/grass.jpg \
    administration/white.jpg \
    administration/wood.jpg \
    employee/bg \
    employee/button.png \
    employee/white.jpg
