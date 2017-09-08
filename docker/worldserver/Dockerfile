# MIT License
# Copyright (c) 2017 Nicola Worthington <nicolaw@tfb.net>

FROM debian:jessie
LABEL author="Nicola Worthington <nicolaw@tfb.net>"

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get -qq -o Dpkg::Use-Pty=0 update && \
    apt-get -qq -o Dpkg::Use-Pty=0 install -y --no-install-recommends \
    curl \
    libboost-filesystem1.55 \
    libboost-iostreams1.55 \
    libboost-program-options1.55 \
    libboost-system1.55 \
    libboost-thread1.55 \
    libssl1.0.0 \
    libmysqlclient18 \
    mysql-client \
    netcat \
    xml2 \
 < /dev/null > /dev/null \
 && rm -rf /var/lib/apt/lists/*

ENV GM_USER trinity
ENV GM_PASSWORD trinity

# Configurable via INSTALL_PREFIX from the Makefile, and/or using
# --define CMAKE_INSTALL_PREFIX=/your/path with the docker/build/ container,
# (which is also published on Ducker Hub as nicolaw/trinitycore).
ENV install_prefix /opt/trinitycore

# https://trinitycore.atlassian.net/wiki/display/tc/Databases+Installation
# Database import of TDB_*.sql files, astonishingly, requires that the
# current working directory be the same path as the location of both the
# worldserver binary and the TDB_*.sql file.
WORKDIR "${install_prefix}/bin"

# Wait for the database server to come up first.
ADD https://raw.githubusercontent.com/vishnubob/wait-for-it/master/wait-for-it.sh "${install_prefix}/bin/wait-for-it.sh"

# Don't need
# Health checking via the tcadmin client SOAP tool..
#ADD https://raw.githubusercontent.com/neechbear/tcadmin/master/tcadmin "${install_prefix}/bin/tcadmin"

# Add worldserver binary and wrapper, and make executable.
COPY worldserver.sh "${install_prefix}/bin/worldserver.sh"
COPY worldserver "${install_prefix}/bin/worldserver"

COPY etc "${install_prefix}/etc"
RUN chmod +x "${install_prefix}/bin"/*

# Don't need
# Add TDB_*.sql database dump for initial world database initialisation.
# ADD TDB_*.sql "${install_prefix}/bin/"

ENV DEBIAN_FRONTEND newt

ENTRYPOINT ["./worldserver.sh"]

# Don't need
# HEALTHCHECK --interval=30s --timeout=3s --retries=3 --start-period=30s \
#   CMD "${install_prefix}/bin/tcadmin" --soaphost=127.0.0.1 --soapport=7878 \
#     "--soapuser=${GM_USER}" "--soappass=${GM_PASSWORD}" \
#     server info || exit 1

