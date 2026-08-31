#!/bin/bash
mkdir -p ~/.local/bin
cp ./mon_programme.c ~/.local/bin/
cp ./mon_programme ~/.local/bin/
chmod +x ~/.local/bin/mon_programme
 
if [[ ":$PATH:" != *":$HOME/.local/bin:"* ]]; then
	    echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
	        export PATH="$HOME/.local/bin:$PATH"
fi
