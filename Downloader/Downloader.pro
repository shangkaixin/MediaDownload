QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += C:\Python\Python38\include \


LIBS += C:\Python\Python38\libs\python3.lib \
        C:\Python\Python38\libs\python38.lib \

SOURCES += \
    aboutdialog.cpp \
    convertdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    newdialog.cpp

HEADERS += \
    aboutdialog.h \
    convertdialog.h \
    mainwindow.h \
    newdialog.h

FORMS += \
    aboutdialog.ui \
    convertdialog.ui \
    mainwindow.ui \
    newdialog.ui

TRANSLATIONS += \
    Downloader_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icon.qrc
