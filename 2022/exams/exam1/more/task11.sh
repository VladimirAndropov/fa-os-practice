#!/bin/bash
: '
Написать скрипт, которые выведет на экран все файлы,
размер которых больше 50 Мб в переданной скрипту директории
'

# Если кол-во переданных параметров не 1
if [[ $(($#)) -ne 1 ]] ; then
    echo "Ошибка: Некорректное кол-во переданных аргументов" >&2
    exit 1
fi

# Директория, переданная в параметрах
dir_path=$1

# Если директория есть
if [ -d "$dir_path" ] 
then
    echo "Директория $dir_path существует"
# Если ее нет
else
    echo "Директории $dir_path НЕ существует"  >&2
    exit 1
fi

find $dir_path -type f -size +50M 2>/dev/null | while read line 
do
    echo $line
done

echo "Успешно выполнили скрипт"