#!/bin/bash

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./cub3D map/42.cub