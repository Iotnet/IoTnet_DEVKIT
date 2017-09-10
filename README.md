## IoTnet_DEVKIT ##

-	[Introducción](#introducción)

-	[Pinout](#pinout)

## Introducción ##

Proyecto para aprender a utilizar el Devkit de desarrollo de IoTnet, el cual trae un módulo Wisol de conectividad Sigfox y un microprocesador ATmega 328P, por lo que puede programarse mediante el IDE de Arduino.
El Devkit cuenta con 6 GPIOs y 6 entradas analógicas, que tambien pueden configurarse como entradas digitales, un botón y un led que pueden programarse. 
A lo largo de este proyecto, se presentaran algunos ejemplos para demostrar lo fácil que es incluir la conectividad Sigfox a cualquier proyecto.

## Pinout ##

En la siguiente imagen se muestra el pinout del Devkit, de manera que se puedan asociar las terminales de la tarjeta con las utilizadas en Arduino Uno.

![devkit_pinout](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/devkit_pinout.jpg?raw=true)

## Ejemplo 1 ##

En este ejemplo se utilizará el sketch devkit_info[Code](Ejemplos/devkit_info/devkit_info.ino) para leer el ID y el PAC de nuestro Devkit, los cuales son necesarios para registrar el dispositivo en la plataforma de Sigfox y poder ver los mensajes enviados en el backend.

