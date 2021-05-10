## uTensor set-up
uTensor depends on certain libaries (check https://github.com/uTensor/uTensor)


For generating MNIST models:
```
pipenv shell
jupyter notebook Generate-Cifar-for-Utensor-.ipynb
```


For compile and flashing the device:
```
mbed compile -m NRF52840_DK
./flashing.sh
```