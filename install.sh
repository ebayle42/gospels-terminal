#!/bin/bash
mkdir -p ~/.local/bin
cp ./main.c ~/.local/bin/
cp ./gospels ~/.local/bin/
chmod +x ~/.local/bin/gospels
 
if [[ ":$PATH:" != *":$HOME/.local/bin:"* ]]; then
	    echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
	        export PATH="$HOME/.local/bin:$PATH"
fi
