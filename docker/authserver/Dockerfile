# MIT License
# Copyright (c) 2017 Nicola Worthington <nicolaw@tfb.net>

FROM debian:jessie
LABEL author="Nicola Worthington <nicolaw@tfb.net>"

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get -qq -o Dpkg::Use-Pty=0 update && \
    apt-get -qq -o Dpkg::Use-Pty=0 install -y --no-install-recommends \
    libboost-filesystem1.55 \
    libboost-iostreams1.55 \
    libboost-program-options1.55 \
    libboost-system1.55 \
    libboost-thread1.55 \
    libssl1.0.0 \
    libmysqlclient18 \
    netcat \
    tzdata \
 < /dev/null > /dev/null \
 && rm -rf /var/lib/apt/lists/*

# Set your timezone here
RUN ln -sf /usr/share/zoneinfo/America/Chicago /etc/localtime

# Configurable via INSTALL_PREFIX from the Makefile, and/or using
# --define CMAKE_INSTALL_PREFIX=/your/path with the docker/build/ container,
# (which is also published on Ducker Hub as nicolaw/trinitycore).
ENV install_prefix /opt/trinitycore

WORKDIR "${install_prefix}/bin"
VOLUME "${install_prefix}/etc"

# Wait for the database server to come up first.
ADD https://raw.githubusercontent.com/vishnubob/wait-for-it/master/wait-for-it.sh "${install_prefix}/bin/wait-for-it.sh"
COPY authserver.sh "${install_prefix}/bin/authserver.sh"
COPY authserver "${install_prefix}/bin/authserver"
COPY etc "${install_prefix}/etc"

RUN chmod +x "${install_prefix}/bin"/*

ENV DEBIAN_FRONTEND newt

ENTRYPOINT ["./authserver.sh"]

