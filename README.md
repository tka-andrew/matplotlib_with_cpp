# Matplotlib with C++
This is just a minimal docker image for using matplotlib with cpp

## Usage
### Building the docker image
```
./buildDockerImage.sh
```

### Running the application on Docker container
```
./runDockerImage.sh
```

## Side notes
1. You may also use the matplotlibcpp.h straight away without adding the matplotlib-cpp as submodule, but remember to declare the license.
2. You may also comopile it without using cmake. For this, please refer to the README.md of official repo below.

## Reference
1. [Matplotlib-cpp GitHub repo](https://github.com/lava/matplotlib-cpp)
2. [A short documentation for basic usage](https://readthedocs.org/projects/matplotlib-cpp/downloads/pdf/latest/)