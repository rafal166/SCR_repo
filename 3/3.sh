#!/bin/bash

echo $(tar -czvf $4 $(find $1 -mtime -$2 -iname "$3"))