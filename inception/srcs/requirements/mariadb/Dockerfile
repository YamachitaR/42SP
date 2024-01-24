# Usando a imagem base Debian Bullseye
FROM debian:bullseye

# Atualizando e instalando o servidor MariaDB
RUN apt update -y && apt upgrade -y && \
    apt install mariadb-server -y

# Criando diretórios e ajustando permissões
RUN mkdir -p /var/lib/mysql /var/run/mysqld && \
    chown -R mysql:mysql /var/lib/mysql /var/run/mysqld && \
    chmod 755 /var/run/mysqld

# Copiando arquivos de configuração e scripts

# Por padrão o MariaDB está vinculado ao localhost, não permite conexões remotas
# Esta configuração permite conexões remotas de qualquer host (no nosso caso, outros containers)
RUN echo "[mysqld] \n\
skip-networking=0 \n\
skip-bind-address" >> /etc/mysql/my.cnf


# Copiando o arquivo do entrypoint (esta no host) para Docker
COPY ./tools/entrypoint.sh entrypoint.sh

# Ajustando permissões dos arquivos copiados
RUN    chmod +x entrypoint.sh

# Definindo o usuário para mysql
USER mysql

# Expondo a porta 3306 para conexões externas
EXPOSE 3306

# Definindo o ponto de entrada do contêiner como o script entrypoint.sh
ENTRYPOINT [ "/entrypoint.sh" ]