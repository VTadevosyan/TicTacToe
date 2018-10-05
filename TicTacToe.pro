#-------------------------------------------------
#
# Project created by QtCreator 2018-05-09T12:31:25
#
#-------------------------------------------------

QT += core gui
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TicTacToe
TEMPLATE = app
OBJECTS_DIR = build
MOC_DIR = build

SOURCES += game/main.cpp\
        items/item_o.cpp \
        items/item_x.cpp \
        player/player_o.cpp \
        player/player_x.cpp \
        gui/actions.cpp \
        gui/board.cpp \
        gui/game_mode_selector.cpp \
        gui/main_window.cpp \
        gui/menu.cpp \
        gui/style_dialog.cpp \
        game/manager.cpp \

HEADERS  += game/manager.hpp \
        items/item_x.hpp \
        items/item_o.hpp \
        items/abstract_item.hpp \
        player/player.hpp \
        player/player_o.hpp \
        player/player_x.hpp \
        style.hpp \
        gui/actions.hpp \
        gui/board.hpp \
        gui/game_mode_selector.hpp \
        gui/main_window.hpp \
        gui/menu.hpp \
        gui/style_dialog.hpp \
    game/options.hpp

