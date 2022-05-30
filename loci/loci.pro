QT += quick sql

SOURCES += \
        appfunctions.cpp \
        card.cpp \
        cardmodel.cpp \
        dbmanager.cpp \
        deck.cpp \
        main.cpp\
        selectedcard.cpp \
        selecteddeck.cpp

HEADERS += \
    appfunctions.h \
    card.h \
    cardmodel.h \
    dbmanager.h \
    deck.h \
    selectedcard.h \
    selecteddeck.h

resources.files = main.qml \
    FieldBox.qml \
    TopBar.qml \
    cardscreen.qml \
    deckscreen.qml \
    homescreen.qml


resources.prefix = /$${TARGET}
RESOURCES += resources

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    CardInfo.qml \
    CardInfoTable.qml \
    DeckInfo.qml
