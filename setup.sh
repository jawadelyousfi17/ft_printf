#!/bin/bash

# Determine which shell is being used
if [[ "$SHELL" == *"bash"* ]]; then
    echo "Using bash"
    # Add alias to .bashrc
    echo "alias testpf='~/ft_printf/run_test.sh'" >> ~/.bashrc
    # Reload .bashrc
    #show message
    echo "Setup ended, Reload your terminal"
    source ~/.bashrc
elif [[ "$SHELL" == *"zsh"* ]]; then
    echo "Using zsh "
    # Add alias to .zshrc
    echo "alias testpf='~/ft_printf/run_test.sh'" >> ~/.zshrc
    # Reload .zshrc
    echo "Setup ended, Reload your terminal"
    zsh -c "source ~/.zshrc"
else
    echo "Unknown shell. Only bash and zsh are supported."
fi
