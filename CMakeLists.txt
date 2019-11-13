cmake_minimum_required(VERSION 3.10)


PROJECT(mvvmc)

ADD_LIBRARY(mvvmc SHARED
	"${PROJECT_SOURCE_DIR}/hash_map.c"
	"${PROJECT_SOURCE_DIR}/mvvmc.c"

)

