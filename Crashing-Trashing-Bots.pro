TEMPLATE = app


CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG +=c++11


LIBS += libfreeglut -lopengl32 -lglu32 -luser32


SOURCES += main.cpp


HEADERS += glutcpp\glutcpp.h \
    special_keys.h \
    display.h \
    glutcpp\tacka.h \
    timer.h \
    global.h \
    robot.h \
    robot_1.h \
    robot_2.h \
    robot_3.h \
    delovi.h \
    vektor3d.h \
    glutcpp/special_keys.h \
    glutcpp/timer.h \
    glutcpp/glutDisplay.h \
    glutcpp/glutNormalKeyListener.h \
    normalKeyListener.h \
    glutcpp/glutMotionListener.h \
    motionListener.h \
    mouseListener.h \
    glutcpp/glutMouseListener.h \
    glutcpp/glutReshapeListener.h \
    reshapeListener.h


include(deployment.pri)
qtcAddDeployment()
