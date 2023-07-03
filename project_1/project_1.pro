QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    data.cpp \
    file_function.cpp \
    log_out.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    page.cpp \
    personal.cpp \
    private_chat.cpp \
    selection_page.cpp \
    signup.cpp

HEADERS += \
    data.h \
    file_function.h \
    log_out.h \
    login.h \
    mainwindow.h \
    menu.h \
    page.h \
    personal.h \
    private_chat.h \
    selection_page.h \
    signup.h \
    user.h

FORMS += \
    log_out.ui \
    login.ui \
    mainwindow.ui \
    menu.ui \
    page.ui \
    private_chat.ui \
    selection_page.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    background_chat.qrc \
    exit.qrc \
    pic22.qrc \
    pictuer.qrc \
    search.qrc \
    send.qrc \
    stic4.qrc \
    sticker.qrc \
    sticker2.qrc \
    sticker3.qrc
