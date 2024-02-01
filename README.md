
# OS Сетевые системы и приложения

# Страничка семинаров ПИ22-1 ПИ22-2 ПИ22-3 ПИ22-4




Основные темы практики:
---

1. [ОСНОВЫ LINUX](lx/README.md)

~~2. [АДМИНИСТРИРОВАНИЕ LINUX](do/README.md)~~
 
~~3. [СЕТЕВОЕ ПРОГРАММИРОВАНИЕ](np/README.md)~~

4. [Системное программирование в Файловой системе unix](fs/README.md)  [(Лекции в формате html)](https://vladimirandropov.github.io/fa-os-practice/)

5. [Операционная система х86 с нуля](https://github.com/VladimirAndropov/fa-os-practice-yabloko)

6. [Операционная система risc-V с нуля](https://github.com/VladimirAndropov/xv6-riscv)



Материалы курса
---
Вы можете познакомиться со всеми материалами курса - презентациями к лекциям, методических рекомендациям к лабораторным работам на [github](http://koroteev.site/os/).

- Плейлист с видео по данному курсу досупен на [YouTube](https://www.youtube.com/playlist?list=PLhgyvraU60gU8OAhjtcipU_sO7UYvkQl9). 


# Практика семинара


- Создание виртуальной машины
  - Установка Linux в виртуальную машину 
[8.1-8.3]
- Основы командной строки
  - Основные команды терминала
  - Основные команды манипуляции с файлами
  - Работа с жесткими и символическими ссылками
 [8.1-8.3]
- Использование удаленного доступа
  - Подключение к удаленному хосту через SSH
  - Работа с программой tmux 
[8.1-8.3]
- Права и пользователи
  - Команды добавления, удаления пользователей, изменение пароля
  - Просмотр, модификация прав доступа к файлам и папкам 
[8.1-8.3]
- Процессы и пакеты
  - Основные операции с процессами
  - Команды управления пакетами
 [8.1-8.3]
- Управление загрузкой Linux
  - Команды управления службами
  - Создание собственной службы 
[8.1-8.3]
- Файловые системы
  - Основные команды управления файловыми системами и просмотра информации о дисках 
[8.1-8.3]
- Основы скриптов на bash
  - Создание сценарных скриптов
  - Освоение синтаксиса языка bash 
[8.1-8.3]
- Средства обработки текста
  - Основные команды терминала по обработке текстовой информации
  - Потоковые текстовые редакторы
  - Написание парсеров текстовых файлов на bash 
[8.1-8.3]
- Настройка сети в Linux
  - Команды диагностики сетевого подключения
  - Настройка виртуальной сети в VirtualBox 
[8.1-8.3]
- Средства ОС в Python
  - Работа с файловой системой в языке программирования Python. Программное выполнение консольных команд. [8.1-8.3]
- Системы контроля версий
  - Использование git для совместной разработки
  - Синхронизация проектов через GitHub
 [8.1-8.3]
- Использование сокетов
  - Создание простейшего клиент-серверного приложения [8.1-8.3]
- Асинхронное программирование
  - Использование многопоточности для серверного приложения
  - Использование многопроцессности для ускорения вычислений
  - Использование библиотеки асинхронного программирования 
[8.1-8.3]
- Веб-сервер
  - Установка и настройка веб-сервера в Linux
  - Создание простейшего веб-сервера 
[8.1-8.3]
- Развертывание сетевых приложений
  - Создание и развертывание сетевого приложения на удаленном сервере 
[8.1-8.3]

# Примерные задания для подготовки к зачету 
1. Сценарий должен вывести (на stdout) все числа, делящиеся на 12, в диапазоне от первого параметра до последнего. Если параметры заданы некорректно, скрипт должен вывести сообщение.
2. Сценарий должен имитировать работу лототрона -- извлекать 5 случайных неповторяющихся чисел в диапазоне 1–50. Сценарий должен предусматривать как вывод на stdout, так и запись чисел в файл, кроме того, вместе с числами должны выводиться дата и время генерации данного набора.
3. Напишите сценарий, который находил бы корни "квадратного " уравнения, вида: Ax^2 + Bx + C = 0. Сценарий должен получать коэффициенты уравнения A, B и C, как аргументы командной строки, и выводить корни. Если корней нет, вывод должен быть пустым.
4. Написать скрипт, который выведет всех потомков процесса по его PID. 
5. Напишите скрипт, который и считает кол-во измененных в течение последних 3 дней файлов из каталога, переданного как параметр и выводит на экран.
6. Написать скрипт, который выведет информацию о топ10 процессов по потреблению оперативной памяти.
7. Написать скрипт, который выведет все файлы в домашней директории пользователя, измененные за последнюю неделю.
8. Напишите сценарий, который принимает как аргументы список программ и устанавливает их в текущую систему. Сделайте возможность передать список программ через текстовый файл.
9. Напишите скрипт, выводящий сообщение в случае, если в файле /etc/hosts есть записи, относящиеся к адресам отличным от 127.0.0.1.
10. Разработать сценарий, который ведёт в файле /tmp/run.log журнал запусков. При каждом запуске сценария в конец журнала должна добавляться строка с датой и временем запуска сценария, в стандартный вывод - фраза "Hello", в stderr - количество предыдущих запусков программы. Убедиться в правильности работы программы и выводе различных сообщений в различные потоки вывода.

# Примерные задания для подготовки к экзамену
1. Напишите программу, которая создает нить. Родительская и вновь созданная нити должны распечатать десять строк текста. [README](exam/1.md)
2. Напишите простой эхо-сервер, использующий неблокирующие сокеты и клиент к нему.[README](18sem-fs/socket_example.c)
3. Напишите простой многопоточный загрузчик URL. Список URL скрипт принимает как аргументы командной строки.[README](2017/20-socket/README.md)
4. Реализуйте простой HTTP-клиент. Он принимает один параметр командной строки - URL. Клиент делает запрос по указанному URL и выдает тело ответа на терминал как текст.
5. Напишите программу, которая вычисляет число Пи при помощи ряда Эйлера. Количество потоков программы должно определяться параметром командной строки. 
6. Дана функция calculate(x, y). Напишите программу, которая создает пул из 5 процессов и распределяет в этом пуле вычисление функции на промежутке х от 0 до 1 с шагом 0,1. у равняется 2 всегда.[README](2017/24-stdthread/README.md)
7. Напишите программу, которая проверяет все числа от 0 на простоту и выводит простые числа на экран по мере нахождения. Числа должны проверяться в различных потоках (или процессах, по выбору студента) Программа должна работать до тех пор, пока ее не остановит пользователь.
8. Напишите программу, которая обходит все файлы в директории, переданной ей как параметр и выводит на экран имена тех, чей размер задан как второй параметр. Реализовать рекурсивный обход поддиректорий.[README](12sem-fs/README.md)
9. Напишите программу, которая выводит на экран список номеров открытых портов на данной машине. Использовать команду netstat.
10. Напишите программу, которая копирует файл с удаленного хоста в текущую папку по SSH. Имя файла и адрес хоста принимать как параметры.


# Пример экзаменационного билета
Экзаменационный билет №

1. Понятие потокобезопасности. Причины, проблематика, способы обеспечения. (20 баллов)
2. Доступ к общим ресурсам в многопоточной программе. Механизмы блокировки ресурсов модуля threading. (20 баллов)
3. Напишите программу, которая создает четыре нити, исполняющие одну и ту же функцию. Эта функция должна распечатать последовательность текстовых строк, переданных как параметр. Каждая из созданных нитей должна распечатать различные последовательности строк. (20 баллов)


## Источники информации

Основная литература

* [Дорожная карта DevOps-разработчика](https://roadmap.sh/devops)
* Э. Таненбаум. Современные операционные системы
* М. Кофлер. Linux. Полное руководство
* В. Олифер. Компьютерные сети. Принципы, технологии, протоколы
* Е. Немет. Unix и Linux.Руководство системного администратора.
* [Pro git](https://git-scm.com/book/ru/v2)

Дополнительная литература

* Б.Уорд. Внутреннее устройство Linux
* Д. Н. Колисниченко. Командная строка Linux
* У. Шоттс. Командная строка Linux. Полное руководство
* Д. Тейлор. Сценарии командной оболочки. Linux, OS X и UNIX
* Д.Н. Колисниченко. Linux. От новичка к профессионалу
* Э. Свейгард. Автоматизация рутинных задач с помощью Python
* Э. Таненбаум. Компьютерные сети
* [М.В. Коротеев. Учебное пособие по дисциплине “Сетевые системы и приложения” - 2023.](http://elib.fa.ru/rbook/books137316.pdf/view) 

Видео-ресурсы

*   [Канал о Linux и DevOps](https://www.youtube.com/channel/UCvA_wgsX6eFAOXI8Rbg_WiQ)
*   [Linux Foundation Certified System Administrator](https://www.youtube.com/playlist?list=PL1eM6UUA7VFycj34L1zgaCBWhh3Ci9Cp0)
*   [Системное администрирование Linux](https://www.youtube.com/playlist?list=PL1eM6UUA7VFysNtA0qflCDxpDiZEt7Bep)
*   [The Linux Basics Course: Beginner to Sysadmin, Step by Step](https://www.youtube.com/playlist?list=PLtK75qxsQaMLZSo7KL-PmiRarU7hrpnwK)

## Программное обеспечение

*   [Oracle VM VirtualBox](https://www.virtualbox.org/)
*   [Дистрибутив Linux Mint](https://www.linuxmint.com/download.php)
*   [Python 3 Anaconda](https://www.anaconda.com/products/individual)
*   [Git](https://git-scm.com/)
*   Google Chrome



Для студентов Финансового университета
---

[Балльно-рейтинговая система](https://docs.google.com/document/d/1ALyuwC3muqUuM-VVbydrGWGIkD8yCtcW0P0N0zhCuCU/edit?usp=sharing)

[Программа зачета](https://docs.google.com/document/d/1eckYbhcpdvc8KKB4o5a1sQbBS_ndc37KKC0c9wI9Fp0/edit?usp=sharing)

[Пробное тестирование к зачету](https://campus.fa.ru/mod/quiz/view.php?id=653468)

[Зачетное тестирование](https://campus.fa.ru/mod/quiz/view.php?id=653469)

[Программа экзамена](https://docs.google.com/document/d/1VD4kMGFQRyyyYlSJUaBCFDOJ3exduoo9P3q4KGglrfM/edit?usp=sharing)

[Инструкция по работе в лаборатории](https://docs.google.com/document/d/1dH6XGbeIX3u_xf12GhgpQwCfwg5Cf5jTMX82WkrdhEk/edit?usp=sharing)

[Методические указания по составлению тестовых заданий](https://docs.google.com/document/d/1zeSRD8l_7VCUbvPoKeHvHijRWHn5z4d5Vfbh0T2kLWE/edit?usp=sharing)