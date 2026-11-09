#!/bin/bash
set -e

cd "$(dirname "$0")"

BIN_DIR="$HOME/.local/bin"
DATA_DIR="$HOME/.local/share/gospels-terminal"

if ! command -v gcc >/dev/null 2>&1; then
    echo "Erreur : gcc n'est pas installé (sudo apt install gcc)"
    exit 1
fi

mkdir -p "$BIN_DIR" "$DATA_DIR"

echo "Compilation..."
gcc -Wall -Wextra -Werror -O2 main.c -o "$BIN_DIR/gospels"
chmod +x "$BIN_DIR/gospels"

cp gospels.txt "$DATA_DIR/gospels.txt"

if [[ ":$PATH:" != *":$BIN_DIR:"* ]]; then
    LINE='export PATH="$HOME/.local/bin:$PATH"'
    for RC in "$HOME/.bashrc" "$HOME/.zshrc"; do
        if [ -f "$RC" ] && ! grep -qF "$LINE" "$RC"; then
            echo "$LINE" >> "$RC"
        fi
    done
    echo "~/.local/bin ajouté au PATH : ouvre un nouveau terminal ou tape  source ~/.bashrc"
fi

echo "Installation terminée : tape gospels"
