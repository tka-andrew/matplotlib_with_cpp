# REFERENCE: https://jerin-electronics.medium.com/docker-now-ep1-python-opencv-in-docker-1dda564672c3

XSOCK=/tmp/.X11-unix
XAUTH=/tmp/.docker.xauth
touch $XAUTH
xauth nlist $DISPLAY | sed -e 's/^..../ffff/' | xauth -f $XAUTH nmerge -
PULSE_SERVER=unix:${XDG_RUNTIME_DIR}/pulse/native

# since we did cmake --build in the docker file and we already set WORKDIR to the build folder, we can straight away run the excutable
sudo docker run --rm -it -e DISPLAY=$DISPLAY -v $XSOCK:$XSOCK -v $XAUTH:$XAUTH \
                -e XAUTHORITY=$XAUTH -t tka-andrew/matplotlib-with-cpp:latest \
                bash -c "./MatplotlibWithCppExample"
