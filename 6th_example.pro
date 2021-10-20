QT += quick

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        src/Board.cpp \
        src/PieceInf.cpp \
        src/StringParser.cpp \
        src/bishop.cpp \
        src/gamecontroller.cpp \
        src/king.cpp \
        src/knight.cpp \
        src/pawn.cpp \
        src/queen.cpp \
        src/rook.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    header/Board.h \
    header/PieceInf.h \
    header/StringParser.h \
    header/VarDefine.h \
    header/Variable.h \
    header/bishop.h \
    header/gamecontroller.h \
    header/king.h \
    header/knight.h \
    header/pawn.h \
    header/queen.h \
    header/rook.h
