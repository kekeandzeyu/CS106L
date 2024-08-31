QT += widgets

# Make sure we do not accidentally #include files placed in 'res'
CONFIG += no_include_pwd
CONFIG += c++1z console
CONFIG -= app_bundle

# Explicitly list source and header files
SOURCES += \
    src/main.cpp \
    src/SimpleGraph.cpp

HEADERS += \
    src/SimpleGraph.h

# Set up flags for the compiler and Stanford C++ libraries
QMAKE_CXXFLAGS += -std=c++1z \
    -Wall \
    -Wextra \
    -Wreturn-type \
    -Werror=return-type \
    -Wunreachable-code \

# Copies the given files to the destination directory
# The rest of this file defines how to copy the resources folder
defineTest(copyToDestdir) {
    files = $$1

    for(FILE, files) {
        DDIR = $$OUT_PWD

        # Replace slashes in paths with backslashes for Windows
        win32:FILE ~= s,/,\\,g
        win32:DDIR ~= s,/,\\,g

        !win32 {
            copyResources.commands += cp -r '"'$$FILE'"' '"'$$DDIR'"' $$escape_expand(\\n\\t)
        }
        win32 {
            copyResources.commands += xcopy '"'$$FILE'"' '"'$$DDIR'"' /e /y $$escape_expand(\\n\\t)
        }
    }
    export(copyResources.commands)
}

!win32 {
    copyToDestdir($$files($$PWD/res/*))
}
win32 {
    copyToDestdir($$PWD/res)
}

copyResources.input = $$files($$PWD/res/*)
OTHER_FILES = $$files(res/*)
QMAKE_EXTRA_TARGETS += copyResources
POST_TARGETDEPS += copyResources

macx {
    cache()
    QMAKE_MAC_SDK = macosx
}

