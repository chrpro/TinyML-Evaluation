## uTensor set-up
uTensor depends on certain libaries

For Cifar-10:


###generate the code
pipenv shell
jupyter notebook Generate-Cifar-for-Utensor-.ipynb

###open a new terminal
mbed compile -m NRF52840_DK
./flashing.sh