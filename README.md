IoTnet_DEVKIT
=============

-	[Introducción](#introducción)

-	[Pinout](#pinout)

-	[Ejemplos](#ejemplos)

	-	[Leer ID/PAC](#leer-idpac)

	-	[Utilizar Boton y led](#utilizar-boton-y-led)

Introducción
------------

Proyecto para aprender a utilizar el Devkit de desarrollo de IoTnet, el cual trae un módulo Wisol de conectividad Sigfox y un microprocesador ATmega 328P, por lo que puede programarse mediante el IDE de Arduino.
El Devkit cuenta con 6 GPIOs y 6 entradas analógicas, que tambien pueden configurarse como entradas digitales, un botón y un led que pueden programarse. 
A lo largo de este proyecto, se presentaran algunos ejemplos para demostrar lo fácil que es incluir la conectividad Sigfox a cualquier proyecto. Además, los ejemplos permitiran asociar las terminales de la tarjeta con las utilizadas en Arduino de manera que cualquier sketch utilizado en Arduino Uno puede ser cargado en el Devkit, unicamente cambiando los puertos utilizados a los disponibles en la tarjeta.

Pinout

En la siguiente imagen se muestra el pinout del Devkit, de manera que se puedan asociar las terminales de la tarjeta con las utilizadas en Arduino Uno. 

![devkit_pinout](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/devkit_pinout.jpg?raw=true)

Ejemplos
--------
A continuación se presentan varios ejemplos donde se utilizan las entradas analogicas y digitales, además de los dispositivos ya integrados en el Devkit.  

### Leer ID/PAC

En este ejemplo se utilizará el sketch devkit_info.ino ([Code](Ejemplos/devkit_info/devkit_info.ino)) para leer el ID y el PAC de nuestro Devkit, los cuales son necesarios para registrar el dispositivo en la plataforma de Sigfox y poder ver los mensajes enviados en el backend.

### Utilizar boton y led

En este ejemplo se Utilizará el sketch boton_led.ino ([Code](Ejemplos/boton_led/boton_led.ino)) para utilizar el botón y el led que ya trae el Devkit dentro de un programa. Una vez cargado el programa, al presionar el botón, el Led 6 se encenderá por 2 segundos para despues apagarse.