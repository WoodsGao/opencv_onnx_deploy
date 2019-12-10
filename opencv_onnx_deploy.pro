TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

INCLUDEPATH += \
    /usr/local/include \
    /usr/local/include/opencv \
    /usr/local/include/opencv2
LIBS += \
    /usr/local/lib/libopencv_core.so \
    /usr/local/lib/libopencv_highgui.so \
    /usr/local/lib/libopencv_dnn.so \
    /usr/local/lib/libopencv_imgproc.so \
    /usr/local/lib/libopencv_imgcodecs.so \
    /home/uisee/Projects/build-onnx_deploy-Desktop_Qt_5_9_8_GCC_64bit-Debug/bin/libonnx_deploy.so
