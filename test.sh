#!/bin/bash

clear
valgrind --leak-check=full --show-leak-kinds=all -s ./cub3D map/mini.cub