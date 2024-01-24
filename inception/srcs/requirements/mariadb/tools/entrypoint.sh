#!/bin/bash

# Iniciando o mysqld_safe em segundo plano
mysqld_safe --skip-syslog &

# Aguardando até que o servidor MariaDB esteja pronto para aceitar conexões
while ! mysqladmin ping -hlocalhost --silent; do
    sleep 1
done

# Verificando se o banco de dados já existe
if ! mysql -e "USE $MYSQL_DATABASE;"; then
    # Criando o banco de dados, usuário e concedendo privilégios
    mysql -e "CREATE DATABASE $MYSQL_DATABASE;"
    mysql -e "CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_USER_PASSWORD';"
    mysql -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_USER_PASSWORD';"
    mysql -e "ALTER USER '$MYSQL_ROOT'@'localhost' IDENTIFIED BY '123';"
    mysql -e "FLUSH PRIVILEGES;"

    echo "Database created."
else
    echo "Database '$MYSQL_DATABASE' has already been created."
fi

# Alterando permissões dentro do script
chmod 755 /var/www/html
chown -R www-data:www-data /var/www/html

# Desligando o servidor MariaDB
mysqladmin shutdown

# Aguardando até que o servidor seja completamente encerrado
while mysqladmin ping -hlocalhost --silent; do
    sleep 1
done

# Executando o servidor MariaDB novamente
exec mariadbd