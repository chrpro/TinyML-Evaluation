# Performance of Deep Neural Networks on Low-PowerIoT Devices

<b>Chistos Profentzas</b>, Magnus Almgren, and Olaf Landsiedel.


To compile the code you need arm-none-eabi-gcc

Makefiles are designed for cortex M with an FPU and DSP. 

## Code structure:

### CMSIS-NN/
 Evalution code fore CMSIS-NN design for NRF52840_DK
 
Jupyter-notebook : 

[Code-Generator-Cifar-CMSIS-NN.ipynb](./CMSIS-NN/Cifar-Models/Code-Generator-Cifar-CMSIS-NN.ipynb) ( Training / Quantization / C file generator)

[Code-Generator-MNIST-CMSIS-NN.ipynb](./CMSIS-NN/MNIST-Models/Code-Generator-MNIST-CMSIS-NN.ipynb) ( Training / Quantization / C file generator)

[Makefile](./CMSIS-NN/Cifar-Models/pca10056/blank/armgcc/Makefile) to compile for NRF52840_DK using NRFsdk-12

Cifar-10 example files
 
Mnist example files

 
### Tensorflow-micro/
 Evalution code fore CMSIS-NN design for NRF52840_DK

[Jupyter-notebooks](./Tensorflow-micro/CIFAR-Models/src/Generate model.ipynb) ( Training / model generator) 

Cifar-10 example files
 
Mnist example files
 
 
 ### uTensor/

[Jupyter-notebooks](./uTensor/Cifar-Models/Generate-Cifar-for-Utensor-.ipynb) ( Training / C++ Generator ) 
 
Cifar-10 example files
 
Mnist example files
