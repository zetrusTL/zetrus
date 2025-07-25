# Решение задания

1. [Установка ОС](#part-1-установка-ос)  
2. [Создание пользователя](#part-2-создание-пользователя)  
3. [Настройка сети ОС](#part-3-настройка-сети-ос)   
4. [Обновление ОС](#part-4-обновление-ос)  
5. [Использование команды  sudo](#part-5-использование-команды-sudo)  
6. [Установка и настройка службы времени](#part-6-установка-и-настройка-службы-времени)  
7. [Установка и использование текстовых редакторов](#part-7-установка-и-использование-текстовых-редакторов)  
8. [Установка и базовая настройка сервиса SSHD](#part-8-установка-и-базовая-настройка-сервиса-sshd)   
9. [Установка и использование утилит top, htop](#part-9-установка-и-использование-утилит-top-htop)   
10. [Использование утилиты fdisk](#part-10-использование-утилиты-fdisk)   
11. [Использование утилиты df](#part-11-использование-утилиты-df)    
12. [Использование утилиты du](#part-12-использование-утилиты-du)    
13. [Установка и использование утилиты ncdu](#part-13-установка-и-использование-утилиты-ncdu)    
14. [Работа с системными журналами](#part-14-работа-с-системными-журналами)     
15. [Использование планировщика заданий CRON](#part-15-использование-планировщика-заданий-cron)    

## Part 1. Установка ОС

**== Задание ==**

##### Установить **Ubuntu 20.04 Server LTS** без графического интерфейса. (Используем программу для виртуализации - VirtualBox)

- Графический интерфейс должен отсутствовать.

- Узнайте версию Ubuntu, выполнив команду \
`cat /etc/issue.`
- Вставьте скриншот с выводом команды.

**== Решение ==**

- Была установленна программа VirtualBox

- С [официального сайта](http://releases.ubuntu.com/20.04/) был скачан образ для дальнейшей установки



- Результат выполнения команды `cat /etc/issue`:

    ![](screen/.1.png)  

## Part 2. Создание пользователя

**== Задание ==**

##### Создать пользователя, отличного от пользователя, который создавался при установке. Пользователь должен быть добавлен в группу `adm`.

- Вставьте скриншот вызова команды для создания пользователя.
- Новый пользователь должен быть в выводе команды \
`cat /etc/passwd`
- Вставьте скриншот с выводом команды.

**== Решение ==**

- Создадим нового пользователя `newuser` с помощью команды:
    ```
    sudo adduser newuser
    ```

    ![](screen/.2.png) 

- Добавим нового пользователя `newuser` в группу `adm` с помощью команды:
    ```
    sudo usermod -a -G adm newuser
    ```

- Новый пользователь присутствует в выводе команды
`cat /etc/passwd`

    ![](screen/3.png)



## Part 3. Настройка сети ОС

**== Задание ==**

##### Задать название машины вида user-1  
##### Установить временную зону, соответствующую вашему текущему местоположению.  
##### Вывести названия сетевых интерфейсов с помощью консольной команды.
- В отчёте дать объяснение наличию интерфейса lo.  
##### Используя консольную команду получить ip адрес устройства, на котором вы работаете, от DHCP сервера. 
- В отчёте дать расшифровку DHCP.  
##### Определить и вывести на экран внешний ip-адрес шлюза (ip) и внутренний IP-адрес шлюза, он же ip-адрес по умолчанию (gw). 
##### Задать статичные (заданные вручную, а не полученные от DHCP сервера) настройки ip, gw, dns (использовать публичный DNS серверы, например 1.1.1.1 или 8.8.8.8).  
##### Перезагрузить виртуальную машину. Убедиться, что статичные сетевые настройки (ip, gw, dns) соответствуют заданным в предыдущем пункте.  

- В отчёте опишите, что сделали для выполнения всех семи пунктов (можно как текстом, так и скриншотами).
- Успешно пропинговать удаленные хосты 1.1.1.1 и ya.ru и вставить в отчёт скрин с выводом команды. В выводе команды должна быть фраза "0% packet loss".

**== Решение ==**

- С помощью команды `hostname` выясним, что при установке ОС машине было задано задано название `zetruserver`. 

    ![](screen/p3_1.png) 

- Зададим новое название машины: `user-1`; с помощью команды:
    ```
    sudo hostname user-1
    ```
- После выполнения этой команды проверим текущее название командой `hostname`

    ![](screen/p3_2.png)   

- Чтобы после `reboot` машины, выставленное ранее название не сбросилось, воспользуемся командой:
    ```
    sudo hostnamectl set-hostname user-1
    ``` 

- После повторной перезагрузки, наименование машины не изменится.

---

- Чтобы узнать какая временная зона установлена на данный момент можно воспользоваться командой `date`. Данная временная зона не соответствует текущему местоположению:

    ![](screen/p3_3.png)

- Для изменения часового пояса на требуемый Europe/Moscow, используем команду:
    ```
    sudo timedatectl set-timezone Europe/Moscow
    ```

    ![](screen/p3_4.png)

- Повторная проверка текущей временной зоны, выполненная с помощью команды `date`, показала актуальные значения.
---

- Вывести названия сетевых интерфейсов с помощью консольных команд:
    ```
    ip l
    ```
    ```
    ip address
    ```
    ```
    ls /sys/class/net
    ```

    ![](screen/p3_5.png)


---

- Чтобы узнать ip адрес машины, выданный ей DHCP сервером воспользуемся командой:
    ```
    cat /var/log/syslog | grep -i dhcp
    ```

    ![](screen/p3_6.png)
    
- На скриншоте видно, что DHCP выдал компьютеру ip адрес: 10.0.2.15/24

- Также ip адрес машины, выданный ей DHCP сервером, можно узнать с помощью команды: 
    ```
    ip r
    ```
    ![](screen/p3_7.png)

---
- Чтобы определить и вывести на экран внешний ip-адрес шлюза (ip) воспользуемся командой:
    ```
    curl ifconfig.co
    ```
    ![](screen/p3_8.png)


- Чтобы определить и вывести на экран внутренний IP-адрес шлюза, он же ip-адрес по умолчанию (gw), можно воспользоваться командами:
    ```
    ip route
    ```
    ```
    route -n
    ```
    ![](screen/p3_9.png)
    
- Как видно из скриншотов, внешний IP-адрес шлюза: 178.176.167.196; а внутренний: 10.0.2.2

---

- Зададим статичные (заданные вручную, а не полученные от DHCP сервера) настройки ip, gw, dns (используя публичные DNS серверы, например 1.1.1.1 или 8.8.8.8). DHCP автоматически присваивает устройству IP, поэтому сначала необходимо отключить облачную инициализацию. Нужно открыть файл конфигурации `subiquity-disable-cloudinit-networking.cfg` в каталоге `/etc/cloud/cloud.cfg.d/` с помощью команды:
```
sudo vim /etc/cloud/cloud.cfg.d/subiquity-disable-cloudinit-networking.cfg
```

- Необходимо, чтобы было: `config: disabled`

    ![](screen/p3_11.png)

- Откроем файл конфигурации `netplan` в текстовом редакторе `vim` с помощью команды:
    ```
    sudo vim /etc/netplan/00-installer-config.yaml
    ```

    ![](screen/p3_12.png)

- Зададим статические настройки: изменим параметр dhcp4 на значение `false`, в `addresses` укажем статический IP-адрес: `10.0.2.15/24`, и в `gateway4` зададим внутренний IP-адрес `10.0.2.2`. В параметре `addresses` раздела `nameservers` укажем публичные серверы.

    ![](screen/p3_13.png)

- Для применения изменений используем команду:
    ```
    sudo netplan apply
    ```

- Далее перезагрузим виртуальную машину командой `reboot` и проверяем сохранились ли выставленные вручную настройки (проверяем сохранились ли изменения в файле конфигурации). Для этого воспользуемся командой:
    ```
    cat /etc/netplan/00-installer-config.yaml
    ```

    ![](screen/p3_14.png)

- Также, для проверки статического IP-адреса можно использовать команды:
    ```
    ip route show
    ```
    ```
    ifconfig
    ```

    ![](screen/p3_15.png)

- На скриншотах видно, что выставленный вручную статический IP-адрес `10.0.2.15` после перезагрузки остался неизменным.

---

- Пропингуем удаленные хосты 1.1.1.1 и ya.ru с помощью команд:
    ```
    ping 1.1.1.1 -c 3
    ```
    ```
    ping ya.ru -c 3
    ```
    ![](screen/p3_16.png)

- На скриншоте видно, что выводе команды присутвствует фраза `0% packet loss`, это свидетельствует о том, что компьютер получил ответ от всех отправленных на указанные сервера пакетов данных.


## Part 4. Обновление ОС

**== Задание ==**

##### Обновить системные пакеты до последней на момент выполнения задания версии.  

- После обновления системных пакетов, если ввести команду обновления повторно, должно появится сообщение, что обновления отсутствуют.
- Вставить скриншот с этим сообщением в отчёт.

**== Решение ==**

- Для обновления индекса пакетов или списка пакетов, воспользуемся командой:
    ```
    sudo apt update
    ```
- Обновим системные пакеты до последней, на момент выполнения задания, версии, используя команду:
    ```
    sudo apt full-upgrade
    ```
    ![](screen/p4_1.png)

- После обновления системных пакетов видим, что при повторном введении двух последних команд получены сообщения об отсутствии новых обновлений
    ![](screen/p4_2.png)

## Part 5. Использование команды **sudo**

**== Задание ==**

##### Разрешить пользователю, созданному в [Part 2](#part-2-создание-пользователя), выполнять команду sudo.

- В отчёте объяснить *истинное* назначение команды sudo (про то, что это слово - "волшебное", писать не стоит).  
- Поменять hostname ОС от имени пользователя, созданного в пункте [Part 2](#part-2-создание-пользователя) (используя sudo).
- Вставить скрин с изменённым hostname в отчёт.

**== Решение ==**

- Разрешим пользователю, созданному в [Part 2](#part-2-создание-пользователя), выполнять команду sudo. Для этого необходимо добавить пользователя `newuser` в группу `sudo`. Воспользуемся командой:
    ```
    sudo usermod -a -G sudo newuser
    ```
- Проверим к каким группам принадлежит пользователь `newuser` с помощью команды:
    ```
    groups newuser
    ```

    ![](screen/p5_1.png)

- На скриншоте видно, что пользователь был добавлен в группу `sudo`. Это дает ему возможность выполнять команду `sudo`.


- Поменяем hostname ОС от имени пользователя, созданного в пункте [Part 2](#part-2-создание-пользователя) (используя sudo). Для этого необходимо сменить текущего пользователя `zetrus` на ранее созданного `newuser` с помощью команды:
    ```
    su newuser
    ```

    ![](screen/p5_2.png)

- Чтобы узнать текущее имя хоста воспользуемся командой:
    ```
    hostnamectl
    ```
- Изменим имя хоста с `user-1` на `user-2` с помощью команды:
    ```
    sudo hostnamectl set-hostname user-2
    ```
- Проверим изменения командой:
    ```
    hostname
    ```

    ![](screen/p5_3.png)

- Выполним перезагрузку машины командой `reboot` и проверим сохранность изменений:

    ![](screenp5_4.png)


## Part 6. Установка и настройка службы времени

**== Задание ==**

##### Настроить службу автоматической синхронизации времени.  

- Вывести время, часового пояса, в котором вы сейчас находитесь.
- Вывод следующей команды должен содержать `NTPSynchronized=yes`: \
  `timedatectl show`
- Вставить скрины с корректным временем и выводом команды в отчёт.

**== Решение ==**

- С помощью команды `date` выведем текущее время часового пояса, в котором мы находимся.

- Для вывода настроек часового пояса, используем команду:
    ```
    timedatectl show
    ```

    ![](screen/p6_1.png)


## Part 7. Установка и использование текстовых редакторов 

**== Задание ==**

##### Установить текстовые редакторы **VIM** (+ любые два по желанию **NANO**, **MCEDIT**, **JOE** и т.д.)  
##### Используя каждый из трех выбранных редакторов, создайте файл *test_X.txt*, где X -- название редактора, в котором создан файл. Напишите в нём свой никнейм, закройте файл с сохранением изменений.  
- В отчёт вставьте скриншоты:
  - Из каждого редактора с содержимым файла перед закрытием.
- В отчёте укажите, что сделали для выхода с сохранением изменений.
##### Используя каждый из трех выбранных редакторов, откройте файл на редактирование, отредактируйте файл, заменив никнейм на строку "21 School 21", закройте файл без сохранения изменений.
- В отчёт вставьте скриншоты:
    - Из каждого редактора с содержимым файла после редактирования.
- В отчёте укажите, что сделали для выхода без сохранения изменений.
##### Используя каждый из трех выбранных редакторов, отредактируйте файл ещё раз (по аналогии с предыдущим пунктом), а затем освойте функции поиска по содержимому файла (слово) и замены слова на любое другое.
- В отчёт вставьте скриншоты:
    - Из каждого редактора с результатами поиска слова.
    - Из каждого редактора с командами, введёнными для замены слова на другое.

**== Решение ==**

- Выполним установку текстовых редакторов командами:
    ```
    sudo apt install vim
    ```
    ```
    sudo apt install nano
    ```
    ```
    sudo apt install mcedit
    ```
---
### Запись никнейма в файлы и закрытие с сохранением

- VIM. Запишем никнейм `zetrus` , перейдя в режим редактирования нажатием клавиши `i`:

    ![](screen/p7_1.png)

    - Для выхода с сохранением изменений нужно нажать `ESC`, затем написать `:wq`, что означает write and quit.

- NANO. Запишем никнейм `zetrus`:

    ![](screen/p7_2.png)

    - Для выхода с сохранением изменений нужно нажать `Ctrl+S` и затем `Ctrl+X`.

- MCEDIT. Запишем никнейм `zetrus`:

    ![](screen/p7_3.png)

    - Для выхода с сохранением изменений нужно нажать `F10` и выбрать `Yes`

    ![](screen/p7_4.png)

---
### Запись "21 School 21" в файлы с выходом без сохранения

- VIM. Запишем "21 School 21":

    ![](screen/p7_5.png)

    - Для выхода без сохранения нужно нажать `ESC`, затем написать `:q!`. Проверим, что изменения не сохранились:

    ![](screen/p7_6.png)

- NANO. Запишем "21 School 21":

    ![](screen/p7_7.png)

    - Для выхода без сохранения изменений нужно нажать `Ctrl+X` и подтвердить нажатием на `N`. Проверим, что изменения не сохранились:

    ![](screen/p7_8.png)

- MCEDIT. Запишем "21 School 21":

    ![](screen/p7_9.png)

    - Для выхода без сохранения изменений нужно нажать `F10` и выбрать `No`

    ![](screen/p7_10.png)

    - Проверим, что изменения не сохранились:

    ![](screen/p7_11.png)

---


### Поиск по слову в файлах
- Внесем изменения с предыдущего пункта (запишем в файлы "21 School 21") и сохраним их.

- **VIM**

    - Поиск:
    `ESC + /<слово_для_поиска>`
    
    ![](screen/p7_12.png)

    - Замена:
    `:s/<заменяемое>/<заменитель>`

    ![](screen/p7_13.png)

- **NANO**

    - Поиск:
    `Ctrl + W`
    
    ![](screen/p7_14.png)

    - Замена:
    `Ctrl + \`

    ![](screen/p7_15.png)

    - Вводим слово для замены:

    ![](screen/p7_16.png)

    - Применяем замену:

    ![](screen/p7_17.png)

- **MCEDIT**

    - Поиск:
    `F7`
    
    ![](screen/p7_18.png)

    - Вводим и подтверждаем слово для поиска:

    ![](screen/p7_19.png)

    - Замена:
    `F4`

    ![](screen/p7_20.png)

    - Вводим и подтверждаем слово для замены:

    ![](screen/p7_21.png)


## Part 8. Установка и базовая настройка сервиса **SSHD**

**== Задание ==**

##### Установить службу SSHd.  
##### Добавить автостарт службы при загрузке системы.  
##### Перенастроить службу SSHd на порт 2022.  
##### Используя команду ps, показать наличие процесса sshd. Для этого к команде нужно подобрать ключи.
- В отчёте объяснить значение команды и каждого ключа в ней.
##### Перезагрузить систему.
- В отчёте опишите, что сделали для выполнения всех пяти пунктов (можно как текстом, так и скриншотами).
- Вывод команды netstat -tan должен содержать  \
`tcp 0 0 0.0.0.0:2022 0.0.0.0:* LISTEN`  \
(если команды netstat нет, то ее нужно установить)
- Скрин с выводом команды вставить в отчёт.
- В отчёте объяснить значение ключей -tan, значение каждого столбца вывода, значение 0.0.0.0.

**== Решение ==**

- Установим службу SSHd с помощью команды:
    ```
    sudo apt install openssh-server
    ```

- Узнаем состояние SSHd службы, воспользовавшись командой:
    ```
    sudo systemctl status ssh
    ```

    ![](screen/p8_1.png)

- Как видно на скриншоте, автостарт SSHd службы добавлен автоматически при загрузке. Чтобы включить автостарт можно воспользоваться командой `sudo systemctl enable ssh`, для выключения автостарта команда `sudo systemctl disable ssh`.

- Для перенастройки службы SSHd на порт 2022 откроем файл `sshd_config` с помощью команды:
    ```
    sudo nano /etc/ssh/sshd_config
    ```
- Изменим значение параметра `Port` с 22 на 2022

    ![](screen/p8_2.png)

- Чтобы изменения в конфигурации сохранились, перезапустим сервер OpenSSH, используя следующую команду:
    ```
    sudo systemctl restart ssh 
    ```

- Проверим состояние SSHd службы после изменения порта командой `sudo systemctl status ssh`

    ![](screen/p8_3.png)

    - На скриншоте видно, что порт изменен.

- Настроим брандмауэр, так как мы изменили SSH-порт по умолчанию на 2022. 
    - Заменим “ssh” новым номером порта: 
    `sudo ufw allow 2022/tcp`

    ![](screen/p8_4.png)

- Покажем наличие процесса sshd, используя команду:
    ```
    ps aux | grep -i ssh
    ```

    ![](screen/p8_5.png)

    - > **ps** - утилита для просмотра списка процессов в Linux. <br> Параметр `-a` - выбрать все процессы всех пользователей, кроме фоновых. 
    <br> Параметр `-u` обозначает ориентированный на пользователя формат, который предоставляет подробную информацию о процессах. 
    <br> Параметр `-x` указывает `ps` перечислить процессы без управляющего терминала.
    <br> В основном это процессы, которые запускаются во время загрузки и работают в фоновом режиме.
    <br> `grep -i ssh` - выводит только те строчки, где есть ssh с игнорированием регистра за счет `-i`.
    <br> Символ `|` перенаправляет вывод команды `ps aux` на ввод `grep -i ssh`.

- Выполним перезагрузку машины командой `reboot` и выполним команду:
    ```
    netstat -tan
    ```

    ![](screen/p8_6.png)

    - Как видно на скриншоте, вывод команды содержит `tcp 0 0 0.0.0.0:2022 0.0.0.0:* LISTEN`, что соответствует требованию задания.

    - >`netstat -tan`\
    \
    Команда `netstat` показывает статистику приема и отправки пакетов, а также информацию об ошибках приема и отправки.\
    \
    `-a` - Вывод всех активных подключений TCP и прослушиваемых компьютером портов TCP и UDP.\
    `-n` - Вывод активных подключений TCP с отображением адресов и номеров портов в числовом формате без попыток определения имен.\
    Тогда, если `netstat -na` - просмотр всех открытых протоколов, то `netstat -tan` - просмотр всех открытых ТСР-протоколов.\
    \
    При вызове команды в терминал выводится таблица, столбцы которой имеют следующие значения:\
    а) `Proto` - сетевой протокол (tcp, udp);\
    б) `Recv-Q` - количество байтов, помещённых в буфер приёма TCP/IP, но не переданных приложению. Если это число высокое, то нужно проверить работоспособность приложения, которое работает с данным портом.\
    в) `Send-Q` — количество байтов, помещённых в буфер отправки TCP/IP, но не отправленных, или отправленных, но не подтверждённых. Высокое значение может быть связано с перегрузкой сети сервера.\
    г) `Local Address` — локальный адрес сервера. В обычных соединениях, это адрес сервера на который пришло соединение. В прослушиваемых портах (LISTEN) — это диапазон адресов. Так 0.0.0.0:port — значит подключаться можно ко всем адресам сервера, а 192.168.0.35:port — значит подключаться можно только к этому адресу сервера.\
    д) `Foreign Address` — адрес второй стороны. В обычных соединениях, это адрес с которого пришло соединение. В прослушиваемых портах (LISTEN) — это диапазон адресов. Так 0.0.0.0:* — значит подключаться можно с любых адресов и с любых портов, а например 192.168.0.50:* — значит подключаться можно только с этого адреса и с любых портов.\
    е) `State` — состояние подключения, или прослушивания.


## Part 9. Установка и использование утилит **top**, **htop**

**== Задание ==**

##### Установить и запустить утилиты top и htop.  

- По выводу команды top определить и написать в отчёте:
  - uptime
  - количество авторизованных пользователей
  - общую загрузку системы
  - общее количество процессов
  - загрузку cpu
  - загрузку памяти
  - pid процесса занимающего больше всего памяти
  - pid процесса, занимающего больше всего процессорного времени

- В отчёт вставить скрин с выводом команды htop:
  - отсортированному по PID, PERCENT_CPU, PERCENT_MEM, TIME
  - отфильтрованному для процесса sshd
  - с процессом syslog, найденным, используя поиск 
  - с добавленным выводом hostname, clock и uptime  

**== Решение ==**

- Команда `top` выводит на экран:

    ![](screen/p9_1.png)

  - uptime - 3 минуты;
  - количество авторизованных пользователей - 1;
  - общую загрузку системы - 0.00;
  - общее количество процессов - 108;
  - загрузка cpu - 0.0 %;
  - загрузка памяти - 901.3 из 3920.2;
  - pid процесса занимающего больше всего памяти - 1;
  - pid процесса, занимающего больше всего процессорного времени - 1 <br>

- **htop** :
    - Вывод команды без сортировки

    ![](screen/p9_2.png)

    - Для сортировки в `htop` нужно нажать `F6` и выбрать параметр сортировки.
    - `htop` отсортированный по `PID`

    ![](screen/p9_3.png)

    - `htop` отсортированный по `PERCENT_CPU`

    ![](screen/p9_4.png)

    - `htop` отсортированный по `PERCENT_MEM`

    ![](screen/p9_5.png)

    - `htop` отсортированный по `TIME`

    ![](screen/p9_6.png)

    - Для использования фильтров в `htop` нужно нажать `F4` и выбрать параметр фильтрации.
    - htop, отфильтрованный для процесса SSHd

    ![](screen/p9_7.png)

    - Для использования поиска в `htop` нужно нажать `F3` и ввести объект поиска. <br>
    `htop` с процессом `syslog`, найденным, используя поиск:

    ![](screen/p9_8.png)

    - Для добавления отображения дополнительных параметров в `htop`, необходимо нажать `F2` и добавить требуемые параметры. `htop` с добавленным выводом hostname, clock и uptime

    ![](screen/p9_9.png)


## Part 10. Использование утилиты **fdisk**

**== Задание ==**

##### Запустить команду fdisk -l.

- В отчёте написать название жесткого диска, его размер и количество секторов, а также размер swap.

**== Решение ==**

##### Запустить команду fdisk -l.

- Выполним команду:
    ```
    fdisk -l
    ```
    ![](screen/p10_1.png)

    - Название жесткого диска: VBOX HARDDISK (/dev/sda);
    - Размер диска: 25 Гигабайт;
    - Количество секторов: 52428800;

- Чтобы узнать размер `swap` выполним команду:
    ```
    free -h
    ```
    ![](screen/p10_2.png)

- Второй способ узнать размер `swap`:
    ```
    swapon -s
    ```
    ![](screen/p10_3.png)

- Выяснилось, что:
    - Размер swap: 2345980 килобайта (= 2.25 Гб);

## Part 11. Использование утилиты **df** 

**== Задание ==**

##### Запустить команду df.  
- В отчёте написать для корневого раздела (/):
  - размер раздела
  - размер занятого пространства
  - размер свободного пространства
  - процент использования
- Определить и написать в отчёт единицу измерения в выводе.  

##### Запустить команду df -Th.
- В отчёте написать для корневого раздела (/):
    - размер раздела
    - размер занятого пространства
    - размер свободного пространства
    - процент использования
- Определить и написать в отчёт тип файловой системы для раздела.

**== Решение ==**
- Выполним команду:
    ```
    df /
    ```

    ![](screen/p11_1.png)

    >Для корневого раздела (/):\
        - Размер раздела: 11758760;\
        - Размер занятого пространства: 6339228;\
        - Размер свободного пространства: 4800424;\
        - Процент использования: 57 %;\
        Единицы измерения при выводе: Килобайты.

- Выполним команду:
    ```
    df -Th
    ```

    ![](screen/p11_2.png)

    >Для корневого раздела (/):\
        - Размер раздела: 12;\
        - Размер занятого пространства: 6.1;\
        - Размер свободного пространства: 4.6;\
        - Процент использования: 57 %;\
        Единицы измерения при вывде: Гигабайты.

    Тип файловой системы: `Ext4` - журналируемая файловая система, используемая в ОС на ядре Linux. Основана на файловой системе Ext3, но отличается тем, что в ней представлен механизм записи файлов в непрерывные участки блоков (екстенты), уменьшающий фрагментацию и повышающий производительность. В ней есть журналирование, то есть в ней предусмотрена запись некоторых данных, позволяющих восстановить файловую систему при сбоях в работе компьютера.


## Part 12. Использование утилиты **du**

**== Задание ==**

##### Запустить команду du.
##### Вывести размер папок /home, /var, /var/log (в байтах, в человекочитаемом виде)
##### Вывести размер всего содержимого в /var/log (не общее, а каждого вложенного элемента, используя *)

- В отчёт вставить скрины с выводом всех использованных команд.

**== Решение ==**
- Выполним команду:
    ```
    du
    ```

    ![](screen/p12_1.png)

- Вывод размера папки /home в байтах и в человекочитаемом виде командами:
    ```
    sudo du -s /home/
    ```
    ```
    sudo du -sh /home/
    ```

    ![](screen/p12_2.png)

- Вывод размера папки /var в байтах и в человекочитаемом виде командами:
    ```
    sudo du -s /var/
    ```
    ```
    sudo du -sh /var/
    ```

    ![](screen/p12_3.png)

- Вывод размера папки /var/log в байтах и в человекочитаемом виде командами:
    ```
    sudo du -s /var/log/
    ```
    ```
    sudo du -sh /var/log/
    ```

    ![](screen/p12_4.png)

- Вывод размера всего содержимого папки /var/log в байтах и в человекочитаемом виде командами:
    ```
    sudo du /var/log/
    ```
    ```
    sudo du -h /var/log/
    ```

    ![](screen/p12_5.png)

- Вывод размера всего содержимого папки (каждого вложенного элемента) /var/log с использованием `*` командой:
    ```
    sudo du /var/log/* | less
    ```

    ![](screen/p12_6.png)


## Part 13. Установка и использование утилиты **ncdu**

**== Задание ==**

##### Установить утилиту ncdu.
##### Вывести размер папок /home, /var, /var/log.

- Размеры должны примерно совпадать с полученными в [Part 12](#part-12-использование-утилиты-du).

- В отчёт вставить скрины с выводом использованных команд.

**== Решение ==**

- Установим утилиту `ncdu` командой:
    ```
    sudo apt install ncdu
    ```
    ![](screen/p13_1.png)

- Выведем размер папки `/home`:

    ![](screen/p13_2.png)

- Выведем размер папки `/var`:

    ![](screen/p13_3.png)

- Выведем размер папки `/var/log`:

    ![](screen/p13_4.png)

- На скриншотах видно, размеры папок примерно совпадают с полученными в `части 12` [Part 12] задания.


## Part 14. Работа с системными журналами

**== Задание ==**

##### Открыть для просмотра:
##### 1. /var/log/dmesg
##### 2. /var/log/syslog
##### 3. /var/log/auth.log  

- Написать в отчёте время последней успешной авторизации, имя пользователя и метод входа в систему.
- Перезапустить службу SSHd.
- Вставить в отчёт скрин с сообщением о рестарте службы (искать в логах).

**== Решение ==**

- `/var/log/dmesg` — драйвера устройств. Содержит сообщения, полученные от ядра. Регистрирует много сообщений еще на этапе загрузки, в них отображается информация об аппаратных устройствах, которые инициализируются в процессе загрузки. Одноименной командой можно просмотреть вывод содержимого файла. Размер журнала ограничен, когда файл достигнет своего предела, старые сообщения будут перезаписаны более новыми. Откроем для просмотра файл `/var/log/dmesg` с помощью команды:
    ```
    less /var/log/dmesg
    ```

    ![](screen/p14_1.png)

- `/var/log/syslog` — содержит глобальный системный журнал, в котором пишутся сообщения с момента запуска системы, от ядра Linux, различных служб, обнаруженных устройствах, сетевых интерфейсов и много другого. Откроем для просмотра файл `/var/log/syslog` с помощью команды:
    ```
    less /var/log/syslog
    ```

    ![](screen/p14_2.png)

- `/var/log/auth.log` — информация об авторизации пользователей, включая удачные и неудачные попытки входа в систему, а также задействованные механизмы аутентификации. Откроем для просмотра файл `/var/log/auth.log` с помощью команды:
    ```
    less /var/log/auth.log
    ```

    ![](screen/p14_3.png)

- Время последней успешной авторизации: may 18 09:37:33
- Имя пользователя: user 2
- Метод входа в систему: by uid = 0 (User Identifier). Суперпользователь всегда должен иметь UID, равный нулю (0).

- Перезапустим службу SSHd с помощью команды:
    ```
    sudo systemctl restart ssh
    ```
- В журнале найдем сообщение о перезапуске службы:

    ![](screen/p14_4.png)

## Part 15. Использование планировщика заданий **CRON**

**== Задание ==**

##### Используя планировщик заданий, запустите команду uptime через каждые 2 минуты.
- Найти в системных журналах строчки (минимум две в заданном временном диапазоне) о выполнении.
- Вывести на экран список текущих заданий для CRON.
- Вставить в отчёт скрины со строчками о выполнении и списком текущих задач.

##### Удалите все задания из планировщика заданий.
- В отчёт вставьте скрин со списком текущих заданий для CRON.

**== Решение ==**

- Запустим команду `uptime` через каждые 2 минуты. Для этого откроем планировщик заданий `CRON` в текстовом редакторе `nano` с помощью команды:
```
crontab -e
```
- Добавим строчку `*/2 * * * * uptime`

    ![](screen/p15_1.png)

- После чего сохраним и закроем файл.
- Найдем в системных журналах строчки о выполнении `uptime`. Для этого воспользуемся командой:
    ```
    less /var/log/syslog | grep CRON
    ```

    ![](screen/p15_2.png)

- Выведем на экран список текущих заданий для `CRON` с помощью команды:
    ```
    crontab -l
    ```

    ![](screen/p15_3.png)

- Удалим все задания из планировщика заданий `CRON` с помощью команды:
    ```
    crontab -r
    ```
- Проверим список текщих задач после удаления командой `crontab -l`:

    ![](screen/p15_4.png)