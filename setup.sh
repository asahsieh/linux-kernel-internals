#!/bin/sh

# Essential packages
sudo apt install build-essential git-core valgrind
sudo apt install cppcheck clang-format aspell colordiff
# * The version of Cppcheck be used should over v1.90,
#   it can be installed alternatively by
#   * snap
#     `$ sudo snap install cppcheck`
#     `$ echo "PATH=/snap/bin:$PATH" >> ~/.bashrc`
#   * from source code
#       https://github.com/danmar/cppcheck/

# Setup for GitHub
# * Creates a new ssh key, using the provided email as a label
sh-keygen -t rsa -C "kchs.tw@gmail.com"

# * Add the key to `ssh-agent`
#   * Start the ssh-agent in the background
ssh-agent -s
ssh-add ~/.ssh/id_rsa

#   * Copies the content of the id_rsa.pub file to your clipboard
#clip < ~/.ssh/id_rsa.pub
cat ~/.ssh/id_rsa.pub

# * Paste the content to Github

# * Verifiy the authentication
ssh -T git@github.com
