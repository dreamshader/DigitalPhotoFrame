###########################################################################
# Makefile for diashow
#
###########################################################################
# This Makefile is part of my diashow project
#	git://github.com/dreamshader/diashow.git
#
#  Copyright (C) 2020 Dreamshader (aka Dirk Schanz)
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#  
#      http://www.apache.org/licenses/LICENSE-2.0
#  
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.
#
###########################################################################
CXX = g++
CC  = gcc
#
DEBUG_FLAGS  = -g
#
CC_FLAGS = -Wall
#
DEFINE_FLAGS =
#
SOURCE_DIR = ../src
EXAMPLE_DIR = ../examples
#
PROJECT_BIN = wand
CORE_BIN = MagickCore
#
# LIBSRC = $(SOURCEDIR)/hc12Radio.cpp
# LIBINC = $(SOURCEDIR)/hc12Radio.h
# EXAMPLSRC = $(EXAMPLEDIR)/hc12Test.cpp
# EXAMPLNAME = hc12Test
# EXAMPLFLAGS = -I$(SOURCEDIR) -L ../build -l hc12Radio -l serialConnection
# LIBOBJ = hc12Radio.o
# SOLIBNAME = libhc12Radio.so

#
###########################################################################
# check for OS we are running
#
UNAME := $(shell uname -m)
#
ifeq ($(UNAME), x86_64)
ADDITIONAL_LIBS =
RASPBERRY_PI =
else
ADDITIONAL_LIBS = -lrt
RASPBERRY_PI = -DRASPBERRY_PI
endif
#
###########################################################################
#
all: $(PROJECT_BIN) $(CORE_BIN)

$(PROJECT_BIN): %: %.c
	$(CC)  -o $@ ${DEBUG_FLAGS} ${CC_FLAGS} ${DEFINE_FLAGS} $< `pkg-config --cflags --libs MagickWand`


$(CORE_BIN): %: %.c
	$(CC)  -o $@ ${DEBUG_FLAGS} ${CC_FLAGS} ${DEFINE_FLAGS} $< `pkg-config --cflags --libs MagickCore`


