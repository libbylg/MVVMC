cmake_minimum_required(VERSION 3.10)


PROJECT(mvvmc)

ADD_LIBRARY(mvvmc SHARED
	"${PROJECT_SOURCE_DIR}/trigger.c"
)