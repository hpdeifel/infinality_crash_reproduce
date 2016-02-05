#!/bin/sh

qmake-qt4 && make && ./test crash.pdf
